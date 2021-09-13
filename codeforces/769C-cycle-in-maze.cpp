#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

struct Direction
{
    int const first;
    int const second;

    constexpr bool operator==(Direction const &other) const
    {
        return first == other.first and second == other.second;
    }
    constexpr bool operator!=(Direction const &other) const
    {
        return first != other.first or second != other.second;
    }

    constexpr Direction opposite() const { return Direction{-first, -second}; }
    constexpr friend pair<int, int> operator+(pair<int, int> const &a,
                                              Direction const &     b)
    {
        return make_pair(a.first + b.first, a.second + b.second);
    }

    static const Direction UP;
    static const Direction RIGHT;
    static const Direction DOWN;
    static const Direction LEFT;
};

char dir_to_char(Direction const &dir)
{
    if (dir == Direction::UP)
        return 'U';
    if (dir == Direction::RIGHT)
        return 'R';
    if (dir == Direction::DOWN)
        return 'D';
    if (dir == Direction::LEFT)
        return 'L';
    throw std::runtime_error("Unrecognized standard direction character.");
}

Direction char_to_dir(char c)
{
    switch (c)
    {
    case 'U':
        return Direction::UP;
    case 'R':
        return Direction::RIGHT;
    case 'D':
        return Direction::DOWN;
    case 'L':
        return Direction::LEFT;
    default:
        throw std::runtime_error("Unrecognized standard direction.");
    };
}

Direction const Direction::UP    = {-1, 0};
Direction const Direction::RIGHT = {0, +1};
Direction const Direction::DOWN  = {+1, 0};
Direction const Direction::LEFT  = {0, -1};

string solve(vector<string> table, int k)
{
    int n = table.size(), m = table.back().size();
    if (k % 2)
        return "IMPOSSIBLE";

    // vector<vector<bool>> vis(n, vector<bool>(m, false));

    vector<Direction> directions = {
        Direction::DOWN, Direction::LEFT, Direction::RIGHT, Direction::UP};

    vector<Direction> ans;
    ans.reserve(k);

    auto in_range = [&](ii u)
    { return 0 <= u.first and u.first < n and 0 <= u.second and u.second < m; };
    auto is_free = [&](ii u) { return table[u.first][u.second] != '*'; };

    ii src;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (table[i][j] == 'X')
                src = {i, j};

    vector<vi> dist(n, vi(m));
    vector<vi> vis(n, vi(m, 0));
    queue<ii>  frontier;
    dist[src.first][src.second] = 0;
    vis[src.first][src.second]  = 1;
    frontier.push(src);

    while (not frontier.empty())
    {
        auto u = frontier.front();
        frontier.pop();

        for (auto dir : directions)
        {
            auto v = u + dir;
            if (in_range(v) and is_free(v) and not vis[v.first][v.second])
            {
                dist[v.first][v.second] = dist[u.first][u.second] + 1;
                vis[v.first][v.second]  = true;
                frontier.push(v);
            }
        }
    }

    function<bool(ii, int)> dfs = [&](ii u, int d = 0)
    {
        if (d == k and u == src)
            return true;
        for (auto dir : directions)
        {
            auto v = u + dir;
            ans.push_back(dir);
            if (in_range(v) and is_free(v) and
                d + dist[v.first][v.second] <= k and dfs(v, d + 1))
                return true;
            ans.pop_back();
        }
        return false;
    };

    if (not dfs(src, 0))
        return "IMPOSSIBLE";

    string str_ans;
    transform(all(ans), back_inserter(str_ans), dir_to_char);
    return str_ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> table(n);
    read(all(table));

    cout << solve(table, k) << endl;

    return 0;
}
