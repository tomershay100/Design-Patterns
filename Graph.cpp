#include <cstddef>
#include <algorithm>

//
// Created by tomer on 18-Feb-21.
//
class Graph {
    size_t vs{};
    bool **adjMat{};

    void clear() {
        if (adjMat != nullptr) {
            for (int i = 0; i < vs; ++i) {
                delete[] adjMat[i];
            }
            delete[] adjMat;
        }
    }

public:
    Graph(size_t vs) {
        adjMat = new bool *[vs];
        for (int i = 0; i < vs; ++i) {
            adjMat[i] = new bool[vs];
            for (int j = 0; j < vs; ++j)
                adjMat[i][j] = false;
        }
    }

    Graph(const Graph &g) {
        vs = g.vs;
        adjMat = new bool *[vs];
        for (int i = 0; i < vs; ++i) {
            adjMat[i] = new bool[vs];
            for (int j = 0; j < vs; ++j)
                adjMat[i][j] = g.adjMat[i][j];
        }
    }

    ~Graph() {
        this->clear();
        vs = 0;
    }

    /*Graph(Graph &&g) {
        vs = g.vs;
        adjMat = g.adjMat;
        g.vs = 0;
        g.adjMat = nullptr;
    }

    Graph &operator=(Graph &&g) {
        *this = std::move(g);
        return *this;
    }*/

    Graph(Graph &&g) {
        *this = std::move(g);
    }

    Graph &operator=(Graph &&g) {
        vs = g.vs;
        adjMat = g.adjMat;
        g.vs = 0;
        g.adjMat = nullptr;
        return *this;
    }

    Graph &operator=(const Graph &g) {
        if (this != &g) {
            delete this;
            *this = Graph(g);
        }
        return *this;
    }
};
