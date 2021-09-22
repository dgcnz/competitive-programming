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
using ll  = long long;
using ii  = pair<int, int>;
using iii = tuple<int, int, int>;
using vi  = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, x;
    cin >> n >> x;

    vector<iii> events(2 * n);
    vector<int> cost(n), start(n), finish(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> start[i] >> finish[i] >> cost[i];
        events.emplace_back(start[i], -1, i);
        events.emplace_back(finish[i], +1, i);
    }

    sort(all(events));

    map<int, int> dp; // least money for duration
    int const     INF = 2e9 + 11;
    int           ans = INF;
    for (auto [t, sign, ix] : events)
    {
        int d = finish[ix] - start[ix] + 1;
        if (sign == -1 and dp.find(x - d) != dp.end())
            ans = min(ans, dp[x - d] + cost[ix]);
        else if (sign == +1 and (dp.find(d) == dp.end() or dp[d] > cost[ix]))
            dp[d] = cost[ix];
    }

    if (ans == INF)
        ans = -1;

    cout << ans << endl;
    return 0;
}
