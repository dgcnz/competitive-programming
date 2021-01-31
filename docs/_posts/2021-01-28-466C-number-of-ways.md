---
layout: post
mathjax: true
title: 466C - Number Of Ways
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
using vll = vector<ll>;
int n;
vll psum;
ll solve(void)
{
    if (n < 3 or psum[n] % 3 != 0)
        return 0;
    ll target = psum[n] / 3;
    vll ix[3];
    for (int i = 1; i <= n; ++i)
        for (int k = 1; k <= 3; ++k)
            if (psum[i] == k * target)
                ix[k - 1].push_back(i);
    ll ans = 0;
    for (auto i0 : ix[0])
    {
        auto it1 = upper_bound(ix[1].begin(), ix[1].end(), i0);
        ans += max((ll)distance(it1, ix[1].end()) - (target == 0), 0LL);
    }
    return ans;
}
int main(void)
{
    cin >> n;
    psum.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        cin >> psum[i], psum[i] += psum[i - 1];
    cout << solve() << endl;
    return 0;
}

{% endraw %}
```
</details>

