---
layout: post
mathjax: true
title: 519D A B Interesting Substrings
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
const int CMAX = 26;
map<ll, ll> m[CMAX + 1];
int x[CMAX + 1];
ll solve(string s)
{
    int n = s.size(), cur;
    ll ans = 0, sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cur = s[i] - 'a';
        ans += m[cur][sum];
        sum += x[cur];
        ++m[cur][sum];
    }
    return ans;
}
int main(void)
{
    string s;
    for (int i = 0; i < CMAX; ++i)
        cin >> x[i];
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}

{% endraw %}
```
</details>

