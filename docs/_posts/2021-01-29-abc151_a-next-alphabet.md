---
layout: post
mathjax: true
title: abc151_a - Next Alphabet
problem_url: https://atcoder.jp/contests/abc151/tasks/abc151_a
tags: easy
memory_complexity: O(1)
time_complexity: O(1)
---

$C + 1$


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
    char c;
    cin >> c;
    cout << char(c + 1) << endl;
    return 0;
}

{% endraw %}
```
</details>

