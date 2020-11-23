---
layout: post
mathjax: true
title: 1337B Kana Dragon Quest
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

```cpp
{% raw %}
using namespace std;
inline void void_absorption(int &x) { x = x / 2 + 10; }
inline void lightning_strike(int &x) { x = x - 10; }
bool solve(int x, int n, int m)
{
    while (n-- > 0 and x > 20)
        void_absorption(x);
    while (m-- > 0 and x > 0)
        lightning_strike(x);
    return x <= 0;
}
int main(void)
{
    int t, x, n, m;
    cin >> t;
    while (t--)
    {
        cin >> x >> n >> m;
        cout << (solve(x, n, m) ? "YES" : "NO") << endl;
    }
    return 0;
}

{% endraw %}
```