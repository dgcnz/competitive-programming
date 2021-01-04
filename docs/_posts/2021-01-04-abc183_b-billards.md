---
layout: post
mathjax: true
title: abc183_b - Billards
problem_url: https://atcoder.jp/contests/abc183/tasks/abc183_b
tags: math, geometry
memory_complexity: O(1)
time_complexity: O(1)
---

With a bit of geo, we can define the following two equations for the
$x$-coordinate of the incident point, $A_x$.

$$A_x = S_x + S_y \frac{\cos{\alpha}}{\sin{\alpha}}$$

$$A_x = G_x - G_y \frac{\cos{\alpha}}{\sin{\alpha}}$$

We can solve for $\alpha$ and then replace it on one of those equations to
get the answer.


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
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double alpha = atan(double(y1 + y2) / double(x2 - x1));
    cout << setprecision(12) << fixed << x1 + y1 * cos(alpha) / sin(alpha)
         << endl;
    return 0;
}

{% endraw %}
```
</details>

