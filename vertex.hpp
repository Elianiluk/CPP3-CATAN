#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <vector>

namespace ariel {
    class Edge;  // Forward declaration

    class Vertex {
    private:
        int num;
        int playerID;
        bool settelment;
        bool city;
        std::vector<Vertex*> neighbors;
        std::vector<Edge*> incidentEdges;
        std::vector<int> hexagons;

    public:
        Vertex(int num);

        int getNum() const;
        void addNeighbors(Vertex* neighbor1, Vertex* neighbor2, Vertex* neighbor3);
        void addIncidentEdges(Edge* edge1, Edge* edge2, Edge* edge3);
        bool hasSettlement() const;
        void setSettlement();
        void addHexagon(int hexID);
        std::vector<int> getHexagons() const;
    };
}

#endif // VERTEX_HPP
