#include "hexagon.hpp"

namespace ariel {
    Hexagon::Hexagon(int num, const std::string& name) : num(num), name(name), vertices(6, nullptr), edges(6, nullptr) {}

    void Hexagon::setVertices(Vertex* v1, Vertex* v2, Vertex* v3, Vertex* v4, Vertex* v5, Vertex* v6) {
        vertices[0] = v1;
        vertices[1] = v2;
        vertices[2] = v3;
        vertices[3] = v4;
        vertices[4] = v5;
        vertices[5] = v6;
    }

    void Hexagon::setEdges(Edge* e1, Edge* e2, Edge* e3, Edge* e4, Edge* e5, Edge* e6) {
        edges[0] = e1;
        edges[1] = e2;
        edges[2] = e3;
        edges[3] = e4;
        edges[4] = e5;
        edges[5] = e6;
    }

    Vertex* Hexagon::getVertex(int index) const {
        return vertices[index];
    }

    Edge* Hexagon::getEdge(int index) const {
        return edges[index];
    }

    int Hexagon::getNum() const {
        return num;
    }
}
