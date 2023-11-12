/// @file GraphBuilder.h
/// @author RZN
/// @todo Builder Ŭ������ ���� ���� �� ������Ʈ�� Ŀ���� �Ǵ��ؾ���.

#ifndef _GRAPH_BUILDER_H
#define _GRAPH_BUILDER_H

#include <vector>
#include "DSAG_Types.h"

/// @enum EGDirMod
/// @short �׷����� ������ ���⼺ ���θ� ��Ÿ����.
enum class EGDirMod 
{ 
    Undirected,
    Directed 
};

/// @enum EGWMod
/// @short �׷��� ������ ����ġ ���ο� ������ ��Ÿ����.
enum class EGWMod
{
    /// ����ġ�� �������� �ʴ´�.
    UnWeighted,
    /// ���� ����ġ�� �����Ѵ�.
    PosWeighted,
    /// ���� ����ġ�� �����Ѵ�.
    NegWeighted
};

class RGraph;

/// @class RGraphBuilder
/// @short @ref RGraph �׷����� ����� ���� ����ϴ� ���� Ŭ�����̴�.
class RGraphBuilder
{
    friend RGraph;
public:
    RGraphBuilder(EGWMod wmod = EGWMod::UnWeighted, EGDirMod dirmod = EGDirMod::Undirected);
    RGraphBuilder(const std::vector<DataType>& vertices, EGWMod wmod = EGWMod::UnWeighted, EGDirMod dirmod = EGDirMod::Undirected);
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
    /// @short ���� � ���Ǵ� Predicate
    static bool GreaterWeightPred(const std::pair<int, int>&, const std::pair<int, int>&);
    /// @short ���� � ���Ǵ� Predicate
    static bool LessWeightPred(const std::pair<int, int>&, const std::pair<int, int>&);
private:
    std::vector<int> vertices;
    std::vector<std::vector<std::pair<int, int>>> adj_list;

    /// @short �׷����� ���� ���⼺ ���¸� ��Ÿ����.
    EGDirMod dirmod;
    /// @short �׷����� ���� ����ġ ���¸� ��Ÿ����.
    EGWMod wmod;
};

#endif // !_GRAPH_BUILDER_H
