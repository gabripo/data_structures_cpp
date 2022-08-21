class Graph {
    private:
        void operator=(const Graph&);
        Graph(const Graph&);
    public:
        Graph();
        virtual ~Graph();

        virtual void init(int inputNumVertices) = 0;
        virtual int getVertices() = 0;
        virtual int getEdges() = 0;
        virtual int getFirstNeighbour(int idxVertex) = 0;
        virtual int getNextNeighbour(int idxVertex1, int idxVertex2) = 0;
        virtual void setEdgeWeight(int idxVertex1, int idxVertex2, int edgeWeightToSet) = 0;
        virtual int getEdgeWeight(int idxVertex1, int idxVertex2) = 0;
        virtual void delEdge(int idxVertex1, int idxVertex2) = 0;
        virtual bool isEdge(int idxVertex1, int idxVertex2) = 0;
        virtual int getMark(int idxVertex) = 0;
        virtual void setMark(int idxVertex, int markValueToSet) = 0;
};