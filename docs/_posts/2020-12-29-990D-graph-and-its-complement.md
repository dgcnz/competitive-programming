---
layout: post
mathjax: true
title: 990D - Graph And Its Complement
problem_url: https://codeforces.com/problemset/problem/990/D
tags: graphs, constructive, implementation
memory_complexity: O(n^2)
time_complexity: O(n^2)
---

[Editorial](https://codeforces.com/blog/entry/59962).


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
pair<bool, vector<vi>> solve(int n, int a, int b)
{
    if (min(a, b) != 1 or (a == b and (n == 2 or n == 3)))
        return {false, {}};
    vector<vi> ans(n, vi(n, 0));
    bool rev = false;
    if (a < b)
    {
        rev = true;
        swap(a, b);
    }
    for (int i = 0; i < n - a; ++i)
        ans[i][i + 1] = ans[i + 1][i] = 1;
    if (rev)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                    continue;
                ans[i][j] = 1 - ans[i][j];
            }
        }
    }
    return {true, ans};
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, a, b;
    cin >> n >> a >> b;
    if (auto [flag, mat] = solve(n, a, b); flag)
    {
        cout << "YES" << endl;
        for (auto row : mat)
        {
            for (auto x : row)
                cout << x;
            cout << endl;
        }
    }
    else
        cout << "NO" << endl;
    return 0;
}

{% endraw %}
```
</details>

