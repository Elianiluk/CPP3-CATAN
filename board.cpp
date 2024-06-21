#include "board.hpp"

namespace ariel {
    Board::Board() : board(19, nullptr) {}

    void Board::createBoard() {

        //create the vertices
        // first row
        board[0] = new Hexagon(10, "Mountains");
        board[0]->setVertices(new Vertex(0), new Vertex(1), new Vertex(2), new Vertex(3), new Vertex(4), new Vertex(5));

        board[1] = new Hexagon(2, "Pasture land");
        board[1]->setVertices(new Vertex(6), board[0]->getVertex(5), board[0]->getVertex(4), new Vertex(7), new Vertex(8), new Vertex(9));

        board[2] = new Hexagon(9, "Forest");
        board[2]->setVertices(new Vertex(10), board[1]->getVertex(5), board[1]->getVertex(4), new Vertex(11), new Vertex(12), new Vertex(13));

        // second row
        board[3] = new Hexagon(12, "Agricultural land");
        board[3]->setVertices(board[0]->getVertex(2), new Vertex(14), new Vertex(15), new Vertex(16), new Vertex(17), board[0]->getVertex(3));

        board[4] = new Hexagon(6, "Hills");
        board[4]->setVertices(board[1]->getVertex(2), board[3]->getVertex(5), board[3]->getVertex(4), new Vertex(18), new Vertex(19), board[1]->getVertex(3));

        board[5] = new Hexagon(4, "Pasture land");
        board[5]->setVertices(board[2]->getVertex(2), board[4]->getVertex(5), board[4]->getVertex(4), new Vertex(20), new Vertex(21), board[2]->getVertex(3));

        board[6] = new Hexagon(10, "Hills");
        board[6]->setVertices(board[2]->getVertex(4), board[5]->getVertex(5), board[5]->getVertex(4), new Vertex(22), new Vertex(23), new Vertex(24));

        // third row
        board[7] = new Hexagon(9, "Agricultural land");
        board[7]->setVertices(board[3]->getVertex(2), new Vertex(25), new Vertex(26), new Vertex(27), new Vertex(28), board[3]->getVertex(3));

        board[8] = new Hexagon(11, "Forest");
        board[8]->setVertices(board[4]->getVertex(2), board[7]->getVertex(5), board[7]->getVertex(4), new Vertex(29), new Vertex(30), board[4]->getVertex(3));

        board[9] = new Hexagon(-1, "Desert");
        board[9]->setVertices(board[5]->getVertex(2), board[8]->getVertex(5), board[8]->getVertex(4), new Vertex(31), new Vertex(32), board[5]->getVertex(3));

        board[10] = new Hexagon(3, "Forest");
        board[10]->setVertices(board[6]->getVertex(2), board[9]->getVertex(5), board[9]->getVertex(4), new Vertex(33), new Vertex(34), board[6]->getVertex(3));

        board[11] = new Hexagon(8, "Mountains");
        board[11]->setVertices(board[6]->getVertex(4), board[10]->getVertex(5), board[10]->getVertex(4), new Vertex(35), new Vertex(36), new Vertex(37));

        // fourth row
        board[12] = new Hexagon(8, "Forest");
        board[12]->setVertices(board[7]->getVertex(4), board[7]->getVertex(3), new Vertex(38), new Vertex(39), new Vertex(40), board[8]->getVertex(3));

        board[13] = new Hexagon(3, "Mountains");
        board[13]->setVertices(board[8]->getVertex(4), board[12]->getVertex(5), board[12]->getVertex(4), new Vertex(41), new Vertex(42), board[9]->getVertex(3));

        board[14] = new Hexagon(4, "Agricultural land");
        board[14]->setVertices(board[9]->getVertex(4), board[13]->getVertex(5), board[13]->getVertex(4), new Vertex(43), new Vertex(44), board[10]->getVertex(3));

        board[15] = new Hexagon(5, "Pasture land");
        board[15]->setVertices(board[10]->getVertex(4), board[14]->getVertex(5), board[14]->getVertex(4), new Vertex(45), new Vertex(46), board[11]->getVertex(3));

        // fifth row
        board[16] = new Hexagon(5, "Hills");
        board[16]->setVertices(board[12]->getVertex(4), board[12]->getVertex(3), new Vertex(47), new Vertex(48), new Vertex(49), board[13]->getVertex(3));

        board[17] = new Hexagon(6, "Agricultural land");
        board[17]->setVertices(board[13]->getVertex(4), board[16]->getVertex(5), board[16]->getVertex(4), new Vertex(50), new Vertex(51), board[14]->getVertex(3));

        board[18] = new Hexagon(11, "Pasture land");
        board[18]->setVertices(board[14]->getVertex(4), board[17]->getVertex(5), board[17]->getVertex(4), new Vertex(52), new Vertex(53), board[15]->getVertex(3));

        // set edges for each land
        // first row
        this->board[0]->setEdges(new Edge(0), new Edge(1), new Edge(2), new Edge(3), new Edge(4), new Edge(5));
        this->board[1]->setEdges(new Edge(6), this->board[0]->getEdge(4), new Edge(7), new Edge(8), new Edge(9), new Edge(10));
        this->board[2]->setEdges(new Edge(11), this->board[1]->getEdge(4), new Edge(12), new Edge(13), new Edge(14), new Edge(15));

        // second row
        this->board[3]->setEdges(new Edge(16), new Edge(17), new Edge(18), new Edge(19), new Edge(20), this->board[0]->getEdge(2));
        this->board[4]->setEdges(this->board[0]->getEdge(3), this->board[3]->getEdge(4), new Edge(21), new Edge(22), new Edge(23), this->board[1]->getEdge(2));
        this->board[5]->setEdges(this->board[1]->getEdge(3), this->board[4]->getEdge(4), new Edge(24), new Edge(25), new Edge(26), this->board[2]->getEdge(2));
        this->board[6]->setEdges(this->board[2]->getEdge(3), this->board[5]->getEdge(4), new Edge(27), new Edge(28), new Edge(29), new Edge(30));

        // third row
        this->board[7]->setEdges(new Edge(31), new Edge(32), new Edge(33), new Edge(34), new Edge(35), this->board[3]->getEdge(2));
        this->board[8]->setEdges(this->board[3]->getEdge(3), this->board[7]->getEdge(4), new Edge(36), new Edge(37), new Edge(38), this->board[4]->getEdge(2));
        this->board[9]->setEdges(this->board[4]->getEdge(3), this->board[8]->getEdge(4), new Edge(39), new Edge(40), new Edge(41), this->board[5]->getEdge(2));
        this->board[10]->setEdges(this->board[5]->getEdge(3), this->board[9]->getEdge(4), new Edge(42), new Edge(43), new Edge(44), this->board[6]->getEdge(2));
        this->board[11]->setEdges(this->board[6]->getEdge(3), this->board[10]->getEdge(4), new Edge(45), new Edge(46), new Edge(47), new Edge(48));

        // fourth row
        this->board[12]->setEdges(this->board[7]->getEdge(3), new Edge(49), new Edge(50), new Edge(51), new Edge(52), this->board[8]->getEdge(2));
        this->board[13]->setEdges(this->board[8]->getEdge(3), this->board[12]->getEdge(4), new Edge(53), new Edge(54), new Edge(55), this->board[9]->getEdge(2));
        this->board[14]->setEdges(this->board[9]->getEdge(3), this->board[13]->getEdge(4), new Edge(56), new Edge(57), new Edge(58), this->board[10]->getEdge(2));
        this->board[15]->setEdges(this->board[10]->getEdge(3), this->board[14]->getEdge(4), new Edge(59), new Edge(60), new Edge(61), this->board[11]->getEdge(2));

        // fifth row
        this->board[16]->setEdges(this->board[12]->getEdge(3), new Edge(62), new Edge(63), new Edge(64), new Edge(65), this->board[13]->getEdge(2));
        this->board[17]->setEdges(this->board[13]->getEdge(3), this->board[16]->getEdge(4), new Edge(66), new Edge(67), new Edge(68), this->board[14]->getEdge(2));
        this->board[18]->setEdges(this->board[14]->getEdge(3), this->board[17]->getEdge(4), new Edge(69), new Edge(70), new Edge(71), this->board[15]->getEdge(2));


        // set neighbors for each vertex and edge
        // first row
                // vertices
        this->board[0]->getVertex(0)->addNeighbors(this->board[0]->getVertex(1), this->board[0]->getVertex(5), nullptr);
        this->board[0]->getVertex(1)->addNeighbors(this->board[0]->getVertex(2), this->board[0]->getVertex(0), nullptr);
        this->board[0]->getVertex(2)->addNeighbors(this->board[0]->getVertex(1),  this->board[3]->getVertex(1), this->board[0]->getVertex(3));
        this->board[0]->getVertex(3)->addNeighbors(this->board[0]->getVertex(2),  this->board[3]->getVertex(4), this->board[0]->getVertex(4));
        this->board[0]->getVertex(4)->addNeighbors(this->board[0]->getVertex(5), this->board[0]->getVertex(3), this->board[4]->getVertex(5));
        this->board[0]->getVertex(5)->addNeighbors(this->board[0]->getVertex(0), this->board[0]->getVertex(4), this->board[1]->getVertex(0));
                // edges
        this->board[0]->getVertex(0)->addIncidentEdges(this->board[0]->getEdge(0), this->board[0]->getEdge(5), nullptr);
        this->board[0]->getVertex(1)->addIncidentEdges(this->board[0]->getEdge(1), this->board[0]->getEdge(0), nullptr);
        this->board[0]->getVertex(2)->addIncidentEdges(this->board[0]->getEdge(1), this->board[3]->getEdge(0), this->board[0]->getEdge(2));
        this->board[0]->getVertex(3)->addIncidentEdges(this->board[0]->getEdge(2), this->board[3]->getEdge(4), this->board[0]->getEdge(3));
        this->board[0]->getVertex(4)->addIncidentEdges(this->board[0]->getEdge(4), this->board[0]->getEdge(3), this->board[4]->getEdge(5));
        this->board[0]->getVertex(5)->addIncidentEdges(this->board[0]->getEdge(5), this->board[0]->getEdge(4), this->board[1]->getEdge(0));
            // LandEdges
                // vertices
        this->board[0]->getEdge(0)->setVertices(this->board[0]->getVertex(0), this->board[0]->getVertex(1));
        this->board[0]->getEdge(1)->setVertices(this->board[0]->getVertex(1), this->board[0]->getVertex(2));
        this->board[0]->getEdge(2)->setVertices(this->board[0]->getVertex(2), this->board[0]->getVertex(3));
        this->board[0]->getEdge(3)->setVertices(this->board[0]->getVertex(3), this->board[0]->getVertex(4));
        this->board[0]->getEdge(4)->setVertices(this->board[0]->getVertex(4), this->board[0]->getVertex(5));
        this->board[0]->getEdge(5)->setVertices(this->board[0]->getVertex(5), this->board[0]->getVertex(0));
                // edges
        this->board[0]->getEdge(0)->addAdjEdges(this->board[0]->getEdge(1), this->board[0]->getEdge(5), nullptr, nullptr);
        this->board[0]->getEdge(1)->addAdjEdges(this->board[3]->getEdge(0), this->board[0]->getEdge(2), this->board[0]->getEdge(0), nullptr);
        this->board[0]->getEdge(2)->addAdjEdges(this->board[0]->getEdge(1), this->board[3]->getEdge(0), this->board[3]->getEdge(4), this->board[0]->getEdge(3));
        this->board[0]->getEdge(3)->addAdjEdges(this->board[0]->getEdge(2), this->board[3]->getEdge(4), this->board[4]->getEdge(5), this->board[0]->getEdge(4));
        this->board[0]->getEdge(4)->addAdjEdges(this->board[0]->getEdge(5), this->board[0]->getEdge(3), this->board[1]->getEdge(2), this->board[1]->getEdge(0));
        this->board[0]->getEdge(5)->addAdjEdges(this->board[0]->getEdge(0), this->board[0]->getEdge(4), this->board[1]->getEdge(0), nullptr);

        // Land 1
        // LandVertices
            // vertices
        this->board[1]->getVertex(0)->addNeighbors(this->board[0]->getVertex(5), this->board[1]->getVertex(5), nullptr);
        this->board[1]->getVertex(3)->addNeighbors(this->board[0]->getVertex(4), this->board[4]->getVertex(4), this->board[1]->getVertex(4));
        this->board[1]->getVertex(4)->addNeighbors(this->board[1]->getVertex(5), this->board[1]->getVertex(3), this->board[5]->getVertex(5));
        this->board[1]->getVertex(5)->addNeighbors(this->board[1]->getVertex(0), this->board[1]->getVertex(4), this->board[2]->getVertex(0));
                // edges
        this->board[1]->getVertex(0)->addIncidentEdges(this->board[1]->getEdge(0), this->board[1]->getEdge(5), nullptr);
        this->board[1]->getVertex(3)->addIncidentEdges(this->board[1]->getEdge(2), this->board[4]->getEdge(4), this->board[1]->getEdge(3));
        this->board[1]->getVertex(4)->addIncidentEdges(this->board[1]->getEdge(4), this->board[1]->getEdge(3), this->board[5]->getEdge(5));
        this->board[1]->getVertex(5)->addIncidentEdges(this->board[1]->getEdge(5), this->board[1]->getEdge(4), this->board[2]->getEdge(0));
            // LandEdges
                // vertices
        this->board[1]->getEdge(0)->setVertices(this->board[1]->getVertex(0), this->board[0]->getVertex(5));
        this->board[1]->getEdge(2)->setVertices(this->board[0]->getVertex(4), this->board[1]->getVertex(3));
        this->board[1]->getEdge(3)->setVertices(this->board[1]->getVertex(3), this->board[1]->getVertex(4));
        this->board[1]->getEdge(4)->setVertices(this->board[1]->getVertex(4), this->board[1]->getVertex(5));
        this->board[1]->getEdge(5)->setVertices(this->board[1]->getVertex(5), this->board[1]->getVertex(0));
                // edges
        this->board[1]->getEdge(0)->addAdjEdges(this->board[0]->getEdge(5), this->board[0]->getEdge(4), this->board[1]->getEdge(5), nullptr);
        this->board[1]->getEdge(2)->addAdjEdges(this->board[0]->getEdge(4), this->board[0]->getEdge(3), this->board[4]->getEdge(4), this->board[1]->getEdge(3));
        this->board[1]->getEdge(3)->addAdjEdges(this->board[1]->getEdge(2), this->board[4]->getEdge(4), this->board[5]->getEdge(5), this->board[1]->getEdge(4));
        this->board[1]->getEdge(4)->addAdjEdges(this->board[1]->getEdge(5), this->board[1]->getEdge(3), this->board[5]->getEdge(5), this->board[2]->getEdge(0));
        this->board[1]->getEdge(5)->addAdjEdges(this->board[1]->getEdge(0), this->board[1]->getEdge(4), this->board[2]->getEdge(0), nullptr);

        // Land 2
            // LandVertices
                // vertices
        this->board[2]->getVertex(0)->addNeighbors(this->board[1]->getVertex(5), this->board[2]->getVertex(5), nullptr);
        this->board[2]->getVertex(3)->addNeighbors(this->board[1]->getVertex(4), this->board[5]->getVertex(4), this->board[2]->getVertex(4));
        this->board[2]->getVertex(4)->addNeighbors(this->board[2]->getVertex(5), this->board[2]->getVertex(3), this->board[6]->getVertex(5));
        this->board[2]->getVertex(5)->addNeighbors(this->board[2]->getVertex(0), this->board[2]->getVertex(4), nullptr);
                // edges
        this->board[2]->getVertex(0)->addIncidentEdges(this->board[2]->getEdge(0), this->board[2]->getEdge(5), nullptr);
        this->board[2]->getVertex(3)->addIncidentEdges(this->board[2]->getEdge(2), this->board[5]->getEdge(4), this->board[2]->getEdge(3));
        this->board[2]->getVertex(4)->addIncidentEdges(this->board[2]->getEdge(4), this->board[2]->getEdge(3), this->board[6]->getEdge(5));
        this->board[2]->getVertex(5)->addIncidentEdges(this->board[2]->getEdge(5), this->board[2]->getEdge(4), nullptr);
            // LandEdges
                // vertices
        this->board[2]->getEdge(0)->setVertices(this->board[2]->getVertex(0), this->board[1]->getVertex(5));
        this->board[2]->getEdge(2)->setVertices(this->board[1]->getVertex(4), this->board[2]->getVertex(3));
        this->board[2]->getEdge(3)->setVertices(this->board[2]->getVertex(3), this->board[2]->getVertex(4));
        this->board[2]->getEdge(4)->setVertices(this->board[2]->getVertex(4), this->board[2]->getVertex(5));
        this->board[2]->getEdge(5)->setVertices(this->board[2]->getVertex(5), this->board[2]->getVertex(0));
                // edges
        this->board[2]->getEdge(0)->addAdjEdges(this->board[1]->getEdge(5), this->board[1]->getEdge(4), this->board[2]->getEdge(5), nullptr);
        this->board[2]->getEdge(2)->addAdjEdges(this->board[1]->getEdge(4), this->board[1]->getEdge(3), this->board[5]->getEdge(4), this->board[2]->getEdge(3));
        this->board[2]->getEdge(3)->addAdjEdges(this->board[2]->getEdge(2), this->board[5]->getEdge(4), this->board[6]->getEdge(5), this->board[2]->getEdge(4));
        this->board[2]->getEdge(4)->addAdjEdges(this->board[2]->getEdge(5), this->board[2]->getEdge(3), this->board[6]->getEdge(5), nullptr);
        this->board[2]->getEdge(5)->addAdjEdges(this->board[2]->getEdge(0), this->board[2]->getEdge(4), nullptr, nullptr);

        // Land 3
            // LandVertices
                // vertices
        this->board[3]->getVertex(1)->addNeighbors(this->board[3]->getVertex(2), this->board[0]->getVertex(2), nullptr);
        this->board[3]->getVertex(2)->addNeighbors(this->board[3]->getVertex(1), this->board[7]->getVertex(1), this->board[3]->getVertex(3));
        this->board[3]->getVertex(3)->addNeighbors(this->board[3]->getVertex(2), this->board[7]->getVertex(4), this->board[3]->getVertex(4));
        this->board[3]->getVertex(4)->addNeighbors(this->board[0]->getVertex(3), this->board[3]->getVertex(3), this->board[4]->getVertex(3));
                // edges
        this->board[3]->getVertex(1)->addIncidentEdges(this->board[3]->getEdge(1), this->board[3]->getEdge(0), nullptr);   
        this->board[3]->getVertex(2)->addIncidentEdges(this->board[3]->getEdge(1), this->board[7]->getEdge(0), this->board[3]->getEdge(2)); 
        this->board[3]->getVertex(3)->addIncidentEdges(this->board[3]->getEdge(2), this->board[7]->getEdge(4), this->board[3]->getEdge(3));
        this->board[3]->getVertex(4)->addIncidentEdges(this->board[3]->getEdge(4), this->board[3]->getEdge(3), this->board[4]->getEdge(2));
            // LandEdges
                // vertices    
        this->board[3]->getEdge(0)->setVertices(this->board[0]->getVertex(2), this->board[3]->getVertex(1));
        this->board[3]->getEdge(1)->setVertices(this->board[3]->getVertex(1), this->board[3]->getVertex(2));
        this->board[3]->getEdge(2)->setVertices(this->board[3]->getVertex(2), this->board[3]->getVertex(3));
        this->board[3]->getEdge(3)->setVertices(this->board[3]->getVertex(3), this->board[3]->getVertex(4));
        this->board[3]->getEdge(4)->setVertices(this->board[3]->getVertex(4), this->board[0]->getVertex(3));
                // edges
        this->board[3]->getEdge(0)->addAdjEdges(this->board[0]->getEdge(1), this->board[3]->getEdge(1), this->board[0]->getEdge(2), nullptr);
        this->board[3]->getEdge(1)->addAdjEdges(this->board[7]->getEdge(0), this->board[3]->getEdge(2), this->board[3]->getEdge(0), nullptr);
        this->board[3]->getEdge(2)->addAdjEdges(this->board[3]->getEdge(1), this->board[7]->getEdge(0), this->board[7]->getEdge(4), this->board[3]->getEdge(3));
        this->board[3]->getEdge(3)->addAdjEdges(this->board[3]->getEdge(2), this->board[7]->getEdge(4), this->board[4]->getEdge(2), this->board[3]->getEdge(4));
        this->board[3]->getEdge(4)->addAdjEdges(this->board[0]->getEdge(2), this->board[3]->getEdge(3), this->board[4]->getEdge(2), this->board[0]->getEdge(3));

        // Land 4
            // LandVertices
                // vertices
        this->board[4]->getVertex(3)->addNeighbors(this->board[3]->getVertex(4), this->board[8]->getVertex(4), this->board[4]->getVertex(4));
        this->board[4]->getVertex(4)->addNeighbors(this->board[1]->getVertex(3), this->board[4]->getVertex(3), this->board[5]->getVertex(3));
                // edges
        this->board[4]->getVertex(3)->addIncidentEdges(this->board[4]->getEdge(2), this->board[8]->getEdge(4), this->board[4]->getEdge(3));
        this->board[4]->getVertex(4)->addIncidentEdges(this->board[4]->getEdge(4), this->board[4]->getEdge(3), this->board[5]->getEdge(2));
            
            // LandEdges
                // vertices
        this->board[4]->getEdge(2)->setVertices(this->board[3]->getVertex(4), this->board[4]->getVertex(3));
        this->board[4]->getEdge(3)->setVertices(this->board[4]->getVertex(3), this->board[4]->getVertex(4));
        this->board[4]->getEdge(4)->setVertices(this->board[4]->getVertex(4), this->board[4]->getVertex(5));
                // edges
        this->board[4]->getEdge(2)->addAdjEdges(this->board[3]->getEdge(4), this->board[3]->getEdge(3), this->board[8]->getEdge(4), this->board[4]->getEdge(3));
        this->board[4]->getEdge(3)->addAdjEdges(this->board[4]->getEdge(2), this->board[8]->getEdge(4), this->board[5]->getEdge(2), this->board[4]->getEdge(4));
        this->board[4]->getEdge(4)->addAdjEdges(this->board[1]->getEdge(2), this->board[4]->getEdge(3), this->board[5]->getEdge(2), this->board[1]->getEdge(3));

        // Land 5
            // LandVertices
                // vertices
        this->board[5]->getVertex(3)->addNeighbors(this->board[4]->getVertex(4), this->board[9]->getVertex(4), this->board[5]->getVertex(4));
        this->board[5]->getVertex(4)->addNeighbors(this->board[2]->getVertex(3), this->board[5]->getVertex(3), this->board[6]->getVertex(3));
                // edges
        this->board[5]->getVertex(3)->addIncidentEdges(this->board[5]->getEdge(2), this->board[9]->getEdge(4), this->board[5]->getEdge(3));
        this->board[5]->getVertex(4)->addIncidentEdges(this->board[5]->getEdge(4), this->board[5]->getEdge(3), this->board[6]->getEdge(2));

            // LandEdges
                // vertices
        this->board[5]->getEdge(2)->setVertices(this->board[5]->getVertex(2), this->board[5]->getVertex(3));
        this->board[5]->getEdge(3)->setVertices(this->board[5]->getVertex(3), this->board[5]->getVertex(4));
        this->board[5]->getEdge(4)->setVertices(this->board[5]->getVertex(4), this->board[5]->getVertex(5));
                // edges
        this->board[5]->getEdge(2)->addAdjEdges(this->board[4]->getEdge(4), this->board[4]->getEdge(3), this->board[9]->getEdge(4), this->board[5]->getEdge(3));
        this->board[5]->getEdge(3)->addAdjEdges(this->board[5]->getEdge(2), this->board[9]->getEdge(4), this->board[6]->getEdge(2), this->board[5]->getEdge(4));
        this->board[5]->getEdge(4)->addAdjEdges(this->board[2]->getEdge(2), this->board[5]->getEdge(3), this->board[6]->getEdge(2), this->board[2]->getEdge(3));
        
        // Land 6
            // LandVertices
                // vertices
        this->board[6]->getVertex(3)->addNeighbors(this->board[5]->getVertex(4), this->board[10]->getVertex(4), this->board[6]->getVertex(4));
        this->board[6]->getVertex(4)->addNeighbors(this->board[6]->getVertex(5), this->board[6]->getVertex(3), this->board[11]->getVertex(5));
        this->board[6]->getVertex(5)->addNeighbors(this->board[2]->getVertex(4), this->board[6]->getVertex(4), nullptr);
                // edges
        this->board[6]->getVertex(3)->addIncidentEdges(this->board[6]->getEdge(2), this->board[10]->getEdge(4), this->board[6]->getEdge(3));
        this->board[6]->getVertex(4)->addIncidentEdges(this->board[6]->getEdge(4), this->board[6]->getEdge(3), this->board[11]->getEdge(5));
        this->board[6]->getVertex(5)->addIncidentEdges(this->board[6]->getEdge(5), this->board[6]->getEdge(4), nullptr);
            
            // LandEdges
                // vertices
        this->board[6]->getEdge(2)->setVertices(this->board[6]->getVertex(2), this->board[6]->getVertex(3));
        this->board[6]->getEdge(3)->setVertices(this->board[6]->getVertex(3), this->board[6]->getVertex(4));
        this->board[6]->getEdge(4)->setVertices(this->board[6]->getVertex(4), this->board[6]->getVertex(5));
        this->board[6]->getEdge(5)->setVertices(this->board[6]->getVertex(5), this->board[6]->getVertex(0));
                // edges
        this->board[6]->getEdge(2)->addAdjEdges(this->board[5]->getEdge(4), this->board[5]->getEdge(3), this->board[10]->getEdge(4), this->board[6]->getEdge(3));
        this->board[6]->getEdge(3)->addAdjEdges(this->board[6]->getEdge(2), this->board[10]->getEdge(4), this->board[11]->getEdge(5), this->board[6]->getEdge(4));
        this->board[6]->getEdge(4)->addAdjEdges(this->board[6]->getEdge(5), this->board[6]->getEdge(3), this->board[11]->getEdge(5), nullptr);
        this->board[6]->getEdge(5)->addAdjEdges(this->board[2]->getEdge(4), this->board[2]->getEdge(3), this->board[6]->getEdge(4), nullptr);

        // Land 7
            // LandVertices
                // vertices
        this->board[7]->getVertex(1)->addNeighbors(this->board[7]->getVertex(2), this->board[3]->getVertex(2), nullptr);
        this->board[7]->getVertex(2)->addNeighbors(this->board[7]->getVertex(1), this->board[12]->getVertex(1), nullptr);
        this->board[7]->getVertex(3)->addNeighbors(this->board[7]->getVertex(2), this->board[12]->getVertex(2), this->board[7]->getVertex(4));
        this->board[7]->getVertex(4)->addNeighbors(this->board[3]->getVertex(3), this->board[7]->getVertex(3), this->board[8]->getVertex(3));
                // edges
        this->board[7]->getVertex(1)->addIncidentEdges(this->board[7]->getEdge(1), this->board[7]->getEdge(0), nullptr);
        this->board[7]->getVertex(2)->addIncidentEdges(this->board[7]->getEdge(1), this->board[7]->getEdge(2), nullptr);
        this->board[7]->getVertex(3)->addIncidentEdges(this->board[7]->getEdge(2), this->board[12]->getEdge(1), this->board[7]->getEdge(3));
        this->board[7]->getVertex(4)->addIncidentEdges(this->board[7]->getEdge(4), this->board[7]->getEdge(3), this->board[8]->getEdge(2));
            
            // LandEdges
                // vertices
        this->board[7]->getEdge(0)->setVertices(this->board[7]->getVertex(0), this->board[7]->getVertex(1));
        this->board[7]->getEdge(1)->setVertices(this->board[7]->getVertex(1), this->board[7]->getVertex(2));
        this->board[7]->getEdge(2)->setVertices(this->board[7]->getVertex(2), this->board[7]->getVertex(3));
        this->board[7]->getEdge(3)->setVertices(this->board[7]->getVertex(3), this->board[7]->getVertex(4));
        this->board[7]->getEdge(4)->setVertices(this->board[7]->getVertex(4), this->board[7]->getVertex(5));
                // edges
        this->board[7]->getEdge(0)->addAdjEdges(this->board[3]->getEdge(1), this->board[7]->getEdge(1), this->board[3]->getEdge(2), nullptr);
        this->board[7]->getEdge(1)->addAdjEdges(this->board[7]->getEdge(2), this->board[7]->getEdge(0), nullptr, nullptr);
        this->board[7]->getEdge(2)->addAdjEdges(this->board[7]->getEdge(1), this->board[12]->getEdge(1), this->board[7]->getEdge(3), nullptr);
        this->board[7]->getEdge(3)->addAdjEdges(this->board[7]->getEdge(2), this->board[12]->getEdge(1), this->board[8]->getEdge(2), this->board[7]->getEdge(4));
        this->board[7]->getEdge(4)->addAdjEdges(this->board[3]->getEdge(2), this->board[7]->getEdge(3), this->board[8]->getEdge(2), this->board[3]->getEdge(3));

        // Land 8
            // LandVertices
                // vertices
        this->board[8]->getVertex(3)->addNeighbors(this->board[7]->getVertex(4), this->board[12]->getVertex(4), this->board[8]->getVertex(4));
        this->board[8]->getVertex(4)->addNeighbors(this->board[4]->getVertex(3), this->board[8]->getVertex(3), this->board[9]->getVertex(3));
                // edges
        this->board[8]->getVertex(3)->addIncidentEdges(this->board[8]->getEdge(2), this->board[12]->getEdge(4), this->board[8]->getEdge(3));
        this->board[8]->getVertex(4)->addIncidentEdges(this->board[8]->getEdge(4), this->board[8]->getEdge(3), this->board[9]->getEdge(2));

            // LandEdges
                // vertices
        this->board[8]->getEdge(2)->setVertices(this->board[8]->getVertex(2), this->board[8]->getVertex(3));
        this->board[8]->getEdge(3)->setVertices(this->board[8]->getVertex(3), this->board[8]->getVertex(4));
        this->board[8]->getEdge(4)->setVertices(this->board[8]->getVertex(4), this->board[8]->getVertex(5));
                // edges
        this->board[8]->getEdge(2)->addAdjEdges(this->board[7]->getEdge(4), this->board[7]->getEdge(3), this->board[12]->getEdge(4), this->board[8]->getEdge(3));
        this->board[8]->getEdge(3)->addAdjEdges(this->board[8]->getEdge(2), this->board[12]->getEdge(4), this->board[9]->getEdge(2), this->board[8]->getEdge(4));
        this->board[8]->getEdge(4)->addAdjEdges(this->board[4]->getEdge(2), this->board[8]->getEdge(3), this->board[9]->getEdge(2), this->board[4]->getEdge(3));

        // Land 9
            // LandVertices
                // vertices
        this->board[9]->getVertex(3)->addNeighbors(this->board[8]->getVertex(4), this->board[13]->getVertex(4), this->board[9]->getVertex(4));
        this->board[9]->getVertex(4)->addNeighbors(this->board[5]->getVertex(3), this->board[9]->getVertex(3), this->board[10]->getVertex(3));
                // edges
        this->board[9]->getVertex(3)->addIncidentEdges(this->board[9]->getEdge(2), this->board[13]->getEdge(4), this->board[9]->getEdge(3));
        this->board[9]->getVertex(4)->addIncidentEdges(this->board[9]->getEdge(4), this->board[9]->getEdge(3), this->board[10]->getEdge(2));

            // LandEdges
                // vertices
        this->board[9]->getEdge(2)->setVertices(this->board[9]->getVertex(2), this->board[9]->getVertex(3));
        this->board[9]->getEdge(3)->setVertices(this->board[9]->getVertex(3), this->board[9]->getVertex(4));
        this->board[9]->getEdge(4)->setVertices(this->board[9]->getVertex(4), this->board[9]->getVertex(5));
                // edges
        this->board[9]->getEdge(2)->addAdjEdges(this->board[8]->getEdge(4), this->board[8]->getEdge(3), this->board[13]->getEdge(4), this->board[9]->getEdge(3));
        this->board[9]->getEdge(3)->addAdjEdges(this->board[9]->getEdge(2), this->board[13]->getEdge(4), this->board[10]->getEdge(2), this->board[9]->getEdge(4));
        this->board[9]->getEdge(4)->addAdjEdges(this->board[5]->getEdge(2), this->board[9]->getEdge(3), this->board[10]->getEdge(2), this->board[5]->getEdge(3));
        
        // Land 10
            // LandVertices
                // vertices
        this->board[10]->getVertex(3)->addNeighbors(this->board[9]->getVertex(4), this->board[14]->getVertex(4), this->board[10]->getVertex(4));
        this->board[10]->getVertex(4)->addNeighbors(this->board[6]->getVertex(3), this->board[10]->getVertex(3), this->board[11]->getVertex(3));
                // edges
        this->board[10]->getVertex(3)->addIncidentEdges(this->board[10]->getEdge(2), this->board[14]->getEdge(4), this->board[10]->getEdge(3));
        this->board[10]->getVertex(4)->addIncidentEdges(this->board[10]->getEdge(4), this->board[10]->getEdge(3), this->board[11]->getEdge(2));    

            // LandEdges
                // vertices
        this->board[10]->getEdge(2)->setVertices(this->board[10]->getVertex(2), this->board[10]->getVertex(3));
        this->board[10]->getEdge(3)->setVertices(this->board[10]->getVertex(3), this->board[10]->getVertex(4));
        this->board[10]->getEdge(4)->setVertices(this->board[10]->getVertex(4), this->board[10]->getVertex(5));
                // edges
        this->board[10]->getEdge(2)->addAdjEdges(this->board[9]->getEdge(4), this->board[9]->getEdge(3), this->board[14]->getEdge(4), this->board[10]->getEdge(3));
        this->board[10]->getEdge(3)->addAdjEdges(this->board[10]->getEdge(2), this->board[14]->getEdge(4),this->board[11]->getEdge(2), this->board[10]->getEdge(4));
        this->board[10]->getEdge(4)->addAdjEdges(this->board[6]->getEdge(2), this->board[10]->getEdge(3), this->board[11]->getEdge(2), this->board[6]->getEdge(3));
        
        // Land 11
            // LandVertices
                // vertices
        this->board[11]->getVertex(3)->addNeighbors(this->board[10]->getVertex(4), this->board[15]->getVertex(4), this->board[11]->getVertex(4));
        this->board[11]->getVertex(4)->addNeighbors(this->board[11]->getVertex(5), this->board[11]->getVertex(3), nullptr);
        this->board[11]->getVertex(5)->addNeighbors(this->board[11]->getVertex(0), this->board[11]->getVertex(4), nullptr);
                // edges
        this->board[11]->getVertex(3)->addIncidentEdges(this->board[11]->getEdge(2), this->board[15]->getEdge(4), this->board[11]->getEdge(3));
        this->board[11]->getVertex(4)->addIncidentEdges(this->board[11]->getEdge(4), this->board[11]->getEdge(3), nullptr);
        this->board[11]->getVertex(5)->addIncidentEdges(this->board[11]->getEdge(5), this->board[11]->getEdge(4), nullptr);
            
            // LandEdges
                // vertices
        this->board[11]->getEdge(2)->setVertices(this->board[11]->getVertex(2), this->board[11]->getVertex(3));
        this->board[11]->getEdge(3)->setVertices(this->board[11]->getVertex(3), this->board[11]->getVertex(4));
        this->board[11]->getEdge(4)->setVertices(this->board[11]->getVertex(4), this->board[11]->getVertex(5));
        this->board[11]->getEdge(5)->setVertices(this->board[11]->getVertex(5), this->board[11]->getVertex(0));
                // edges
        this->board[11]->getEdge(2)->addAdjEdges(this->board[10]->getEdge(4), this->board[10]->getEdge(3), this->board[15]->getEdge(4),this->board[11]->getEdge(3));
        this->board[11]->getEdge(3)->addAdjEdges(this->board[11]->getEdge(2), this->board[15]->getEdge(4), this->board[11]->getEdge(4), nullptr);
        this->board[11]->getEdge(4)->addAdjEdges(this->board[11]->getEdge(5), this->board[11]->getEdge(3), nullptr, nullptr);
        this->board[11]->getEdge(5)->addAdjEdges(this->board[6]->getEdge(4), this->board[6]->getEdge(3), this->board[11]->getEdge(4), nullptr);
        
        // Land 12
            // LandVertices
                // vertices
        this->board[12]->getVertex(2)->addNeighbors(this->board[12]->getVertex(1), this->board[12]->getVertex(3), nullptr);
        this->board[12]->getVertex(3)->addNeighbors(this->board[12]->getVertex(2), this->board[16]->getVertex(2), this->board[12]->getVertex(4));
        this->board[12]->getVertex(4)->addNeighbors(this->board[8]->getVertex(3), this->board[12]->getVertex(3), this->board[13]->getVertex(3));
                // edges
        this->board[12]->getVertex(2)->addIncidentEdges(this->board[12]->getEdge(1), this->board[12]->getEdge(2), nullptr);
        this->board[12]->getVertex(3)->addIncidentEdges(this->board[12]->getEdge(2), this->board[16]->getEdge(1), this->board[12]->getEdge(3));
        this->board[12]->getVertex(4)->addIncidentEdges(this->board[12]->getEdge(4), this->board[12]->getEdge(3), this->board[13]->getEdge(2));

            // LandEdges
                // vertices
        this->board[12]->getEdge(1)->setVertices(this->board[12]->getVertex(1), this->board[12]->getVertex(2));
        this->board[12]->getEdge(2)->setVertices(this->board[12]->getVertex(2), this->board[12]->getVertex(3));
        this->board[12]->getEdge(3)->setVertices(this->board[12]->getVertex(3), this->board[12]->getVertex(4));
        this->board[12]->getEdge(4)->setVertices(this->board[12]->getVertex(4), this->board[12]->getVertex(5));
                // edges
        this->board[12]->getEdge(1)->addAdjEdges(this->board[7]->getEdge(2), this->board[12]->getEdge(2), this->board[7]->getEdge(3), nullptr);
        this->board[12]->getEdge(2)->addAdjEdges(this->board[12]->getEdge(1), this->board[16]->getEdge(1), this->board[16]->getEdge(0), nullptr);
        this->board[12]->getEdge(3)->addAdjEdges(this->board[12]->getEdge(2), this->board[16]->getEdge(1), this->board[13]->getEdge(2), this->board[12]->getEdge(4));
        this->board[12]->getEdge(4)->addAdjEdges(this->board[8]->getEdge(2), this->board[12]->getEdge(3), this->board[13]->getEdge(2), this->board[8]->getEdge(3));

        // Land 13
            // LandVertices
                // vertices
        this->board[13]->getVertex(3)->addNeighbors(this->board[12]->getVertex(4), this->board[16]->getVertex(4),this->board[13]->getVertex(4));
        this->board[13]->getVertex(4)->addNeighbors(this->board[9]->getVertex(3), this->board[13]->getVertex(3), this->board[14]->getVertex(3));
                // edges
        this->board[13]->getVertex(3)->addIncidentEdges(this->board[13]->getEdge(2), this->board[16]->getEdge(4), this->board[13]->getEdge(3));
        this->board[13]->getVertex(4)->addIncidentEdges(this->board[13]->getEdge(4), this->board[13]->getEdge(3), this->board[14]->getEdge(2));

            // LandEdges
                // vertices
        this->board[13]->getEdge(2)->setVertices(this->board[13]->getVertex(2), this->board[13]->getVertex(3));
        this->board[13]->getEdge(3)->setVertices(this->board[13]->getVertex(3), this->board[13]->getVertex(4));
        this->board[13]->getEdge(4)->setVertices(this->board[13]->getVertex(4), this->board[13]->getVertex(5));
                // edges
        this->board[13]->getEdge(2)->addAdjEdges(this->board[13]->getEdge(1), this->board[12]->getEdge(3), this->board[16]->getEdge(4), this->board[13]->getEdge(3));
        this->board[13]->getEdge(3)->addAdjEdges(this->board[13]->getEdge(2), this->board[16]->getEdge(4), this->board[14]->getEdge(2), this->board[13]->getEdge(4));
        this->board[13]->getEdge(4)->addAdjEdges(this->board[9]->getEdge(2), this->board[13]->getEdge(3), this->board[14]->getEdge(2), this->board[9]->getEdge(3));
        
        // Land 14
            // LandVertices
                // vertices
        this->board[14]->getVertex(3)->addNeighbors(this->board[13]->getVertex(4), this->board[17]->getVertex(4), this->board[14]->getVertex(4));
        this->board[14]->getVertex(4)->addNeighbors(this->board[10]->getVertex(3), this->board[14]->getVertex(3), this->board[15]->getVertex(3));
                // edges
        this->board[14]->getVertex(3)->addIncidentEdges(this->board[14]->getEdge(2), this->board[17]->getEdge(4), this->board[14]->getEdge(3));
        this->board[14]->getVertex(4)->addIncidentEdges(this->board[14]->getEdge(4), this->board[14]->getEdge(3), this->board[15]->getEdge(2));
            
            // LandEdges
                // vertices
        this->board[14]->getEdge(2)->setVertices(this->board[14]->getVertex(2), this->board[14]->getVertex(3));
        this->board[14]->getEdge(3)->setVertices(this->board[14]->getVertex(3), this->board[14]->getVertex(4));
        this->board[14]->getEdge(4)->setVertices(this->board[14]->getVertex(4), this->board[14]->getVertex(5));       
                // edges
        this->board[14]->getEdge(2)->addAdjEdges(this->board[13]->getEdge(4), this->board[13]->getEdge(3), this->board[17]->getEdge(4), this->board[14]->getEdge(3));
        this->board[14]->getEdge(3)->addAdjEdges(this->board[14]->getEdge(2), this->board[17]->getEdge(4), this->board[15]->getEdge(2), this->board[14]->getEdge(4));
        this->board[14]->getEdge(4)->addAdjEdges(this->board[10]->getEdge(2), this->board[14]->getEdge(3), this->board[15]->getEdge(2), this->board[10]->getEdge(3));
        
        // Land 15
            // LandVertices
                // vertices
        this->board[15]->getVertex(3)->addNeighbors(this->board[14]->getVertex(4), this->board[18]->getVertex(4), this->board[15]->getVertex(4));
        this->board[15]->getVertex(4)->addNeighbors(this->board[11]->getVertex(3), this->board[15]->getVertex(3), nullptr);
                // edges
        this->board[15]->getVertex(3)->addIncidentEdges(this->board[15]->getEdge(2), this->board[18]->getEdge(4), this->board[15]->getEdge(3));
        this->board[15]->getVertex(4)->addIncidentEdges(this->board[15]->getEdge(4), this->board[15]->getEdge(3), nullptr);
            
            // LandEdges
                // vertices
        this->board[15]->getEdge(2)->setVertices(this->board[15]->getVertex(2), this->board[15]->getVertex(3));
        this->board[15]->getEdge(3)->setVertices(this->board[15]->getVertex(3), this->board[15]->getVertex(4));
        this->board[15]->getEdge(4)->setVertices(this->board[15]->getVertex(4), this->board[15]->getVertex(5));
                // edges
        this->board[15]->getEdge(2)->addAdjEdges(this->board[14]->getEdge(4), this->board[14]->getEdge(3), this->board[18]->getEdge(4), this->board[15]->getEdge(3));
        this->board[15]->getEdge(3)->addAdjEdges(this->board[15]->getEdge(2), this->board[18]->getEdge(4), this->board[15]->getEdge(4), nullptr);
        this->board[15]->getEdge(4)->addAdjEdges(this->board[15]->getEdge(5), this->board[15]->getEdge(3), this->board[11]->getEdge(3), nullptr);
        
        // Land 16
            // LandVertices
                // vertices
        this->board[16]->getVertex(2)->addNeighbors(this->board[16]->getVertex(1), this->board[16]->getVertex(3), nullptr);
        this->board[16]->getVertex(3)->addNeighbors(this->board[16]->getVertex(2), this->board[16]->getVertex(4), nullptr);
        this->board[16]->getVertex(4)->addNeighbors(this->board[13]->getVertex(3), this->board[16]->getVertex(3), this->board[17]->getVertex(3));
                // edges
        this->board[16]->getVertex(2)->addIncidentEdges(this->board[16]->getEdge(1), this->board[16]->getEdge(2), nullptr);
        this->board[16]->getVertex(3)->addIncidentEdges(this->board[16]->getEdge(2), this->board[16]->getEdge(3), nullptr);
        this->board[16]->getVertex(4)->addIncidentEdges(this->board[16]->getEdge(4), this->board[16]->getEdge(3), this->board[17]->getEdge(2));
            
            // LandEdges
                // vertices
        this->board[16]->getEdge(1)->setVertices(this->board[16]->getVertex(1), this->board[16]->getVertex(2));
        this->board[16]->getEdge(2)->setVertices(this->board[16]->getVertex(2), this->board[16]->getVertex(3));
        this->board[16]->getEdge(3)->setVertices(this->board[16]->getVertex(3), this->board[16]->getVertex(4));
        this->board[16]->getEdge(4)->setVertices(this->board[16]->getVertex(4), this->board[16]->getVertex(5));
                // edges
        this->board[16]->getEdge(1)->addAdjEdges(this->board[12]->getEdge(2), this->board[16]->getEdge(2), this->board[12]->getEdge(3), nullptr);
        this->board[16]->getEdge(2)->addAdjEdges(this->board[16]->getEdge(1), this->board[16]->getEdge(3), nullptr, nullptr);
        this->board[16]->getEdge(3)->addAdjEdges(this->board[16]->getEdge(2), this->board[17]->getEdge(2), this->board[16]->getEdge(4), nullptr);
        this->board[16]->getEdge(4)->addAdjEdges(this->board[13]->getEdge(2), this->board[16]->getEdge(3), this->board[17]->getEdge(2), this->board[13]->getEdge(3));
        
        // Land 17
            // LandVertices
                // vertices
        this->board[17]->getVertex(3)->addNeighbors(this->board[17]->getVertex(2), this->board[17]->getVertex(4), nullptr);
        this->board[17]->getVertex(4)->addNeighbors(this->board[14]->getVertex(3), this->board[17]->getVertex(3), this->board[18]->getVertex(3));
                // edges
        this->board[17]->getVertex(3)->addIncidentEdges(this->board[17]->getEdge(2), this->board[17]->getEdge(3), nullptr);
        this->board[17]->getVertex(4)->addIncidentEdges(this->board[17]->getEdge(4), this->board[17]->getEdge(3), this->board[18]->getEdge(2));
            
            // LandEdges
                // vertices
        this->board[17]->getEdge(2)->setVertices(this->board[17]->getVertex(2), this->board[17]->getVertex(3));
        this->board[17]->getEdge(3)->setVertices(this->board[17]->getVertex(3), this->board[17]->getVertex(4));
        this->board[17]->getEdge(4)->setVertices(this->board[17]->getVertex(4), this->board[17]->getVertex(5));
                // edges
        this->board[17]->getEdge(2)->addAdjEdges(this->board[16]->getEdge(4), this->board[16]->getEdge(3), this->board[17]->getEdge(3), nullptr);
        this->board[17]->getEdge(3)->addAdjEdges(this->board[17]->getEdge(2), this->board[18]->getEdge(2), this->board[17]->getEdge(4), nullptr);
        this->board[17]->getEdge(4)->addAdjEdges(this->board[14]->getEdge(2), this->board[17]->getEdge(3), this->board[18]->getEdge(2), this->board[14]->getEdge(3));
        
        // Land 18
            // LandVertices
                // vertices
        this->board[18]->getVertex(3)->addNeighbors(this->board[18]->getVertex(2), this->board[18]->getVertex(4), nullptr);
        this->board[18]->getVertex(4)->addNeighbors(this->board[15]->getVertex(3), this->board[18]->getVertex(3), nullptr);
                // edges
        this->board[18]->getVertex(3)->addIncidentEdges(this->board[18]->getEdge(2), this->board[18]->getEdge(3), nullptr);
        this->board[18]->getVertex(4)->addIncidentEdges(this->board[18]->getEdge(4), this->board[18]->getEdge(3), nullptr);
            
            // LandEdges
                // vertices
        this->board[18]->getEdge(2)->setVertices(this->board[18]->getVertex(2), this->board[18]->getVertex(3));
        this->board[18]->getEdge(3)->setVertices(this->board[18]->getVertex(3), this->board[18]->getVertex(4));
        this->board[18]->getEdge(4)->setVertices(this->board[18]->getVertex(4), this->board[18]->getVertex(5));
                // edges
        this->board[18]->getEdge(2)->addAdjEdges(this->board[17]->getEdge(4), this->board[17]->getEdge(3), this->board[18]->getEdge(3), nullptr);
        this->board[18]->getEdge(3)->addAdjEdges(this->board[18]->getEdge(2), this->board[18]->getEdge(4), nullptr, nullptr);
        this->board[18]->getEdge(4)->addAdjEdges(this->board[15]->getEdge(2), this->board[18]->getEdge(3), this->board[15]->getEdge(3), nullptr);

        std::cout << "Board created" << std::endl;
    }

    Board::~Board() {
        for (auto hex : board) {
            delete hex;
        }
    }

    void Board::printBoard() const {
        std::cout << "Printing Board:" << std::endl;
        for (const Hexagon* hex : board) {
            std::cout << "Hexagon " << hex->getNum() << ":" << std::endl;

            // Print vertices
            for (int i = 0; i < 6; ++i) {
                const Vertex* vertex = hex->getVertex(i);
                if (vertex) {
                    std::cout << "Vertex " << i << ": " << vertex->getNum() << std::endl;
                } else {
                    std::cout << "Vertex " << i << ": nullptr" << std::endl;
                }
            }

            // Print edges
            for (int i = 0; i < 6; ++i) {
                const Edge* edge = hex->getEdge(i);
                if (edge) {
                    std::cout << "Edge " << i << ": " << edge->getNum() << std::endl;
                } else {
                    std::cout << "Edge " << i << ": nullptr" << std::endl;
                }
            }

            std::cout << std::endl;
        }
    }
    
}
