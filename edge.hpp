#ifndef EDGE_HPP
#define EDGE_HPP

#include "vertex.hpp"
#include <vector>

namespace ariel {
    class Edge {
    private:
        int num;
        Vertex* vertex1;
        Vertex* vertex2;
        std::vector<Edge*> neighbors;
        bool road;
        std::vector<int> hexagons;

    public:
        Edge(int num);

        int getNum() const;
        void setVertices(Vertex* v1, Vertex* v2);
        void setNeighbors(Edge* neighbor1, Edge* neighbor2, Edge* neighbor3, Edge* neighbor4);
        void addAdjEdges(Edge* edge1, Edge* edge2, Edge* edge3, Edge* edge4);
        bool hasRoad();
        void setRoad();
        void addHexagon(int hexID);
        std::vector<int> getHexagons() const;
        std::vector<Edge*> getNeighbors() const;
    };
}

#endif // EDGE_HPP
