---
layout: post
mathjax: true
title: abc188_a - Three Point Shot
problem_url: https://atcoder.jp/contests/abc188/tasks/abc188_a
tags: easy
memory_complexity: O(1)
time_complexity: O(1)
---

$$|x - y| < 3$$



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
    int x, y;
    cin >> x >> y;
    string ans[2] = {"No", "Yes"};
    cout << (abs(x - y) < 3 ? "Yes" : "No") << endl;
    return 0;
}

{% endraw %}
```
</details>

