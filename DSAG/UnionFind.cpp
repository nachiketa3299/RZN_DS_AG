#include "UnionFind.h"

RUnionFind::RUnionFind(IndexType n): node_parents(n)
{
    for (size_t ni = 0; ni < n; ++ni)
        node_parents[ni] = ni;
    return;
}

bool RUnionFind::NodesHaveSameLastParent(IndexType ni1, IndexType ni2) const
{
    const IndexType& last_parent_n1 = this->FindLastParentNode(ni1);
    const IndexType& last_parent_n2 = this->FindLastParentNode(ni2);
    if (last_parent_n1 == last_parent_n2)
        return true;
    return false;
}

void RUnionFind::MergeNodes(IndexType ni1, IndexType ni2)
{
    const IndexType& last_parent_n1 = this->FindLastParentNode(ni1);
    const IndexType& last_parent_n2 = this->FindLastParentNode(ni2);

    /// �̹� ���� �θ� ��尡 ���ٸ� ������ �ʿ䰡 ����.
    if (last_parent_n1 == last_parent_n2)
        return;
    /// ���� �θ� ��尡 �ٸ��ٸ� �� ��° ���ڷ� ���޵� ����� �θ� ù ��° ���ڷ� ���޵� ����� ���� �θ� ���� �����Ѵ�.
    /// �̷ν� �� ���� ���� ���� �θ� �����ϰ� �ȴ�.

    if (last_parent_n1 < last_parent_n2) this->node_parents[last_parent_n1] = last_parent_n2;
    else                                 this->node_parents[last_parent_n2] = last_parent_n1;
    return;
}

IndexType RUnionFind::FindLastParentNode(IndexType ni) const
{
    const auto& parent_n = this->node_parents[ni];
    /// ������ ���� �θ� ��忡 �����ߴٸ� ����� ��ȣ�� �θ� ����� ��ȣ�� ���� ���̴�.
    if (ni == parent_n)
        return parent_n;
    /// �ٸ��ٸ�, �ڽ��� �θ� ���� ��� ȣ���� �Ѵ�.
    return this->FindLastParentNode(parent_n);
}
