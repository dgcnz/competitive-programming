---
layout: post
mathjax: true
title: abc151_e - Max Min Sum
problem_url: https://atcoder.jp/contests/abc151/tasks/abc151_e
tags: combinatorics, counting, contribution
memory_complexity: O(n)
time_complexity: O(n \log{n})
---

Assume the array $A$ is sorted.

Note that each $a_i$ will be counted as a maximum element $C(i - 1, k - 1)$
times. Conversely, it will be counted $C(n - i, k - 1)$ times as minimum.


{% if page.time_complexity != "None" %}
Time complexity: ${{ page.time_complexity }}$
{% endif %}

{% if page.memory_complexity != "None" %}
Memory complexity: ${{ page.memory_complexity }}$
{% endif %}

<details>
<summary>
<p style="display:inline">Click to show code.</p>
</summary>
```cpp
{% raw %}
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
template <int NMAX, typename mint>
struct Combinations
{
    std::vector<mint> fact, inv_fact;
    Combinations(void) { precompute(NMAX + 1); }
    void precompute(int len)
    {
        fact.resize(len), inv_fact.resize(len);
        inv_fact[0] = fact[0] = 1;
        for (int i = 1; i < len; i++)
        {
            inv_fact[i] = inv_fact[i - 1] * mint(i).inv();
            fact[i] = fact[i - 1] * i;
        }
    }
    mint C(int n, int k) const
    {
        assert(int(fact.size()) > n);
        if (k > n or k < 0)
            return 0;
        return fact[n] * inv_fact[k] * inv_fact[n - k];
    }
    mint factorial(int n)
    {
        assert(int(fact.size()) > n);
        return fact[n];
    }
    mint inverse_factorial(int n)
    {
        assert(int(fact.size()) > n);
        return inv_fact[n];
    }
    mint operator()(int n, int k) const { return C(n, k); }
};
ll solve(vector<ll> a, int k)
{
    using mint = atcoder::modint1000000007;
    int const NMAX = 1e5 + 1;
    int n = a.size();
    sort(begin(a), end(a));
    Combinations<NMAX, mint> C;
    mint ans = 0;
    for (int i = 0; i < n; ++i)
        ans += a[i] * C(i, k - 1) - a[i] * C(n - i - 1, k - 1);
    return ans.val();
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &ai : a)
        cin >> ai;
    cout << solve(a, k) << endl;
    return 0;
}

{% endraw %}
```
</details>

