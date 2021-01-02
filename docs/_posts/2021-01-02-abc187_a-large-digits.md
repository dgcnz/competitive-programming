---
layout: post
mathjax: true
title: abc187_a - Large Digits
problem_url: https://atcoder.jp/contests/abc187/tasks/abc187_a
tags: easy, implementation
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
int d(char c) { return c - '0'; }
int s(string x) { return d(x[0]) + d(x[1]) + d(x[2]); }
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    int sa = s(a), sb = s(b);
    cout << (sa >= sb ? sa : sb) << endl;
    return 0;
}

{% endraw %}
```
</details>

