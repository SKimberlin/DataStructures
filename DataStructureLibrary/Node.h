#pragma once
#include <vector>
#include <limits>
#include "Edge.h"

template<typename T>
class Node {
public:
    Node(const T& value) : value(value), distance(std::numeric_limits<size_t>::max()) {}

    void AddEdge(Node<T>* node, size_t weight) {
        edges.push_back(new Edge<T>(node, weight));
    }

    T value;
    std::vector<Edge<T>*> edges;
    Node<T>* prev = nullptr;
    size_t distance;

    /*
    * @brief Sets the previous node and distance
    * @brief O(1)
    * @param Node and weight
    */
    void SetPrevious(Node<T>* node, size_t edgeWeight) {
        prev = node;
        distance = node->distance + edgeWeight;
    }
};
