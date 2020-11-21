---
layout: post
mathjax: true
title: 850B Arpa List Numbers
url: None
tags: None
time_complexity: None
memory_complexity: None
---

{% raw %}
None
{% endraw %}

```cpp
{% raw %}
const int TAMAX = 2e6 + 22;
using namespace std;
using ll = long long;
using vll = vector<ll>;
ll n, x, y;
vll a, acc_sum(TAMAX, 0), acc_cnt(TAMAX, 0);
inline ll cnt(int l, int r)
{
    if (r < l)
        return 0;
    return acc_cnt[r] - (l <= 0 ? 0 : acc_cnt[l - 1]);
}
inline ll sum(int l, int r)
{
    if (r < l)
        return 0;
    return acc_sum[r] - (l <= 0 ? 0 : acc_sum[l - 1]);
}
ll cost(ll p)
{
    ll local_ans = 0, local_inc_cost, local_del_cost;
    ll rel_border = min(p - 1, x / y);
    for (ll j = p; j < TAMAX; j += p)
    {
        ll border = j - rel_border;
        local_del_cost = x * cnt(j - p + 1, border - 1);
        local_inc_cost = y * (j * cnt(border, j - 1) - sum(border, j - 1));
        local_ans += local_inc_cost + local_del_cost;
    }
    return local_ans;
}
ll solve(void)
{
    ll ans = x * n;
    for (ll p = 2; p < TAMAX; ++p)
        ans = min(ans, cost(p));
    return ans;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x >> y;
    a = vll(n);
    for (auto &x : a)
    {
        cin >> x;
        ++acc_cnt[x];
        acc_sum[x] += x;
    }
    for (int i = 1; i < TAMAX; ++i)
    {
        acc_cnt[i] += acc_cnt[i - 1];
        acc_sum[i] += acc_sum[i - 1];
    }
    cout << solve() << endl;
    return 0;
}

{% endraw %}
```
