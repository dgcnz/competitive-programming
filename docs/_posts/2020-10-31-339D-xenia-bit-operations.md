---
layout: post
mathjax: true
title: 339D Xenia Bit Operations
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
const int NMAX = (1L << 17) + 11;
int n, height, a[NMAX], seg[4 * NMAX];
int f(int x, int y, int h) { return (h % 2 == 0 ? x ^ y : x | y); }
void build(int a[], int v, int tl, int tr)
{
    if (tl == tr)
        seg[v] = a[tl];
    else
    {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        seg[v] = f(seg[v * 2], seg[v * 2 + 1], height - (int)log2(v));
    }
}
void update(int v, int tl, int tr, int pos, int x)
{
    if (pos < tl or pos > tr)
        return;
    if (tl == tr and tl == pos)
        seg[v] = x;
    else
    {
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, pos, x);
        update(v * 2 + 1, tm + 1, tr, pos, x);
        seg[v] = f(seg[v * 2], seg[v * 2 + 1], height - (int)log2(v));
    }
}
int main(void)
{
    int m, p, b;
    cin >> n >> m;
    n = 1L << n;
    height = log2(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    build(a, 1, 0, n - 1);
    while (m--)
    {
        cin >> p >> b;
        update(1, 0, n - 1, p - 1, b);
        cout << seg[1] << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

