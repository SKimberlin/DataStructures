#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <istream>
#include <queue>
#include <map>
#include <tuple>
#include <initializer_list>
#include "Node.h"

template<typename T>
class Graph {
public:
    Graph(std::initializer_list<T> nodeValues) {
        for (const T& value : nodeValues) {
            AddNode(value);
        }
    }

    /*
    * @brief Adds the edges to the given node value
    * @brief This has a time complexity of O(n^2) because for every edge it must call GetNode which has a complexity of O(n)
    * @param The value to add the edges to and the edges themselves
    */
    void AddNodeEdges(const T& edgeNodeValue, const std::map<T, size_t>& edges) {
        Node<T>* beginningNode = GetNode(edgeNodeValue);
        if (!beginningNode) return;

        for (const auto& edge : edges) {
            Node<T>* endNode = GetNode(edge.first);
            beginningNode->AddEdge(endNode, edge.second);
        }
    }

    /*
    * @brief Adds a node of the value to a vector if that value has not been used before
    * @brief This has a time complexity of O(n) because it calls GetNode
    * @param Value to add
    */
    void AddNode(const T& value) {
        if (GetNode(value)) return;
        Node<T>* newNode = new Node<T>(value);
        nodes.push_back(newNode);
    }

    /*
    * @brief Gets the shortest path between two node
    * @brief This method has a time complexity of O(n^2) because it's greatest amount of operations is carried over from the Dijkstra
    * @param The start and end values
    * @return A vector of values describing the path and the sum of distance between the start and end
    */
    std::tuple<std::vector<T>, size_t> GetShortestPath(T startValue, T endValue)
    {
        Node<T>* startNode = GetNode(startValue);
        Node<T>* endNode = GetNode(endValue);
        std::vector<T> path;

        if (startNode == endNode)
        {
            path.push_back(endNode->value);
            return { path, 0 };
        }

        Dijkstra(startNode, endNode);
        size_t totalDistance = endNode->distance;

        Node<T>* currentNode = endNode;
        if (endNode->prev)
        {
            while (currentNode) {
                path.push_back(currentNode->value);
                currentNode = currentNode->prev;
            }
            std::reverse(path.begin(), path.end());
        }

        return { path, totalDistance };
    }

    /*
    std::tuple<size_t, std::vector<size_t, T>> Prims()
    {
        size_t totalDistance = 0;
        Node<T>* node = nodes.front();
        std::priority_queue<std::pair<size_t, Node<T>*>, std::vector<std::pair<size_t, Node<T>*>>, CompareNode> queue;
        queue.push({ 0, node });
        std::vector<std::pair<size_t, T>> list;

        while (!queue.empty())
        {
            Node<T>* currentNode = queue.top().second;
            size_t currentWeight = queue.top().first;
            queue.pop();
            if (!SecondValueInVector(list, currentNode))
            {
                list.push_back({ currentWeight, currentNode->value });
                for (Edge<T>* edge : currentNode)
                {
                    queue.push({ edge->weight, edge->node });
                }
            }
        }

        for (auto& pair : list)
        {
            totalDistance += pair.first;
        }

        return { totalDistance, list };

    }
    */
private:

    /*
    * @brief the operator used to compare nodes in the priority queue
    */
    struct CompareNode {
        bool operator()(std::pair<size_t, Node<T>*> n1, std::pair<size_t, Node<T>*> n2) {
            return n1.first > n2.first;
        }
    };
    
    /*
    * @brief Use the greedy algorithm to find the fastest path from one node to another
    * @brief This has a time complexity of O(n ^ 2) since in the worst case it has to go through every node which may be linked to every node
    * @param The start and ending node
    */ 
    void Dijkstra(Node<T>* startNode, Node<T>* endNode) {
        std::priority_queue<std::pair<size_t, Node<T>*>, std::vector<std::pair<size_t, Node<T>*>>, CompareNode> queue;
        startNode->distance = 0;
        queue.push({ 0, startNode });

        // you have to look through every node (n)
        while (!queue.empty()) {
            size_t currentDistance = queue.top().first;
            Node<T>* currentNode = queue.top().second;
            queue.pop();

            if (currentDistance > currentNode->distance) {
                continue;
            }

            // worst case every node is attached to the node (n)
            for (Edge<T>* edge : currentNode->edges) {
                size_t newDist = currentNode->distance + edge->weight;
                if (newDist < edge->node->distance) {
                    edge->node->SetPrevious(currentNode, edge->weight);
                    queue.push({ newDist, edge->node });
                }
            }
        }
    }

    /*
    * @brief finds and returns node of value
    * @brief This has a time complexity of o(n) because it may need to go through every node
    * @param the value of the node
    * @return the node of the value
    */
    Node<T>* GetNode(const T& value) {
        for (Node<T>* node : nodes) {
            if (node->value == value) return node;
        }
        return nullptr;
    }

    bool SecondValueInVector(std::pair<size_t, T> vec, T value)
    {
        for (auto& pair : vec)
        {
            if (pair.second == value) return true;
        }
        return false;
    }

    std::vector<Node<T>*> nodes;

    
};
