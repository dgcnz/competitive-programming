---
layout: post
mathjax: true
title: 1367C - Social Distance
problem_url: https://codeforces.com/contest/1367/problem/C
tags: greedy, implementation
memory_complexity: O(n)
time_complexity: O(n)
---

For each block of consecutive zeros (with one on both ends) of size $m$,
one can place $ceil(\frac{m - 2k}{k + 1})$ ones.


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
int ceil(int a, int b) { return (a + b - 1) / b; }
int solve(string s, int k)
{
    s = "1" + string(k, '0') + s + string(k, '0') + "1";
    int cnt = 0;
    vi lengths;
    for (auto c : s)
    {
        if (c == '0')
            ++cnt;
        else
        {
            lengths.push_back(max(cnt - 2 * k, 0));
            cnt = 0;
        }
    }
    return accumulate(begin(lengths), end(lengths), 0LL, [k](int acc, int x) {
        return acc + ceil(x, k + 1);
    });
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        string s;
        cin >> n >> k >> s;
        cout << solve(s, k) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

