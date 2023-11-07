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

    /// 이미 최종 부모 노드가 같다면 병합할 필요가 없다.
    if (last_parent_n1 == last_parent_n2)
        return;
    /// 최종 부모 노드가 다르다면 두 번째 인자로 전달된 노드의 부모를 첫 번째 인자로 전달된 노드의 최종 부모 노드로 설정한다.
    /// 이로써 두 노드는 같은 최종 부모를 공유하게 된다.

    if (last_parent_n1 < last_parent_n2) this->node_parents[last_parent_n1] = last_parent_n2;
    else                                 this->node_parents[last_parent_n2] = last_parent_n1;
    return;
}

IndexType RUnionFind::FindLastParentNode(IndexType ni) const
{
    const auto& parent_n = this->node_parents[ni];
    /// 언젠가 최종 부모 노드에 도달했다면 노드의 번호와 부모 노드의 번호가 같을 것이다.
    if (ni == parent_n)
        return parent_n;
    /// 다르다면, 자신의 부모 노드로 재귀 호출을 한다.
    return this->FindLastParentNode(parent_n);
}
