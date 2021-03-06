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

int const       N     = 7;
int const       MOVES = 48;
bitset<4> const HORIZONTAL_T(string("1100"));
bitset<4> const VERTICAL_T(string("0011"));

string s;
bool   visited[N][N];

vector<ii> const directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

inline bool in_bounds(int r, int c)
{
    return 0 <= r and r < N and 0 <= c and c < N;
}

inline bool valid(int r, int c)
{
    return in_bounds(r, c) and not visited[r][c];
}

bool tform(int r, int c, char dir)
{
    switch (dir)
    {
    case 'U':
        return not valid(r - 2, c) and valid(r - 1, c - 1) and
               valid(r - 1, c + 1);
    case 'D':
        return not valid(r + 2, c) and valid(r + 1, c - 1) and
               valid(r + 1, c + 1);
    case 'L':
        return not valid(r, c - 2) and valid(r + 1, c - 1) and
               valid(r - 1, c - 1);
    case 'R':
        return not valid(r, c + 2) and valid(r + 1, c + 1) and
               valid(r - 1, c + 1);
    default:
        return false;
    }
}

inline bool goal(int r, int c) { return r == N - 1 and c == 0; }

ll backtrack(int r, int c, int ix)
{
    if (goal(r, c) and ix != MOVES)
        return 0;
    if (ix == MOVES)
        return goal(r, c);

    ll ans        = 0;
    visited[r][c] = true;

    if (s[ix] == '?' or s[ix] == 'L')
        if (valid(r, c - 1) and not tform(r, c, 'L'))
            ans += backtrack(r, c - 1, ix + 1);
    if (s[ix] == '?' or s[ix] == 'R')
        if (valid(r, c + 1) and not tform(r, c, 'R'))
            ans += backtrack(r, c + 1, ix + 1);
    if (s[ix] == '?' or s[ix] == 'U')
        if (valid(r - 1, c) and not tform(r, c, 'U'))
            ans += backtrack(r - 1, c, ix + 1);
    if (s[ix] == '?' or s[ix] == 'D')
        if (valid(r + 1, c) and not tform(r, c, 'D'))
            ans += backtrack(r + 1, c, ix + 1);

    visited[r][c] = false;
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> s;
    cout << backtrack(0, 0, 0) << endl;
    return 0;
}
