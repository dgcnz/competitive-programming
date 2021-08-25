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

pair<ll, vi> solve(vector<ll> a, int m, int k)
{
    int                   n = a.size();
    vector<pair<ll, int>> sorted;
    for (int i = 0; i < n; ++i)
        sorted.emplace_back(a[i], i);
    sort(all(sorted), greater<pair<ll, int>>());

    vector<bool> taken(n, false);
    ll           sum = 0;
    for (int i = 0; i < m * k; ++i)
    {
        sum += sorted[i].first;
        taken[sorted[i].second] = true;
    }

    int cnt = 0;
    vi  ans;
    for (int i = 0; i < n; ++i)
    {
        cnt += taken[i];
        if (cnt == m + 1)
        {
            ans.push_back(i - 1);
            cnt = 1;
        }
    }
    return {sum, ans};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    read(all(a));

    auto [sum, ans] = solve(a, m, k);
    cout << sum << endl;
    increment(all(ans));
    write(all(ans), " "), cout << endl;
    return 0;
}
