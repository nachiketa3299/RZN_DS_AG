/// @file GraphBuilder.h
/// @author RZN
/// @todo Builder 클래스를 따로 모을 지 프로젝트가 커지면 판단해야함.

#ifndef _GRAPH_BUILDER_H
#define _GRAPH_BUILDER_H

#include <vector>
#include "DSAG_Types.h"

/// @enum EGDirMod
/// @short 그래프의 간선의 방향성 여부를 나타낸다.
enum class EGDirMod 
{ 
    Undirected,
    Directed 
};

/// @enum EGWMod
/// @short 그래프 간선의 가중치 여부와 종류를 나타낸다.
enum class EGWMod
{
    /// 가중치가 존재하지 않는다.
    UnWeighted,
    /// 양의 가중치만 존재한다.
    PosWeighted,
    /// 음의 가중치도 존재한다.
    NegWeighted
};

class RGraph;

/// @class RGraphBuilder
/// @short @ref RGraph 그래프를 만들기 위해 사용하는 빌더 클래스이다.
class RGraphBuilder
{
    friend RGraph;
public:
    RGraphBuilder(EGWMod wmod = EGWMod::UnWeighted, EGDirMod dirmod = EGDirMod::Undirected);
    RGraphBuilder(const std::vector<DataType>& vertices, EGWMod wmod = EGWMod::UnWeighted, EGDirMod dirmod = EGDirMod::Undirected);
public:
    /// @short (u, v, w) 형태로 정점 u, v에 부속하고 가중치가 w인 간선을 추가한다.
    /// @param[in] edge pair 형태로 전달되는 간선의 시작과 끝 정점의 인덱스
    /// @return 현재 빌더 인스턴스
    RGraphBuilder& AddWeightedEdge(const std::pair<int, int>& edge, int weight);

    /// @short (u, v, w) 형태로 정점 u, v에 부속하고 가중치가 w인 간선을 추가한다.
    /// @param[in] start_vertex 간선의 시작 인덱스
    /// @param[in] end_vertex 간선의 끝 인덱스
    /// @return 현재 빌더 인스턴스
    RGraphBuilder& AddWeightedEdge(int start_vertex, int end_vertex, int weight);

    /// @short vector 형태로 정점을 받는다. 내부 정점 벡터와 받은 정점 벡터를 병합한다.
    /// @param[in] vertices 추가할 정점들의 정보가 담긴 벡터
    /// @return 현재 빌더 인스턴스
    RGraphBuilder& AddVertices(const std::vector<int>& vertices);

    /// @short 정점의 데이터를 받아 정점에 추가한다.
    /// @param[in] vertex 추가할 정점의 데이터
    /// @return 현재 빌더 인스턴스
    RGraphBuilder& AddVertex(int vertex);
private:
    /// @short 정렬 등에 사용되는 Predicate
    static bool GreaterWeightPred(const std::pair<int, int>&, const std::pair<int, int>&);
    /// @short 정렬 등에 사용되는 Predicate
    static bool LessWeightPred(const std::pair<int, int>&, const std::pair<int, int>&);
private:
    std::vector<int> vertices;
    std::vector<std::vector<std::pair<int, int>>> adj_list;

    /// @short 그래프의 현재 방향성 상태를 나타낸다.
    EGDirMod dirmod;
    /// @short 그래프의 현재 가중치 상태를 나타낸다.
    EGWMod wmod;
};

#endif // !_GRAPH_BUILDER_H
