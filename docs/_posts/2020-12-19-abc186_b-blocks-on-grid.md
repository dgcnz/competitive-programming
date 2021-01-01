---
layout: post
mathjax: true
title: abc186_b - Blocks On Grid
problem_url: https://atcoder.jp/contests/abc186/tasks/abc186_b
tags: easy, implementation
memory_complexity: O(hw)
time_complexity: O(hw)
---

To make all blocks the same height, make them the same height. as the
smallest block.


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
    int h, w;
    cin >> h >> w;
    ll minv = 1e9, sum = 0;
    for (int r = 0; r < h; ++r)
    {
        for (int c = 0; c < w; ++c)
        {
            ll arc;
            cin >> arc;
            minv = min(minv, arc);
            sum += arc;
        }
    }
    cout << sum - (h * w * minv) << endl;
    return 0;
}

{% endraw %}
```
</details>

