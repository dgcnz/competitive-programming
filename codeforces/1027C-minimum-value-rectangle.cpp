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

int const AMAX = 1e4 + 2;

ii solve(map<int, int> const &cnt)
{
    vector<int> sticks;
    for (auto [a, c] : cnt)
    {
        if (c >= 4)
            return {a, a};
        else if (c >= 2)
            sticks.push_back(a);
    }

    int x = sticks[0], y = sticks[1];
    for (int i = 2, m = sticks.size(); i < m; ++i)
    {
        if (x * sticks[i] < y * sticks[i - 1])
            x = sticks[i - 1], y = sticks[i];
    }
    return {x, y};
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
        map<int, int> cnt;
        for (int i = 0; i < n; ++i)
        {
            int ai;
            cin >> ai;
            cnt[ai]++;
        }

        auto [x, y] = solve(cnt);
        cout << x << " " << x << " " << y << " " << y << "\n";
    }
    return 0;
}
