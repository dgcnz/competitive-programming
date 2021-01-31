---
layout: post
mathjax: true
title: 1629 - Movie Festival
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
using vii = vector<ii>;
int main(void)
{
    int n, last = 0, ans = 0;
    cin >> n;
    vii movies(n);
    for (auto &[s, e] : movies)
        cin >> s >> e;
    sort(movies.begin(), movies.end(), [](ii x, ii y) {
        return x.second < y.second;
    });
    for (auto [s, e] : movies)
    {
        if (last <= s)
        {
            last = e;
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
</details>

