#include "edge.hpp"

namespace ariel {
    Edge::Edge(int num) : num(num), vertex1(nullptr), vertex2(nullptr), neighbors(4, nullptr),road(false),hexagons({}) {}

    int Edge::getNum() const {
        return num;
    }

    void Edge::setVertices(Vertex* v1, Vertex* v2) {
        vertex1 = v1;
        vertex2 = v2;
    }

    void Edge::setNeighbors(Edge* neighbor1, Edge* neighbor2, Edge* neighbor3, Edge* neighbor4) {
        neighbors[0] = neighbor1;
        neighbors[1] = neighbor2;
        neighbors[2] = neighbor3;
        neighbors[3] = neighbor4;
    }

    void Edge::addAdjEdges(Edge* edge1, Edge* edge2, Edge* edge3, Edge* edge4) {
        neighbors[0] = edge1;
        neighbors[1] = edge2;
        neighbors[2] = edge3;
        neighbors[3] = edge4;
    }

    bool Edge::hasRoad() {
        return road;
    }

    void Edge::setRoad() {
        road = true;
    }

    void Edge::addHexagon(int hexID) {
        hexagons.push_back(hexID);
    }

    std::vector<int> Edge::getHexagons() const {
        return hexagons;
    }

    std::vector<Edge*> Edge::getNeighbors() const {
        return neighbors;
    }
}
