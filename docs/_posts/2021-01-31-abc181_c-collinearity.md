---
layout: post
mathjax: true
title: abc181_c - Collinearity
problem_url: https://atcoder.jp/contests/abc181/tasks/abc181_c
tags: math, brute_force
memory_complexity: O(n)
time_complexity: O(n^3)
---

Given three points, we can check if they lie on the same line by testing if
their slope is the same. We shall do some algebra first to work with integers
and avoid precision errors.

Using this fact, we can try all triplets of points to see if they fulfill
this condition.



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
bool solve(vector<ii> points)
{
    int n = points.size();
    sort(begin(points), end(points));
    for (int i = 0; i < n - 2; ++i)
    {
        auto [x1, y1] = points[i];
        for (int j = i + 1; j < n - 1; ++j)
        {
            auto [x2, y2] = points[j];
            for (int k = j + 1; k < n; ++k)
            {
                auto [x3, y3] = points[k];
                if ((x2 - x1) * (y3 - y2) == (x3 - x2) * (y2 - y1))
                    return true;
            }
        }
    }
    return false;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ii> points(n);
    for (auto &[x, y] : points)
        cin >> x >> y;
    cout << (solve(points) ? "Yes" : "No") << endl;
    return 0;
}

{% endraw %}
```
</details>

