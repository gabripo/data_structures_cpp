#include "GraphAL.h"

GraphAL::GraphAL(int inputNumVertices) {
    init(inputNumVertices);
}

GraphAL::~GraphAL() {
    for (int i = 0; i < numVertices; i++)
    {
        delete verticesList[i];
    }
    delete[] verticesList;
    delete[] markArray;
}

void GraphAL::init(int inputNumVertices) {
    numVertices = inputNumVertices;
    numEdges = 0;
    verticesList = new LList<Edge>*[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        verticesList[i] = new LList<Edge>();
    }
    markArray = new int[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        markArray[i] = UNVISITED;
    }
}

int GraphAL::getVertices() {
    return numVertices;
}

int GraphAL::getEdges() {
    return numEdges;
}

int GraphAL::getFirstNeighbour(int idxVertex) {
    if (verticesList[idxVertex]->length() == 0)
    {
        return numVertices; // List length if none
    }
    verticesList[idxVertex]->moveToStart();
    Edge firstNeighbour = verticesList[idxVertex]->getValue();
    return firstNeighbour.getIdxPointedVertex();
}

int GraphAL::getNextNeighbour(int idxVertex1, int idxVertex2) {
    if (isEdge(idxVertex1, idxVertex2))
    {
        if ( (verticesList[idxVertex1]->currentPos()+1) < verticesList[idxVertex1]->length() )
        {
            verticesList[idxVertex1]->next();
            Edge nextNeighbour = verticesList[idxVertex1]->getValue();
            return nextNeighbour.getIdxPointedVertex();
        }
    }
    return getVertices(); // List length if none
}

void GraphAL::setEdgeWeight(int idxVertex1, int idxVertex2, int edgeWeightToSet) {
    if (edgeWeightToSet < 0)
    {
        std::cout << "Invalid weight to set!" << std::endl;
        return;
    }

    Edge currentEdge(idxVertex2, edgeWeightToSet);
    if (isEdge(idxVertex1, idxVertex2))
    {
        verticesList[idxVertex1]->remove();
    } else {
        numEdges++;
        for (verticesList[idxVertex1]->moveToStart();
        verticesList[idxVertex1]->currentPos() < verticesList[idxVertex1]->length();
        verticesList[idxVertex1]->next())
        {
            Edge tempEdge = verticesList[idxVertex1]->getValue();
            if (tempEdge.getIdxPointedVertex() > idxVertex2)
            {
                break;
            }
        }
    }
    verticesList[idxVertex1]->insert(currentEdge);
}

int GraphAL::getEdgeWeight(int idxVertex1, int idxVertex2) {
    if (isEdge(idxVertex1, idxVertex2))
    {
        Edge currentEdge = verticesList[idxVertex1]->getValue();
        return currentEdge.getWeight();
    } else {
        return 0;
    }
}

void GraphAL::delEdge(int idxVertex1, int idxVertex2) {
    if (isEdge(idxVertex1, idxVertex2))
    {
        verticesList[idxVertex1]->remove();
        numEdges--;
    }
}

bool GraphAL::isEdge(int idxVertex1, int idxVertex2) {
    for (verticesList[idxVertex1]->moveToStart();
    verticesList[idxVertex1]->currentPos() < verticesList[idxVertex1]->length();
    verticesList[idxVertex1]->next())
    {
        Edge tempEdge = verticesList[idxVertex1]->getValue();
        if (tempEdge.getIdxPointedVertex() == idxVertex2 )
        {
            return true;
        }
    }
    return false;
}

int GraphAL::getMark(int idxVertex) {
    return markArray[idxVertex];
}

void GraphAL::setMark(int idxVertex, int markValueToSet) {
    markArray[idxVertex] = markValueToSet;
}