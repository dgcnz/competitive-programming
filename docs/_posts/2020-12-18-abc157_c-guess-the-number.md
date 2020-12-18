---
layout: post
mathjax: true
title: abc157_c - Guess The Number
problem_url: https://atcoder.jp/contests/abc157/tasks/abc157_c
tags: implementation, greedy
memory_complexity: O(n)
time_complexity: O(m + n)
---

Implement statement and handle edge cases. Fill every unknown space with a
$0$ if it's not the first digit ($1$ in that case).


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
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vi s(n, -1);
    bool flag = true;
    while (m--)
    {
        int i, c;
        cin >> i >> c, i--;
        if (s[i] != -1 and s[i] != c)
            flag = false;
        if (i == 0 and c == 0 and n != 1)
            flag = false;
        s[i] = c;
    }
    if (flag)
    {
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == -1)
                s[i] = (i == 0 and n != 1);
            cout << s[i];
        }
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

