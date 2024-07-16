#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <queue>

namespace graph {
    struct Node {
        std::string name;
        bool special;
        int degree;
        std::unordered_set<Node*> adj;
        bool markRemoved = false;
        int color = -1;
    };

    struct CompareNodePointerByDegree {
        bool operator()(Node* const& a, Node* const& b) {
            return a->degree < b->degree;
        }
    };

    struct CompareNodePointerBySpill {
        bool operator()(Node* const& a, Node* const& b) {
            return a->degree > b->degree;
        }
    };

    class Graph {
    public:
        Graph();
        Graph(int colors);
        void addEdge(std::string u, std::string v);
        void createNode(std::string u);
        void rebuildNode(Node* u);
        void removeNode(Node* u);
        bool colorNode(Node* u);
        void colorGraph();
        void clearGraph();
        std::unordered_set<std::string> spills;
        std::unordered_map<std::string, Node*> nodes;
    private:
        std::stack<Node*> removedNodes;
        std::priority_queue<Node*, std::vector<Node*>, CompareNodePointerByDegree> degree_pq;
        std::priority_queue<Node*, std::vector<Node*>, CompareNodePointerBySpill> spill_pq;
        int colors;
    };
}