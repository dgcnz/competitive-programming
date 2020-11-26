#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int const NMAX = 1e2 + 11;

int    n, m;
char   mat[NMAX][NMAX];
bool   vis[NMAX][NMAX];
string s = "ALLIZZWELL";

// N, NW, W, WS, S, SE, E, EN

int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

inline bool in_bounds(int r, int c)
{
    return 0 <= r and r < n and 0 <= c and c < m;
}

bool backtrack(int r, int c, int i)
{
    if (i == isz(s))
        return true;
    if (vis[r][c])
        return false;
    if (s[i] != mat[r][c])
        return false;

    vis[r][c] = true;
    // dbg(s[i]);
    // dbg(r);
    // dbg(c);
    bool ans = false;
    for (int ix = 0; ix < 8; ++ix)
    {
        int rr = r + dr[ix], cc = c + dc[ix];
        if (in_bounds(rr, cc) and backtrack(rr, cc, i + 1))
        {
            ans = true;
            break;
        }
    }

    vis[r][c] = false;
    return ans;
}

bool solve(void)
{
    for (int r = 0; r < n; ++r)
        for (int c = 0; c < m; ++c)
            if (backtrack(r, c, 0))
                return true;
    return false;
}

int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        for (int r = 0; r < n; ++r)
            for (int c = 0; c < m; ++c)
                cin >> mat[r][c];

        cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}
