---
layout: post
mathjax: true
title: 1469D - Ceil Divisions
problem_url: https://codeforces.com/contest/1469/problem/D
tags: constructive, math
memory_complexity: O(n)
time_complexity: O(n)
---

[Editorial](https://codeforces.com/blog/entry/86082).


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
inline int ceil(int a, int b) { return (a + b - 1) / b; }
int bs(int l, int r, function<bool(int)> p)
{
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (p(m))
            r = m;
        else
            l = m + 1;
    }
    return l;
}
void solve(int n, vector<ii> &ans)
{
    if (n == 2)
        return;
    int i = bs(1, n - 1, [n](int x) { return x >= ceil(n, x); });
    for (int j = i + 1; j < n; ++j)
        ans.emplace_back(j, n);
    ans.emplace_back(n, i);
    ans.emplace_back(n, i);
    solve(i, ans);
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ii> ans;
        solve(n, ans);
        cout << ans.size() << endl;
        for (auto [x, y] : ans)
            cout << x << " " << y << endl;
        cout << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

