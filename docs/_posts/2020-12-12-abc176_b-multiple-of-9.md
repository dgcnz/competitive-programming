---
layout: post
mathjax: true
title: abc176_b - Multiple Of 9
problem_url: https://atcoder.jp/contests/abc176/tasks/abc176_b
tags: easy
memory_complexity: O(n)
time_complexity: O(n)
---

Check if the sum of digits is multiple of $9$.


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
    string n;
    cin >> n;
    ll sum =
        accumulate(begin(n), end(n), 0LL, [](ll acc, char c) { return acc + (c - '0'); });
    cout << (sum % 9 == 0 ? "Yes" : "No") << endl;
    return 0;
}

{% endraw %}
```
</details>

