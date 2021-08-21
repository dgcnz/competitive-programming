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

int solve(vector<vi> r)
{
    int n = r.size(), winner = 0;

    auto fight = [&](int i, int j)
    {
        int first_wins = 0;
        for (int k = 0; k < 5; ++k)
            if (r[i][k] < r[j][k])
                first_wins++;
        return first_wins >= 3 ? i : j;
    };

    for (int i = 1; i < n; ++i)
        winner = fight(winner, i);

    for (int i = 0; i < n; ++i)
        if (i != winner and fight(winner, i) != winner)
            return -1;

    return winner + 1;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> r(n, vi(5));
        for (auto &ri : r)
            read(all(ri));
        cout << solve(r) << endl;
    }
    return 0;
}
