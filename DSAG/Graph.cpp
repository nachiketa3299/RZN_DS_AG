/// @file Graph.cpp
/// @author RZN

#include <iostream>
#include <algorithm>

#include "Graph.h"
#include "UnionFind.h"

using namespace std;

RGraph::RGraph(const RGraphBuilder& gbuilder): vertices(gbuilder.vertices), adj_list(gbuilder.adj_list) { }

void RGraph::Print() const
{
    cout << "===WEIGHTED_GRAPH===" << '\n';
    cout << "---Vertices---" << '\n';
    for (size_t i = 0; i < this->vertices.size(); ++i)
        cout << i << "[" << this->vertices[i] << "] ";
    cout << '\n';
    cout << "---Edges---" << '\n';
    for (size_t vi = 0; vi < this->vertices.size(); ++vi)
    {
        cout << vi << " | ";
        for (const auto& ew : this->adj_list[vi])
        {
            cout << "(" << ew.first << ", " << ew.second << ") ";
        }
        cout << '\n';
    }
    return;
}

int RGraph::MinPath() const
{
    vector<tuple<int, int, int>> edges;
    for (size_t vi = 0; vi < this->adj_list.size(); ++vi)
    {
        for (const auto& we : this->adj_list[vi])
            edges.push_back(make_tuple(vi, we.first, we.second));
    }

    sort
    (
        edges.begin(), 
        edges.end(), 
        [](const tuple<int, int, int>& op1, const tuple<int, int, int>& op2) 
        { 
            return get<2>(op1) < get<2>(op2); 
        }
    );

    vector<tuple<int, int, int>> min_edges;

    RUnionFind uf(this->vertices.size());
    for (const auto& edge : edges)
    {
        if (!uf.NodesHaveSameLastParent(get<0>(edge), get<1>(edge)))
        {
            uf.UnionNodes(get<0>(edge), get<1>(edge));
            min_edges.push_back(edge);
        }
    }

    for (const auto& edge : min_edges)
    {
        cout << get<0>(edge) << "--(" << get<2>(edge) << ")--" << get<1>(edge) << '\n';
    }

    return 0;
}

