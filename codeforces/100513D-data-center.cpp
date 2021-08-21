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

pair<vi, int> solve(vector<tuple<ll, bool, int>> servers, ll m)
{
    sort(all(servers));
    reverse(all(servers));
    vector<pair<ll, int>> volt[2];

    ll sum = 0, sum_taken = 0;
    for (auto [a, l, ix] : servers)
    {
        if (sum_taken >= m and l)
        {
            if (volt[0].size() and sum_taken - volt[0].back().first + a >= m)
            {
                sum_taken -= volt[0].back().first;
                sum_taken += a;
                volt[0].pop_back();
                volt[1].emplace_back(a, ix);
            }
        }
        else if (sum_taken < m)
            volt[l].emplace_back(a, ix), sum_taken += a;
        sum += a;
    }
    int k = volt[1].size();
    vi  ans;
    for (int i = 0; i < 2; ++i)
        for (auto [a, ix] : volt[i])
            ans.push_back(ix + 1);
    return {ans, k};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    ll  m;
    cin >> n >> m;
    vector<tuple<ll, bool, int>> servers(n);
    for (int i = 0; i < n; ++i)
    {
        auto &[a, l, ix] = servers[i];
        cin >> a >> l;
        ix = i;
    }
    auto [ans, k] = solve(servers, m);
    cout << ans.size() << " " << k << endl;
    write(all(ans), " "), cout << endl;
    return 0;
}
