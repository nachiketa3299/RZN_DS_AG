/// @file Graph.cpp
/// @author RZN

#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

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

int RGraph::MinPath(IndexType start_idx, IndexType end_idx, EGMinPathMod AlgMod) const
{
    switch (AlgMod)
    {
    case EGMinPathMod::Dijkstra:
        return this->MinPath_Dijkstra(start_idx, end_idx);
        break;
    case EGMinPathMod::Kruskal:
    default:
        return this->MinPath_Kruskal();
        break;
    }
}

int RGraph::MinPath_Kruskal() const
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

int RGraph::MinPath_Dijkstra(IndexType start_idx, IndexType end_idx) const
{
    using DistanceType = int;
    static constexpr DistanceType START_DISTANCE = 0;
    using VertexDistanceType = pair<IndexType, WeightType>;
    static auto GetVertexIndex  = [](const VertexDistanceType& edge) { return edge.first;  };
    static auto GetVertexWeight = [](const VertexDistanceType& edge) { return edge.second; };

    struct tVertexDistance
    {
        tVertexDistance()
        {
            static IndexType cnt = 0;
            this->idx = cnt++;
        };
        IndexType idx;
        WeightType distance = numeric_limits<WeightType>::max();
        bool operator>(const tVertexDistance& e) { return this->distance > e.distance; };
    };

    // PQ를 그냥 써야 함?

    vector<tVertexDistance> distance_from_start_idx(this->vertices.size());
    distance_from_start_idx[start_idx].distance = START_DISTANCE;

    vector<IndexType> visited(this->vertices.size(), false);

    return 0;
}

