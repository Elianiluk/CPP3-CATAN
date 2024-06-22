#include "hexagon.hpp"

namespace ariel {
    Hexagon::Hexagon(int num,int numOrder, const std::string& name) : num(num),numOrder(numOrder), name(name), vertices(6, nullptr), edges(6, nullptr) {}

    void Hexagon::setVertices(Vertex* v1, Vertex* v2, Vertex* v3, Vertex* v4, Vertex* v5, Vertex* v6) {
        vertices[0] = v1;
        vertices[1] = v2;
        vertices[2] = v3;
        vertices[3] = v4;
        vertices[4] = v5;
        vertices[5] = v6;

        v1->addHexagon(numOrder);
        v2->addHexagon(numOrder);
        v3->addHexagon(numOrder);
        v4->addHexagon(numOrder);
        v5->addHexagon(numOrder);
        v6->addHexagon(numOrder);
    }

    void Hexagon::setEdges(Edge* e1, Edge* e2, Edge* e3, Edge* e4, Edge* e5, Edge* e6) {
        edges[0] = e1;
        edges[1] = e2;
        edges[2] = e3;
        edges[3] = e4;
        edges[4] = e5;
        edges[5] = e6;

        e1->addHexagon(numOrder);
        e2->addHexagon(numOrder);
        e3->addHexagon(numOrder);
        e4->addHexagon(numOrder);
        e5->addHexagon(numOrder);
        e6->addHexagon(numOrder);
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

    std::string Hexagon::getName() const {
        return name;
    }

    std::string Hexagon::getType() {
        if (name == "Mountains") {
            return "ore";
        }
        else if (name == "Forest") {
            return "wood";
        }
        else if (name == "Agricultural Land") {
            return "wheat";
        }
        else if (name == "Pasture Land") {
            return "wool";
        }
        else if (name == "Hills") {
            return "brick";
        }
        else {
            return "-1";
        }
    }
}
