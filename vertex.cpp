#include "vertex.hpp"

namespace ariel
{
    Vertex::Vertex(int num) : num(num), playerID(-1), settelment(false), city(false), neighbors(3, nullptr), incidentEdges(3, nullptr) {}

    int Vertex::getNum() const
    {
        return num;
    }

    void Vertex::addNeighbors(Vertex *neighbor1, Vertex *neighbor2, Vertex *neighbor3)
    {
        if (neighbor1 != nullptr)
            neighbors[0] = neighbor1;
        if (neighbor2 != nullptr)
            neighbors[1] = neighbor2;
        if (neighbor3 != nullptr)
            neighbors[2] = neighbor3;
    }

    void Vertex::addIncidentEdges(Edge *edge1, Edge *edge2, Edge *edge3)
    {
        incidentEdges[0] = edge1;
        incidentEdges[1] = edge2;
        incidentEdges[2] = edge3;
    }

    bool Vertex::hasSettlement() const
    {
        return settelment;
    }

    void Vertex::setSettlement(int playerID)
    {
        settelment = true;
        this->playerID = playerID;
    }

    void Vertex::addHexagon(int hexID)
    {
        hexagons.push_back(hexID);
    }

    std::vector<int> Vertex::getHexagons() const
    {
        return hexagons;
    }

    std::vector<Vertex *> Vertex::getNeighbors() const
    {
        return neighbors;
    }

    bool Vertex::hasCity() const
    {
        return city;
    }

    void Vertex::setCity()
    {
        city = true;
        settelment = false;
    }

    std::string Vertex::getVertexKind() const
    {
        if (playerID == -1)
            return "O";
        std::string symbol;
        if (playerID == 0)
            symbol += "\033[1;31m";
        if (playerID == 1)
            symbol += "\033[1;34m";
        if (playerID == 2)
            symbol += "\033[1;32m";
        if (city)
            symbol += "C";
        else if (settelment)
            symbol += "S";
        return symbol;
    }

    int Vertex::getPlayerID() const
    {
        return playerID;
    }
}
