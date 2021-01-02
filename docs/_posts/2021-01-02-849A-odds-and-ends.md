---
layout: post
mathjax: true
title: 849A - Odds And Ends
problem_url: https://codeforces.com/contest/849/problem/A
tags: implementation
memory_complexity: O(n)
time_complexity: O(1)
---

First of all, if $n$ is even then it is impossible to decompose it
into subsegments of odd sizes.

Otherwise if $n$ is odd then there must be necessarily a subsegment
containing the first element and a subsegment containing the last element,
otherwise it is not possible. If true, we can take the entire array as a
valid subsegment.


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
bool solve(vi a)
{
    int n = (int)(a).size();
    if ((a[0] % 2 != 1) or (a.back() % 2 != 1))
        return false;
    return n % 2;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    for (auto &ai : a)
        cin >> ai;
    cout << (solve(a) ? "Yes" : "No") << endl;
    return 0;
}

{% endraw %}
```
</details>

