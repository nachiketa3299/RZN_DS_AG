/// @file Graph.h
/// @author RZN

#ifndef _GRAPH_H
#define _GRAPH_H

#include "GraphBuilder.h"

#include <vector>
#include <functional>

#include "DSAG_Types.h"

/// @enum EGMinPathMod
/// @short 그래프의 최소/최대 가중치 경로합을 탐색하는 데에 어떤 알고리즘을 쓸 것인지 (가중치가 양수인 경우)
enum class EGMinPathMod 
{ 
    Dijkstra,  ///< 다익스트라(Dijstra) 알고리즘
    Kruskal    ///< 크루스칼(Kruskal) 알고리즘
};

/// @class RGraph
/// @short int 데이터 형에 대해서만 작동하는 그래프
class RGraph
{
public:
    /// @short @ref RGraphBuilder 객체로 그래프를 초기화하는 생성자
    /// @param[in] gbuilder 그래프 빌더 객체
    /// @relatesalso RGraphBuilder
    RGraph(const RGraphBuilder& gbuilder);
public:
    void Print() const;
    int MinPath(IndexType start_idx, IndexType end_idx, EGMinPathMod AlgMod) const;
    /// @todo 최소/최대 가중치합을 일반화하여 최대 우선순위(?) 경로로 바꿀 수 있을 듯
private:
    /// @short Kruskal's Algorithm으로 최소 가중치합 경로
    int MinPath_Kruskal() const;
    /// @short Dijkstra's Algorithm으로 최소 가중치합 경로
    int MinPath_Dijkstra(IndexType start_idx, IndexType end_idx) const;
private:
    /// @short 정점(Vertex)의 집합
    std::vector<int> vertices;
    /// @short 연결 리스트
    std::vector<std::vector<std::pair<IndexType, WeightType>>> adj_list;
};

#endif // !_GRAPH_H
