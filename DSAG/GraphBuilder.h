#ifndef _GRAPH_BUILDER_H
#define _GRAPH_BUILDER_H

#include <vector>

class RGraph;

class RGraphBuilder
{
    friend RGraph;
public:
    RGraphBuilder(const std::vector<int>& vertices);
    RGraphBuilder() {}
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
    std::vector<int> vertices;
    std::vector<std::vector<std::pair<int, int>>> adj_list;
private:
    static bool GreaterWeightPred(const std::pair<int, int>&, const std::pair<int, int>&);
    static bool LessWeightPred(const std::pair<int, int>&, const std::pair<int, int>&);
};

#endif // !_GRAPH_BUILDER_H
