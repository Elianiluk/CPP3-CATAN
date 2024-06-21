#include "vertex.hpp"

namespace ariel {
    Vertex::Vertex(int num) : num(num), neighbors(3, nullptr), incidentEdges(3, nullptr) {}

    int Vertex::getNum() const {
        return num;
    }

    void Vertex::addNeighbors(Vertex* neighbor1, Vertex* neighbor2, Vertex* neighbor3) {
        neighbors[0] = neighbor1;
        neighbors[1] = neighbor2;
        neighbors[2] = neighbor3;
    }

    void Vertex::addIncidentEdges(Edge* edge1, Edge* edge2, Edge* edge3) {
        incidentEdges[0] = edge1;
        incidentEdges[1] = edge2;
        incidentEdges[2] = edge3;
    }
}
