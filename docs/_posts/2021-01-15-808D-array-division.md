---
layout: post
mathjax: true
title: 808D - Array Division
problem_url: https://codeforces.com/contest/808/problem/D
tags: greedy, binary_search, implementation
memory_complexity: O(n)
time_complexity: O(n \log{n})
---

[Editorial](https://codeforces.com/blog/entry/52010).


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
bool solve(vi a)
{
    ll target = accumulate(begin(a), end(a), 0LL);
    if (target & 1)
        return false;
    target /= 2;
    for (int i = 0; i < 2; ++i)
    {
        ll sum = 0;
        set<ll> unique;
        for (auto ai : a)
        {
            sum += ai;
            unique.insert(ai);
            if (unique.find(sum - target) != unique.end())
                return true;
        }
        reverse(begin(a), end(a));
    }
    return false;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    for (auto &ai : a)
        cin >> ai;
    cout << (solve(a) ? "YES" : "NO") << endl;
    return 0;
}

{% endraw %}
```
</details>

