#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <vector>

namespace ariel {
    class Edge;  // Forward declaration

    class Vertex {
    private:
        int num;
        std::vector<Vertex*> neighbors;
        std::vector<Edge*> incidentEdges;

    public:
        Vertex(int num);

        int getNum() const;
        void addNeighbors(Vertex* neighbor1, Vertex* neighbor2, Vertex* neighbor3);
        void addIncidentEdges(Edge* edge1, Edge* edge2, Edge* edge3);
    };
}

#endif // VERTEX_HPP
