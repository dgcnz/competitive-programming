---
layout: post
mathjax: true
title: 1341C - Nastya Strange Generator
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
const int NMAX = 1e5 + 11;
int n, pos[NMAX], p[NMAX];
bool solve(void)
{
    bool vis[n];
    memset(vis, false, sizeof(*vis) * n);
    int cur = 0;
    while (cur < n)
    {
        if (vis[pos[cur]])
        {
            ++cur;
            continue;
        }
        if (not vis[pos[cur]])
        {
            vis[pos[cur++]] = true;
            while (pos[cur - 1] + 1 < n and not vis[pos[cur - 1] + 1])
            {
                if (pos[cur] != pos[cur - 1] + 1)
                    return false;
                vis[cur++] = true;
            }
        }
    }
    return true;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, pi;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> pi;
            p[i] = pi - 1;
            pos[pi - 1] = i;
        }
        cout << (solve() ? "Yes" : "No") << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

