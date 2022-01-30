#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/segtree>
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

template <typename F, typename S, class Compare = std::less<S>>
struct by_second
{
    Compare cmp;
    by_second(Compare cmp = std::less<S>()) : cmp(cmp) {}
    bool operator()(pair<F, S> a, pair<F, S> b)
    {
        return cmp(a.second, b.second);
    }
};

int solve(vector<ii> robbers, vector<ii> searchlights)
{
    vector<ii> delta;
    for (auto [a, b] : robbers)
        for (auto [c, d] : searchlights)
            delta.emplace_back(c - a, d - b);

    sort(all(delta));
    int dy = 0, ans = 1e9;
    for (int dx = 1e6 + 10; dx >= 0; dx--)
    {
        while (delta.size() and delta.back().first == dx)
        {
            dy = max(dy, delta.back().second + 1);
            delta.pop_back();
        }
        ans = min(ans, dx + dy);
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<ii> robbers(n), searchlights(m);
    for (auto &[x, y] : robbers)
        cin >> x >> y;
    for (auto &[x, y] : searchlights)
        cin >> x >> y;

    cout << solve(robbers, searchlights) << endl;
    return 0;
}
