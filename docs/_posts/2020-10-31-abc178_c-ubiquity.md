---
layout: post
mathjax: true
title: Abc178_C Ubiquity
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---



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
ll const MOD = 1e9 + 7;
ll binpow(ll a, ll b)
{
    a %= MOD;
    ll ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}
ll sub(ll a, ll b) { return ((a + MOD % MOD) - (b + MOD % MOD) + MOD) % MOD; }
ll add(ll a, ll b) { return ((a + MOD % MOD) + (b + MOD % MOD)) % MOD; }
int main(void)
{
    ll n;
    cin >> n;
    ll U = binpow(10, n);
    ll Z = binpow(9, n);
    ll N = binpow(9, n);
    ll ZuN = binpow(8, n);
    ll ans = sub(U, sub(add(Z, N), ZuN));
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
</details>

