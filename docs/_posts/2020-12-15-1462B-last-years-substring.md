---
layout: post
mathjax: true
title: 1462B - Last Years Substring
problem_url: https://codeforces.com/contest/1462/problem/B
tags: implementation, strings
memory_complexity: O(n)
time_complexity: O(n)
---

There are three successful cases for a string $s$:
1. $s$ = `2020`
2. `2020` is a prefix of $s$
3. `2020` is a suffix of $s$

To see if $s$ matches one of these cases, compute the longest common prefix
between $s$ and `2020` and the longest common suffix between $s$ and `2020`.
If the sum of those answers is greater or equal than $4$, then it means that
I can combine them together (removing the excess in the middle) and get
$2020$.


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
bool solve(string s)
{
    int n = (int)(s).size();
    string sub = "2020";
    if (s == sub)
        return true;
    int pre = 0, suf = 0;
    while (pre < 4 and s[pre] == sub[pre])
        ++pre;
    while (suf < 4 and s[n - suf - 1] == sub[4 - suf - 1])
        ++suf;
    return pre + suf >= 4;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        cout << (solve(s) ? "YES" : "NO") << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

