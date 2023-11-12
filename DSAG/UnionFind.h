/// @file UnionFind.h
/// @author RZN

#ifndef _UNION_FIND_H
#define _UNION_FIND_H

#include <vector>
#include "DSAG_Types.h"


/// @class RUnionFind
/// @brief ���Ͽ�-���ε� ������ ������ �ִ� Ŭ�����̴�.
class RUnionFind
{
public:

    /// @short ���� ��ŭ�� ��带 ���� ���Ͽ�-���ε� ������ �����. �� ��带 ���� ������ ������ �ʱ�ȭ�Ѵ�.
    /// @param[in] n ����� ����
    RUnionFind(IndexType n);

    /// @short �� ����� �ε����� �޾Ƽ�, �� ��尡 ���� ��Ʈ�� �����ϴ��� �˻��Ѵ�.
    /// @param[in] ni1 ù ��° ����� �ε���
    /// @param[in] ni2 �� ��° ����� �ε���
    /// @return �� ��尡 ���� ���� �θ� �����ϴ����� ����
    bool NodesHaveSameLastParent(IndexType ni1, IndexType ni2) const;

    /// @short �� ��° ���ڷ� ���޵� ����� �θ� ù ��° ���� �����Ѵ�.
    /// @param[in] ni1 ù ��° ����� �ε���
    /// @param[in] ni2 �� ��° ����� �ε���
    void UnionNodes(IndexType ni1, IndexType ni2);

    /// @short ���ڷ� ���޵� ����� ���� �θ� ��������� ã�´�. �� ��, ���� �θ�� ��� ��ȣ�� �θ��� ��ȣ�� ���� ����̴�.
    /// @param[in] ni ��Ʈ ��带 ã�� ����� �ε���
    /// @return ��Ʈ ����� �ε���
    IndexType FindLastParentNode(IndexType ni) const;

private:
    /// @short �� ����� �θ��� ��ȣ�� �����ϴ� ����.
    std::vector<IndexType> parent;
};

#endif // !_UNION_FIND_H
