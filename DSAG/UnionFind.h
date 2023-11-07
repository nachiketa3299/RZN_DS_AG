#ifndef _UNION_FIND_H
#define _UNION_FIND_H

#include <vector>

typedef std::size_t IndexType;

class RUnionFind
{
public:

    /// @short ���� ��ŭ�� ��带 ���� ���Ͽ�-���ε� ������ �����. �� ��带 ���� ������ ������ �ʱ�ȭ�Ѵ�.
    /// @param[in] n ����� ����
    RUnionFind(IndexType n);

    /// @short �� ����� ��ȣ�� �޾Ƽ�, �� ��尡 ���� ��Ʈ�� �����ϴ��� �˻��Ѵ�.
    /// @param[in] ni1 ù ��° ����� �ε���
    /// @param[in] ni2 �� ��° ����� �ε���
    /// @return �� ��尡 ���� ��Ʈ�� �����ϴ����� ����
    bool NodesHaveSameLastParent(IndexType ni1, IndexType ni2) const;

    /// @short �� ��° ���ڷ� ���޵� ����� �θ� ù ��° ���� �����Ѵ�.
    /// @param[in] ni1 ù ��° ����� �ε���
    /// @param[in] ni2 �� ��° ����� �ε���
    void MergeNodes(IndexType ni1, IndexType ni2);

    /// @short ���ڷ� ���޵� ����� ���� �θ� ��������� ã�´�. �� ��, ���� �θ�� ��� ��ȣ�� �θ��� ��ȣ�� ���� ����̴�.
    /// @param[in] ni ��Ʈ ��带 ã�� ����� �ε���
    /// @return ��Ʈ ����� �ε���
    IndexType FindLastParentNode(IndexType ni) const;

private:
    /// @short �� ����� �θ��� ��ȣ�� �����ϴ� ����.
    std::vector<IndexType> node_parents;
};

#endif // !_UNION_FIND_H
