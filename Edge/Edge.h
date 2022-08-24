#ifndef EDGE
#define EDGE

class Edge {
    private:
        int idxPointedVertex;
        int weight;
    public:
        Edge();
        Edge(int inputIdxPointedVertex, int inputWeight);

        int getIdxPointedVertex();
        int getWeight();
};

#endif