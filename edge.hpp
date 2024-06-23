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
        int playerID;

    public:
        Edge(int num);

        int getNum() const;
        void setVertices(Vertex* v1, Vertex* v2);
        void setNeighbors(Edge* neighbor1, Edge* neighbor2, Edge* neighbor3, Edge* neighbor4);
        void addAdjEdges(Edge* edge1, Edge* edge2, Edge* edge3, Edge* edge4);
        bool hasRoad();
        void setRoad(int playerID);
        void addHexagon(int hexID);
        std::vector<int> getHexagons() const;
        std::vector<Edge*> getNeighbors() const;
        int getPlayerID() const;
    };
}

#endif // EDGE_HPP
