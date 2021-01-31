---
layout: post
mathjax: true
title: 135B - Rectangle And Square
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
struct point
{
    ll x, y;
    int id;
    bool operator<(const point &o) const { return id < o.id; }
    point operator-(const point &o) const { return {x - o.x, y - o.y, id}; }
};
ll dot_product(point a, point b) { return a.x * b.x + a.y * b.y; }
bool orthogonal(point a, point b, point c)
{
    return dot_product(b - a, b - c) == 0;
}
ll sq(ll x) { return x * x; }
ll d2(point a, point b) { return sq(a.x - b.x) + sq(a.y - b.y); }
bool rectangle(point a, point b, point c, point d)
{
    return orthogonal(a, b, c) and orthogonal(b, c, d) and
           orthogonal(c, d, a) and orthogonal(d, a, b);
}
bool square(point a, point b, point c, point d)
{
    return rectangle(a, b, c, d) and d2(a, b) == d2(b, c);
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    point a[8];
    for (int i = 0; i < 8; i++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].id = i + 1;
    }
    do
    {
        if (square(a[0], a[1], a[2], a[3]) and
            rectangle(a[4], a[5], a[6], a[7]))
        {
            cout << "YES" << endl;
            for (int i = 0; i < 4; i++)
                cout << a[i].id << ' ';
            cout << endl;
            for (int i = 4; i < 8; i++)
                cout << a[i].id << ' ';
            cout << endl;
            return 0;
        }
    } while (next_permutation(a, a + 8));
    cout << "NO" << endl;
}

{% endraw %}
```
</details>

