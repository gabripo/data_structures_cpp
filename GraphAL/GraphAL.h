#include "../Graph/Graph.cpp"
#include "../List/List.cpp"
#include "../LList/LList.cpp"
#include "../Edge/Edge.cpp"

enum vertexMarks {
    UNVISITED,
    VISITED,
};

// Adjacency List representation for graphs
class GraphAL : public Graph {
    private:
        LList<Edge>** verticesList;
        int numVertices;
        int numEdges;
        int* markArray;
    public:
        GraphAL(int inputNumVertices);
        ~GraphAL();

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