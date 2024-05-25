#pragma once
template<typename T>
class Node;

template<typename T>
class Edge {
public:
    Edge(Node<T>* node, size_t weight) : node(node), weight(weight) {}

    size_t weight;
    Node<T>* node;
};
