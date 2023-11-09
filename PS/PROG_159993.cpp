
#include "PROG.h"


/// @date 2023-11-09T17:30 18:24 (54)
/// ���α׷��ӽ� �̷� Ż�� L2
/*!
* 1x1 ĭ���� �̷���� ���簢�� ���� ������ �̷ο��� Ż���Ϸ��� �Ѵ�.
* �� ĭ�� ��� �Ǵ� ������ �����Ǿ� �ִ�. 
* ������ �� ĭ�� ������ �� ����.
* ��η� �� ĭ���θ� �̵��� �� �ִ�.
* ��ε� �� �� ĭ���� �̷θ� ���������� ���� �ִ�.
* �׷��� �� ���� ������ ��ܾ� ������, ���� ���� ��ε� �� �� ĭ�� �ִ�.
* ���� ��� ���� -> ������ �ִ� ĭ -> �ⱸ ĭ ���� �̵��ؾ��Ѵ�.
* ������ ����� �ʾҴ��� �ⱸ�� �ִ� ĭ�� ������ ���� �ִ�.
* �̷ο��� �� ĭ�� �̵��ϴµ� �ɸ��� �ð��� 1���̴�.
* 
* �̷��� ������ �־��� ��, �̷θ� ���������� ���� �ɸ��� �ּ��� �ð��� ���Ѵ�.
* Ż���� �� ������ -1�� �����Ѵ�.
* �̷��� ������ ���ڿ� ���� `maps` �̴�. ���̴� [5, 100]
* `S` ���� ���� `E` �ⱸ `L` ���� `O` ��� `X` ��
* `S`, `E`, `L` �� �׻� �ٸ� ���� �����ϸ� �ϳ��� �����Ѵ�.
* ��� `S`, `E`, `L`�� ���� �� ������ �� �ִ�.
*/

#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

enum class CellType { Start, Exit, Lever, Path, Wall, None };
const map<char, CellType> CTOT =
{
    {'S', CellType::Start},
    {'E', CellType::Exit},
    {'L', CellType::Lever},
    {'O', CellType::Path},
    {'X', CellType::Wall},
};

struct Cell
{
    Cell() {};
    Cell(const char& ctype_char): type(::CTOT.at(ctype_char)) { };
    bool is_wall() const { return type == CellType::Wall; }
    CellType type = CellType::None;
};

typedef size_t IndexType;
typedef int DistanceType;
typedef DistanceType TimeType;

class Maze
{
public:
    Maze(const vector<string>& maps, size_t i_size, size_t j_size): 
        cells(i_size * j_size), 
        i_size(i_size), 
        j_size(j_size),
        adj_list(cells.size())
    {
        // Make Cells
        for (size_t i = 0; i < i_size; ++i)
            for (size_t j = 0; j < j_size; ++j)
                cells[toidx(i, j)].type = ::CTOT.at(maps[i][j]);

        // Tie Cells
        for (size_t i = 0; i < i_size; ++i)
        {
            for (size_t j = 0; j < j_size; ++j)
            {
                if (cells[toidx(i, j)].is_wall()) 
                    continue;
                switch (cells[toidx(i, j)].type)
                {
                case CellType::Start: idx_start = toidx(i, j); break;
                case CellType::Lever: idx_lever = toidx(i, j); break;
                case CellType::Exit: idx_exit = toidx(i, j); break;
                default: break;
                }

                const IndexType up = i - 1;
                const IndexType down = i + 1;
                const IndexType left = j - 1;
                const IndexType right = j + 1;

                if (i > 0 && !cells[toidx(up, j)].is_wall())
                    adj_list[toidx(i, j)].push_back(toidx(up, j));
                if (i < i_size - 1 && !cells[toidx(down, j)].is_wall())
                    adj_list[toidx(i, j)].push_back(toidx(down, j));
                if (j > 0 && !cells[toidx(i, left)].is_wall())
                    adj_list[toidx(i, j)].push_back(toidx(i, left));
                if (j < j_size - 1 && !cells[toidx(i, right)].is_wall())
                    adj_list[toidx(i, j)].push_back(toidx(i, right));
            }
        }
    }
    inline IndexType toidx(IndexType i, IndexType j) { return j + i * j_size; }

    TimeType get_minimum_exit_time() const
    {
        int stol = bfs_distance(idx_start, idx_lever);

        if (stol == -1) return -1;

        int ltoe = bfs_distance(idx_lever, idx_exit);

        if (ltoe == -1) return -1;

        return stol + ltoe;
    }

    DistanceType bfs_distance(IndexType bfs_start, IndexType bfs_end) const
    {
        // Initial Queue
        queue<IndexType> to_visit;
        to_visit.push(bfs_start);

        // Initial Visited
        vector<bool> visited(cells.size(), false); 
        visited[to_visit.front()] = true;

        // Initial Distance
        vector<DistanceType> distance(cells.size(), -1); 
        distance[bfs_start] = 0;

        return bfs_distance_recur(to_visit, visited, distance, bfs_end);
    }
    DistanceType bfs_distance_recur(queue<IndexType>& to_visit, vector<bool> visited, vector<DistanceType>& distance, IndexType& bfs_recur_end) const
    {
        auto ccell_idx = to_visit.front(); 
        to_visit.pop();

        if (ccell_idx == bfs_recur_end) 
            return distance[ccell_idx];

        for (auto& adj_ccell_idx : adj_list[ccell_idx])
        {
            if (visited[adj_ccell_idx]) continue;
            visited[adj_ccell_idx] = true;
            to_visit.push(adj_ccell_idx);
            distance[adj_ccell_idx] = distance[ccell_idx] + 1;
        } 

        if (to_visit.empty()) return -1;

        return bfs_distance_recur(to_visit, visited, distance, bfs_recur_end);
    }

private:
    vector<Cell> cells;
    vector<vector<IndexType>> adj_list;

    IndexType idx_start;
    IndexType idx_lever;
    IndexType idx_exit;

    size_t i_size;
    size_t j_size;
};

int solution(vector<string> maps)
{
    const size_t i_size = maps.size();
    const size_t j_size = maps.front().size();

    Maze mz(maps, i_size, j_size);
    return mz.get_minimum_exit_time();
}

int main()
{
    Solver<vector<string>, int> s =
    {
        {
            { {"SOOOL","XXXXO","OOOOO","OXXXX","OOOOE"}, 16},
            { {"LOOXS","OOOOX","OOOOO","OOOOO","EOOOO"}, -1},
            { {"ESL"} , 3},
            { {"E", "S", "L"} , 3}
        }
    }; s();
    return 0;
}




/// @date 2023-11-09T15:36 18:24
