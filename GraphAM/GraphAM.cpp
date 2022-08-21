#include "GraphAM.h"

GraphAM::GraphAM(int numVertices) {
    init(numVertices);
}

GraphAM::~GraphAM() {
    for (int i = 0; i < numVertices; i++)
    {
        delete[] adjacencyMatrix[i];
    }
    delete[] adjacencyMatrix;
    delete[] markArray;
}

void GraphAM::init(int inputNumVertices) {
    numVertices = inputNumVertices;
    numEdges = 0;

    markArray = new int[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        markArray[i] = UNVISITED;
    }
    
    adjacencyMatrix = new int*[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        adjacencyMatrix[i] = new int[numVertices];
        for (int j = 0; j < numVertices; j++)
        {
            adjacencyMatrix[i][j] = 0;
        }
    }
}

int GraphAM::getVertices() {
    return numVertices;
}

int GraphAM::getEdges() {
    return numEdges;
}

int GraphAM::getFirstNeighbour(int idxVertex) {
    for (int i = 0; i < numVertices; i++)
    {
        if (adjacencyMatrix[idxVertex][i] != 0)
        {
            return i;
        }
    }
    return numVertices; // Row length if none
}

int GraphAM::getNextNeighbour(int idxVertex1, int idxVertex2) {
    for (int i = idxVertex2+1; i < numVertices; i++)
    {
        if (adjacencyMatrix[idxVertex1][i] != 0)
        {
            return i;
        }
    }
    return numVertices; // Row length if none
}

void GraphAM::setEdgeWeight(int idxVertex1, int idxVertex2, int edgeWeightToSet) {
    if (edgeWeightToSet <= 0)
    {
        std::cout << "Invalid weight to set!" << std::endl;
        return;
    }
    if (adjacencyMatrix[idxVertex1][idxVertex2] == 0)
    {
        numEdges++;
    }
    adjacencyMatrix[idxVertex1][idxVertex2] = edgeWeightToSet;
}

int GraphAM::getEdgeWeight(int idxVertex1, int idxVertex2) {
    return adjacencyMatrix[idxVertex1][idxVertex2];
}

void GraphAM::delEdge(int idxVertex1, int idxVertex2) {
    if (adjacencyMatrix[idxVertex1][idxVertex2] != 0)
    {
        numEdges--;
    }
    adjacencyMatrix[idxVertex1][idxVertex2] = 0;
}

bool GraphAM::isEdge(int idxVertex1, int idxVertex2) {
    return (adjacencyMatrix[idxVertex1][idxVertex2] != 0);
}

int GraphAM::getMark(int idxVertex) {
    return markArray[idxVertex];
}

void GraphAM::setMark(int idxVertex, int markValueToSet) {
    markArray[idxVertex] = markValueToSet;
}