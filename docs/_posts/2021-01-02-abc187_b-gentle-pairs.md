---
layout: post
mathjax: true
title: abc187_b - Gentle Pairs
problem_url: https://atcoder.jp/contests/abc187/tasks/abc187_b
tags: brute_force
memory_complexity: O(n)
time_complexity: O(n^2)
---

The formula to compute the slope given two points $(x_1, y_1)$ and
$(x_2, y_2)$ is:

$$ m = \frac{y_2 - y_1}{x_2 - x_1}$$

The problem tells you that:

$$ -1 \leq \frac{y_2 - y_1}{x_2 - x_1} \leq 1$$

Or equivalently:

$$ | y_2 - y_1 |  \leq x_2 - x_1 $$

Try all pairs and check if such condition holds. Don't forget to enforce an
order to ease implementation (sort points by $x$-coordinate).


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
int solve(vector<ii> xy)
{
    int n = (int)(xy).size(), ans = 0;
    sort(begin(xy), end(xy));
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            auto [xi, yi] = xy[i];
            auto [xj, yj] = xy[j];
            ans += (abs(yj - yi) <= (xj - xi));
        }
    }
    return ans;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ii> xy(n);
    for (auto &[x, y] : xy)
        cin >> x >> y;
    cout << solve(xy) << endl;
    return 0;
}

{% endraw %}
```
</details>

