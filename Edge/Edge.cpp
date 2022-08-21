#include "Edge.h"

Edge::Edge() {
    idxPointedVertex = 0;
    weight = 0;
}

Edge::Edge(int inputIdxPointedVertex, int inputWeight) {
    idxPointedVertex = inputIdxPointedVertex;
    weight = inputWeight;
}

int Edge::getIdxPointedVertex() {
    return idxPointedVertex;
}

int Edge::getWeight() {
    return weight;
}