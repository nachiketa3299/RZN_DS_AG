/// @file Graph.h
/// @author RZN

#ifndef _GRAPH_H
#define _GRAPH_H

#include "GraphBuilder.h"

#include <vector>
#include <functional>

#include "DSAG_Types.h"

/// @enum EGMinPathMod
/// @short �׷����� �ּ�/�ִ� ����ġ ������� Ž���ϴ� ���� � �˰����� �� ������ (����ġ�� ����� ���)
enum class EGMinPathMod 
{ 
    Dijkstra,  ///< ���ͽ�Ʈ��(Dijstra) �˰���
    Kruskal    ///< ũ�罺Į(Kruskal) �˰���
};

/// @class RGraph
/// @short int ������ ���� ���ؼ��� �۵��ϴ� �׷���
class RGraph
{
public:
    /// @short @ref RGraphBuilder ��ü�� �׷����� �ʱ�ȭ�ϴ� ������
    /// @param[in] gbuilder �׷��� ���� ��ü
    /// @relatesalso RGraphBuilder
    RGraph(const RGraphBuilder& gbuilder);
public:
    void Print() const;
    int MinPath(IndexType start_idx, IndexType end_idx, EGMinPathMod AlgMod) const;
    /// @todo �ּ�/�ִ� ����ġ���� �Ϲ�ȭ�Ͽ� �ִ� �켱����(?) ��η� �ٲ� �� ���� ��
private:
    /// @short Kruskal's Algorithm���� �ּ� ����ġ�� ���
    int MinPath_Kruskal() const;
    /// @short Dijkstra's Algorithm���� �ּ� ����ġ�� ���
    int MinPath_Dijkstra(IndexType start_idx, IndexType end_idx) const;
private:
    /// @short ����(Vertex)�� ����
    std::vector<int> vertices;
    /// @short ���� ����Ʈ
    std::vector<std::vector<std::pair<IndexType, WeightType>>> adj_list;
};

#endif // !_GRAPH_H
