#include "../Graph/Graph.cpp"
#include <iostream>
#define UNVISITED 0

// Adjacency Matrix representation for graphs
class GraphAM : public Graph {
    private:
        int numVertices;
        int numEdges;
        int** adjacencyMatrix;
        int* markArray;
    public:
        GraphAM(int numVertices);
        ~GraphAM();

        void init(int inputNumVertices);
        int getVertices();
        int getEdges();
        int getFirstNeighbour(int idxVertex);
        int getNextNeighbour(int idxVertex1, int idxVertex2);
        void setEdgeWeight(int idxVertex1, int idxVertex2, int edgeWeightToSet);
        int getEdgeWeight(int idxVertex1, int idxVertex2);
        void delEdge(int idxVertex1, int idxVertex2);
        bool isEdge(int idxVertex1, int idxVertex2);
        int getMark(int idxVertex);
        void setMark(int idxVertex, int markValueToSet);
};