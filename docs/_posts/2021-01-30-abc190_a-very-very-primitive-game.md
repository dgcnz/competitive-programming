---
layout: post
mathjax: true
title: abc190_a - Very Very Primitive Game
problem_url: https://atcoder.jp/contests/abc190/tasks/abc190_a
tags: easy
memory_complexity: O(1)
time_complexity: O(1)
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
using ii = pair<int, int>;
using vi = vector<int>;
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    string ans[2] = {"Aoki", "Takahashi"};
    int a, b, c;
    cin >> a >> b >> c;
    if (c == 0)
        cout << ans[a > b] << endl;
    else
        cout << ans[a >= b] << endl;
    return 0;
}

{% endraw %}
```
</details>

