/// @file UnionFind.h
/// @author RZN

#ifndef _UNION_FIND_H
#define _UNION_FIND_H

#include <vector>
#include "DSAG_Types.h"


/// @class RUnionFind
/// @brief 유니온-파인드 연산을 수행해 주는 클래스이다.
class RUnionFind
{
public:

    /// @short 인자 만큼의 노드를 가진 유니온-파인드 집합을 만든다. 각 노드를 서로 분절된 것으로 초기화한다.
    /// @param[in] n 노드의 갯수
    RUnionFind(IndexType n);

    /// @short 두 노드의 인덱스를 받아서, 두 노드가 같은 루트를 공유하는지 검사한다.
    /// @param[in] ni1 첫 번째 노드의 인덱스
    /// @param[in] ni2 두 번째 노드의 인덱스
    /// @return 두 노드가 같은 최종 부모를 공유하는지의 여부
    bool NodesHaveSameLastParent(IndexType ni1, IndexType ni2) const;

    /// @short 두 번째 인자로 전달된 노드의 부모를 첫 번째 노드로 병합한다.
    /// @param[in] ni1 첫 번째 노드의 인덱스
    /// @param[in] ni2 두 번째 노드의 인덱스
    void UnionNodes(IndexType ni1, IndexType ni2);

    /// @short 인자로 전달된 노드의 최종 부모를 재귀적으로 찾는다. 이 때, 최종 부모는 노드 번호와 부모의 번호가 같은 노드이다.
    /// @param[in] ni 루트 노드를 찾을 노드의 인덱스
    /// @return 루트 노드의 인덱스
    IndexType FindLastParentNode(IndexType ni) const;

private:
    /// @short 각 노드의 부모의 번호를 저장하는 벡터.
    std::vector<IndexType> parent;
};

#endif // !_UNION_FIND_H
