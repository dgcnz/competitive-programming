#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/graphs/graph>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll  = long long;
using ii  = pair<int, int>;
using iii = tuple<int, int, int>;
using vi  = vector<int>;

vi solve(vector<string> board, vi s)
{
    int n = board.size(), m = board[0].size(), p = s.size();

    vector<queue<iii>> q(p);
    vector<vi>         color(n, vi(m, -1));
    vector<int>        ans(p, 0);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            char c = board[i][j];
            if ('1' <= c and c <= '9')
                q[c - '1'].emplace(i, j, 0), ans[c - '1']++;
        }
    }

    bool       change = true;
    vector<ii> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    auto       valid = [&](int i, int j) {
        return 0 <= i and i < n and 0 <= j and j < m and color[i][j] == -1 and
               board[i][j] == '.';
    };
    do
    {
        change = false;
        for (int k = 0; k < p; ++k)
        {
            queue<iii> new_queue;
            while (!q[k].empty())
            {
                auto [i, j, d] = q[k].front();
                q[k].pop();
                for (auto [di, dj] : directions)
                {
                    if (valid(i + di, j + dj))
                    {
                        color[i + di][j + dj] = k;
                        ans[k]++;
                        if (d + 1 == s[k])
                            new_queue.emplace(i + di, j + dj, 0);
                        else
                            q[k].emplace(i + di, j + dj, d + 1);
                    }
                }
            }
            swap(q[k], new_queue);
            change |= q[k].size();
        }
    } while (change);
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m, p;
    cin >> n >> m >> p;

    vi s(p);
    read(all(s));

    vector<string> board(n);
    read(all(board));

    auto ans = solve(board, s);
    write(all(ans), " "), cout << endl;
    return 0;
}
