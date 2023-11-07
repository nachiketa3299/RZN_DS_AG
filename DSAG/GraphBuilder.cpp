#include "GraphBuilder.h"

#include <algorithm>

using namespace std;

RGraphBuilder::RGraphBuilder(const vector<int>& vertices): vertices(vertices) {}

RGraphBuilder& RGraphBuilder::AddWeightedEdge(const pair<int, int>& edge, int weight)
{
    return this->AddWeightedEdge(edge.first, edge.second, weight);
}

RGraphBuilder& RGraphBuilder::AddWeightedEdge(int start_vertex, int end_vertex, int weight)
{
    bool edge_already_in = find_if
    (
        adj_list[start_vertex].begin(), 
        adj_list[start_vertex].end(), 
        [&end_vertex](const pair<int, int>& op) 
        {
            return op.first == end_vertex;
        }
    ) != adj_list[start_vertex].end();

    if (edge_already_in)
        return *this;

    this->adj_list[start_vertex].push_back(make_pair(end_vertex, weight));
    push_heap
    (
        adj_list[start_vertex].begin(), 
        adj_list[start_vertex].end(),
        RGraphBuilder::GreaterWeightPred
    );

    this->adj_list[end_vertex].push_back(make_pair(start_vertex, weight));
    push_heap
    (
        adj_list[end_vertex].begin(), 
        adj_list[end_vertex].end(),
        RGraphBuilder::GreaterWeightPred
    );

    return *this;
}

RGraphBuilder& RGraphBuilder::AddVertices(const vector<int>& vertices)
{
    this->vertices.insert(this->vertices.end(), vertices.begin(), vertices.end());
    if (this->vertices.size() > this->adj_list.size())
        this->adj_list.resize(this->vertices.size());
    for (auto& cadj_list : this->adj_list)
    {
        if (!is_heap(cadj_list.begin(), cadj_list.end()))
        {
            make_heap
            (
                cadj_list.begin(), 
                cadj_list.end(), 
                RGraphBuilder::GreaterWeightPred
            );
        }
    }
    return *this;
}

RGraphBuilder& RGraphBuilder::AddVertex(int vertex)
{
    this->vertices.push_back(vertex);
    return *this;
}

bool RGraphBuilder::GreaterWeightPred(const pair<int, int>& op1, const pair<int, int>& op2)
{
    return op1.second > op2.second;
}

bool RGraphBuilder::LessWeightPred(const pair<int, int>& op1, const pair<int, int>& op2)
{
    return op1.second < op2.second;
}

