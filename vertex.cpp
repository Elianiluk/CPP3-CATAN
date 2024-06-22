#include "vertex.hpp"

namespace ariel {
    Vertex::Vertex(int num) : num(num),playerID(-1),settelment(false),city(false), neighbors(3, nullptr), incidentEdges(3, nullptr) {}

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

    bool Vertex::hasSettlement() const {
        return settelment;
    }

    void Vertex::setSettlement() {
        settelment = true;
    }

    void Vertex::addHexagon(int hexID) {
        hexagons.push_back(hexID);
    }

    std::vector<int> Vertex::getHexagons() const {
        return hexagons;
    }
}
