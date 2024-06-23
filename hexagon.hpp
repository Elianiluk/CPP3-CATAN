#pragma once
#include <vector>
#include <string>
#include "vertex.hpp"
#include "edge.hpp"

namespace ariel {
    class Hexagon {
    private:
        int num;
        int numOrder;
        std::string name;
        std::vector<Vertex*> vertices;
        std::vector<Edge*> edges;

    public:
        Hexagon(int num,int numOrder, const std::string& name);
        void setVertices(Vertex* v1, Vertex* v2, Vertex* v3, Vertex* v4, Vertex* v5, Vertex* v6);
        void setEdges(Edge* e1, Edge* e2, Edge* e3, Edge* e4, Edge* e5, Edge* e6);
        Vertex* getVertex(int index) const;
        Edge* getEdge(int index) const;
        int getNum() const;
        std::string getName() const;
        std::string getType();
        // std::string getLandSymbol() const;
    };
}
