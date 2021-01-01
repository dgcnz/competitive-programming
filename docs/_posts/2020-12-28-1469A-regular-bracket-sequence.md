---
layout: post
mathjax: true
title: 1469A - Regular Bracket Sequence
problem_url: https://codeforces.com/contest/1469/problem/A
tags: greedy, observation
memory_complexity: O(n)
time_complexity: O(1)
---

There are two cases in which it is impossible to construct a valid sequence:
1. The length of the sequence is odd.
2. A parenthesis is unmatchable: `)....` or `....(`.

To understand why is it otherwise always possible, let $t$ be the string that
results from greedy-matching the existing parenthesis (matching a parenthesis
with the closest interrogation symbol). Such a string will be empty or be an
even-length sequence of `?`, which is trivially regular (first half `(` and
second half `)`).


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
    if (s[0] == ')' or s.back() == '(')
        return false;
    return ((int)(s).size() - 2) % 2 == 0;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << (solve(s) ? "YES" : "NO") << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

