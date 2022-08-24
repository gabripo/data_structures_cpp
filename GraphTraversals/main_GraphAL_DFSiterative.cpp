#include "../GraphAL/GraphAL.cpp"
#include <iostream>
#include <stack>

void graphTraverse(Graph* G);
void DFS(Graph* G, int idxVertex);
void PreVisit(Graph* G, int idxVertex);
void PostVisit(Graph* G, int idxVertex);

int main(int argc, char const *argv[])
{
    const int numVertices = 6; 
    GraphAL g(numVertices);
    enum vertexNames {
        A,
        B,
        C,
        D,
        E,
        F
    };
    const int defaultWeight = 1;
    g.setEdgeWeight(A, E, defaultWeight);
    g.setEdgeWeight(A, C, defaultWeight);
    g.setEdgeWeight(B, C, defaultWeight);
    g.setEdgeWeight(B, F, defaultWeight);
    g.setEdgeWeight(C, D, defaultWeight);
    g.setEdgeWeight(C, F, defaultWeight);
    g.setEdgeWeight(D, F, defaultWeight);
    g.setEdgeWeight(E, F, defaultWeight);
    for (int i = 0; i < g.getVertices(); i++)
    {
        g.setMark(i, UNVISITED);
    }

    graphTraverse(&g);
    for (int i = 0; i < g.getVertices(); i++)
    {
        if (g.getMark(i) == UNVISITED)
        {
            std::cout << "Node " << i << " was not visited!" << std::endl;
        } else if (g.getMark(i) == VISITED) {
            std::cout << "Node " << i << " was visited. ;-)" << std::endl;
        }
    }

    return 0;
}

void graphTraverse(Graph* G) {
    int idxVertex;
    for (idxVertex = 0; idxVertex < G->getVertices() ; idxVertex++)
    {
        G->setMark(idxVertex, UNVISITED);
    }
    for (idxVertex = 0; idxVertex < G->getVertices(); idxVertex++)
    {
        if (G->getMark(idxVertex) == UNVISITED)
        {
            DFS(G, idxVertex);
        }
    }
}

void DFS(Graph* G, int idxVertex) {
    std::stack<int> verticesStack;
    verticesStack.push(idxVertex);
    while (!verticesStack.empty())
    {
        int currentVertex = verticesStack.top();
        verticesStack.pop();

        if (G->getMark(currentVertex) == VISITED)
        {
            continue;
        }
        PreVisit(G, idxVertex);
        G->setMark(currentVertex, VISITED);

        for (int currentChild = G->getFirstNeighbour(currentVertex); currentChild != G->getVertices(); currentChild = G->getNextNeighbour(currentVertex, currentChild))
        {
            if (G->getMark(currentChild) == VISITED)
            {
                continue;
            } else {
                verticesStack.push(currentChild);
            }
        }
        PostVisit(G, idxVertex);
    }
}

void PreVisit(Graph* G, int idxVertex) {

}

void PostVisit(Graph* G, int idxVertex) {

}