---
layout: post
mathjax: true
title: 102433E - Rainbow Strings
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
const int MOD = 11092019;
const int ALPHSZ = 26;
ll freq[ALPHSZ];
inline ll m(ll a, ll b) { return (a % MOD * b % MOD) % MOD; }
inline ll p(ll a, ll b) { return (a % MOD + b % MOD) % MOD; }
int main(void)
{
    int n;
    string s;
    ll ans;
    cin >> s;
    n = (int)s.size();
    for (int i = 0; i < n; i++)
        freq[s[i] - 'a']++;
    ans = 0;
    for (int i = 0; i < ALPHSZ; ++i)
    {
        ans = p(ans, p(m(ans, freq[i]), freq[i]));
    }
    cout << ans + 1 << endl;
    return 0;
}

{% endraw %}
```
</details>

