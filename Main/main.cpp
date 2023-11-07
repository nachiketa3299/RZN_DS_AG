#include <Graph.h>
#include <vector>

int main(void)
{
    RGraphBuilder* gb = new RGraphBuilder;
    (*gb).AddVertices({0, 1, 2, 3, 4, 5, 6, 7, 8})
        .AddWeightedEdge({ 0, 1 }, 4)
        .AddWeightedEdge({ 0, 7 }, 8)
        .AddWeightedEdge({ 1, 7 }, 11)
        .AddWeightedEdge({ 1, 2 }, 8)
        .AddWeightedEdge({ 2, 8 }, 2)
        .AddWeightedEdge({ 2, 5 }, 4)
        .AddWeightedEdge({ 2, 3 }, 7)
        .AddWeightedEdge({ 3, 4 }, 9)
        .AddWeightedEdge({ 3, 5 }, 14)
        .AddWeightedEdge({ 4, 5 }, 10)
        .AddWeightedEdge({ 5, 6 }, 2)
        .AddWeightedEdge({ 6, 7 }, 1)
        .AddWeightedEdge({ 6, 8 }, 6)
        .AddWeightedEdge({ 7, 8 }, 7);

    RGraph graph(*gb);
    delete gb;
    graph.Print();
    graph.MinPath();

	return 0;
}
