#include <bits/stdc++.h>

using namespace std;
using ll   = long long;
using ii   = pair<int, int>;
using iii  = tuple<int, int, int>;
using siii = set<iii>;

const int NMAX = 30 + 1;

int  n, m;
bool mat[NMAX][NMAX];

vector<ii> dup   = {{-1, 0}, {0, -1}}; // left, up
vector<ii> ddown = {{1, 0}, {0, 1}};   // down, right

bool valid(int i, int j) { return 0 <= i and i < n and 0 <= j and j < m; }

vector<iii> neighbors(iii a)
{
    vector<iii> ans;
    auto [i, j, dir] = a;

    if (dir) // up
    {
        for (auto [di, dj] : dup)
            if (valid(i + di, j + dj))
                ans.push_back({i + di, j + dj, dir});
    }
    else // down
    {
        for (auto [di, dj] : ddown)
            if (valid(i + di, j + dj))
                ans.push_back({i + di, j + dj, dir});
    }

    return ans;
}

int main(void)
{
    int t, len, ones, zeros;
    ll  ans;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        ans = 0;
        len = n + m - 1;

        siii current;
        siii next;
        current.insert({0, 0, 0});
        current.insert({n - 1, m - 1, 1});

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> mat[i][j];

        for (int i = 0; i < len / 2; ++i)
        {
            zeros = 0;
            ones  = 0;
            for (auto elem : current)
            {
                if (mat[get<0>(elem)][get<1>(elem)] == 1)
                    ++ones;
                else
                    ++zeros;
                for (auto neigh : neighbors(elem))
                    next.insert(neigh);
            }
            ans += min(zeros, ones);
            current = next;
            next.clear();
        }

        cout << ans << endl;
    }

    return 0;
}
