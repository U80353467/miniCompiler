#include "graph.hpp"
#include <unordered_set>

namespace graph {
    bool isNameSpecial(std::string name) {
        return name[0] != '_';
    }

    Graph::Graph() = default;

    Graph::Graph(int colors) {
        this->colors = colors;
    }

    void Graph::addEdge(std::string u, std::string v) {
        if (nodes.find(u) == nodes.end()) {
            createNode(u);
        }
        if (nodes.find(v) == nodes.end()) {
            createNode(v);
        }
        if (nodes[u]->adj.find(nodes[v]) != nodes[u]->adj.end()) {
            return;
        }
        nodes[u]->adj.insert(nodes[v]);
        nodes[v]->adj.insert(nodes[u]);
        nodes[u]->degree++;
        nodes[v]->degree++;
    }

    void Graph::createNode(std::string u) {
        if (nodes.find(u) != nodes.end()) {
            return;
        }
        Node* newNode = new Node();
        newNode->name = u;
        newNode->degree = 0;
        newNode->special = isNameSpecial(u);
        if (newNode->special) {
            // std::cout << "Special: " << u << std::endl;
            newNode->color = std::stoi(u.substr(1)) + 18;
        }
        nodes[u] = newNode;
        degree_pq.push(newNode);
        spill_pq.push(newNode);
    }

    void Graph::removeNode(Node* u) {
        u->markRemoved = true;
        for (Node* v : u->adj) {
            if (!v->markRemoved) {
                v->degree--;
                u->degree--;
            }
        }
    }

    void Graph::rebuildNode(Node* u) {
        u->markRemoved = false;
        for (Node* v : u->adj) {
            if (v->markRemoved) {
                v->degree++;
                u->degree++;
            }
        }
    }

    bool Graph::colorNode(Node* u) {
        std::unordered_set<int> usedColors;
        for (Node* v : u->adj) {
            if (!v->markRemoved) {
                usedColors.insert(v->color);
            }
        }
        for (int i = 0; i < colors; i++) {
            if (usedColors.find(i) == usedColors.end()) {
                u->color = i;
                return true;
            }
        }
        u->color = -1;
        return false;
    }

    void Graph::colorGraph() {
        while (!degree_pq.empty()) {
            Node* u = degree_pq.top();
            while (u->markRemoved || u->special) {
                degree_pq.pop();
                if (degree_pq.empty()) {
                    break;
                }
                u = degree_pq.top();
            }
            if (degree_pq.empty()) {
                break;
            }
            if (u->degree < colors) {
                degree_pq.pop();
                removedNodes.push(u);
                removeNode(u);
            } else {
                Node* v = spill_pq.top();
                while (v->markRemoved || v->special) {
                    spill_pq.pop();
                    if (spill_pq.empty()) {
                        break;
                    }
                    v = spill_pq.top();
                }
                if (spill_pq.empty()) {
                    break;
                }
                spill_pq.pop();
                removedNodes.push(v);
                removeNode(v);
            }
        }
        while (!removedNodes.empty()) {
            Node* u = removedNodes.top();
            removedNodes.pop();
            rebuildNode(u);
            if (!colorNode(u)) {
                spills.insert(u->name);
            }
        }
    }

    void Graph::clearGraph() {
        while (!degree_pq.empty()) {
            degree_pq.pop();
        }
        while (!spill_pq.empty()) {
            spill_pq.pop();
        }
        while (!removedNodes.empty()) {
            removedNodes.pop();
        }
        spills.clear();
        for (auto& node : nodes) {
            delete node.second;
        }
        nodes.clear();
    }
}