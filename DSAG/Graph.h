#ifndef _GRAPH_H
#define _GRAPH_H

#include "GraphBuilder.h"

#include <vector>
#include <functional>

class RGraph
{
public:
    RGraph(const RGraphBuilder& gbuilder);
public:
    void Print() const;
    int MinPath() const;
private:
    std::vector<int> vertices;
    std::vector<std::vector<std::pair<int, int>>> adj_list;
};

#endif // !_GRAPH_H
