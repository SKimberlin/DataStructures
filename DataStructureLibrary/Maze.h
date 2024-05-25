#pragma once
#include "Graph.h"

template<typename T>
class Maze
{
public:
    Maze(Graph<T>& graph, T start, T end) : graph(graph), start(start), end(end) {}

    /*
    * @brief Solves the maze by finding the shortest distance
    * @brief This method has a time complexity of O(n^2) because it's calling GetShortestPath
    * @return A vector of values describing the path and the sum of distance between the start and end
    */
    std::tuple<std::vector<T>, size_t> SolveMaze()
    {
        return graph.GetShortestPath(start, end);
    }

private:
    Graph<T>& graph;
    T start;
    T end;
};
