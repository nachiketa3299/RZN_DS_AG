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
    /// @short (u, v, w) ���·� ���� u, v�� �μ��ϰ� ����ġ�� w�� ������ �߰��Ѵ�.
    /// @param[in] edge pair ���·� ���޵Ǵ� ������ ���۰� �� ������ �ε���
    /// @return ���� ���� �ν��Ͻ�
    RGraphBuilder& AddWeightedEdge(const std::pair<int, int>& edge, int weight);

    /// @short (u, v, w) ���·� ���� u, v�� �μ��ϰ� ����ġ�� w�� ������ �߰��Ѵ�.
    /// @param[in] start_vertex ������ ���� �ε���
    /// @param[in] end_vertex ������ �� �ε���
    /// @return ���� ���� �ν��Ͻ�
    RGraphBuilder& AddWeightedEdge(int start_vertex, int end_vertex, int weight);

    /// @short vector ���·� ������ �޴´�. ���� ���� ���Ϳ� ���� ���� ���͸� �����Ѵ�.
    /// @param[in] vertices �߰��� �������� ������ ��� ����
    /// @return ���� ���� �ν��Ͻ�
    RGraphBuilder& AddVertices(const std::vector<int>& vertices);

    /// @short ������ �����͸� �޾� ������ �߰��Ѵ�.
    /// @param[in] vertex �߰��� ������ ������
    /// @return ���� ���� �ν��Ͻ�
    RGraphBuilder& AddVertex(int vertex);
private:
    std::vector<int> vertices;
    std::vector<std::vector<std::pair<int, int>>> adj_list;
private:
    static bool GreaterWeightPred(const std::pair<int, int>&, const std::pair<int, int>&);
    static bool LessWeightPred(const std::pair<int, int>&, const std::pair<int, int>&);
};

#endif // !_GRAPH_BUILDER_H
