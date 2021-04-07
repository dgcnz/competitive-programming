#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

bool solve(int n, vi URDL, int i = 0)
{
    if (i == 4)
        return true;
    if (URDL[i] == 0)
        return solve(n, URDL, i + 1);

    bool ans = false;
    if (URDL[i] <= n - 2)
    {
        vi temp = URDL;
        URDL[i] = 0;
        ans |= solve(n, URDL, i + 1);
        URDL = temp;
    }

    int l = (i - 1 + 4) % 4, r = (i + 1) % 4;

    if (URDL[i] >= 2 and URDL[l] >= 1 and URDL[r] >= 1)
    {
        vi temp = URDL;
        URDL[i] = 0, URDL[l]--, URDL[r]--;
        ans |= solve(n, URDL, i + 1);
        URDL = temp;
    }

    if (URDL[i] >= 1 and URDL[i] <= n - 1 and URDL[l] >= 1)
    {
        vi temp = URDL;
        URDL[i] = 0, URDL[l]--;
        ans |= solve(n, URDL, i + 1);
        URDL = temp;
    }

    if (URDL[i] >= 1 and URDL[i] <= n - 1 and URDL[r] >= 1)
    {
        vi temp = URDL;
        URDL[i] = 0, URDL[r]--;
        ans |= solve(n, URDL, i + 1);
        URDL = temp;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, U, R, D, L;
        cin >> n >> U >> R >> D >> L;

        cout << (solve(n, {U, R, D, L}) ? "YES" : "NO") << endl;
    }
    return 0;
}
