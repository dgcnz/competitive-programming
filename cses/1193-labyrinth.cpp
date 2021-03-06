#include <bits/stdc++.h>
using namespace std;
using ii  = pair<int, int>;
using iic = tuple<int, int, char>;

const int NMAX = 1e3 + 11;

iic  directions[4] = {{1, 0, 'D'}, {-1, 0, 'U'}, {0, 1, 'R'}, {0, -1, 'L'}};
ii   start, target;
char lab[NMAX][NMAX];
bool visited[NMAX][NMAX];
int  n, m;

inline bool valid(int row, int col)
{
    return (row >= 0 and row < n and col >= 0 and col < m and
            lab[row][col] != '#');
}

void reconstruct_path(ii x, const map<ii, pair<ii, char>> &parent)
{
    ii     end = x;
    string res = "";
    do
    {
        res += parent.at(end).second;
        end = parent.at(end).first;
    } while (end != start);

    reverse(res.begin(), res.end());
    cout << "YES" << endl;
    cout << res.length() << endl;
    cout << res << endl;
}

void bfs(void)
{
    list<ii>                q;
    map<ii, pair<ii, char>> parent;

    visited[start.first][start.second] = 1;
    q.push_back(start);

    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop_front();

        for (auto [di, dj, dir] : directions)
        {
            if (valid(i + di, j + dj) and !visited[i + di][j + dj])
            {
                ii x      = {i + di, j + dj};
                parent[x] = {{i, j}, dir};

                if (x == target)
                {
                    reconstruct_path(x, parent);
                    return;
                }

                visited[i + di][j + dj] = true;
                q.push_back(x);
            }
        }
    }

    cout << "NO" << endl;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> lab[i][j];
            if (lab[i][j] == 'A')
                start = {i, j};
            else if (lab[i][j] == 'B')
                target = {i, j};
        }
    }

    bfs();

    return 0;
}
