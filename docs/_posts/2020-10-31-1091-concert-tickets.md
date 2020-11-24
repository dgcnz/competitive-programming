---
layout: post
mathjax: true
title: 1091 - Concert Tickets
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
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
int main(void)
{
    int n, m;
    cin >> n >> m;
    set<ii> h;
    for (int i = 0; i < n; ++i)
    {
        int hi;
        cin >> hi;
        h.emplace(hi, i);
    }
    for (int i = 0; i < m; ++i)
    {
        int ti;
        cin >> ti;
        auto it = h.upper_bound({ti, 1e9});
        if (it != h.begin())
        {
            --it;
            cout << it->first << endl;
            h.erase(it);
        }
        else
            cout << -1 << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

