---
layout: post
mathjax: true
title: 676C - Vasya And String
problem_url: http://codeforces.com/contest/676/problem/C
tags: two_pointers
memory_complexity: O(n)
time_complexity: O(n)
---

Without loss of generality, we want to find the largest substring consisting
of `a`s. To make this task easier, we can fix the right border, $r$ of this
hypothetical subarray.

Note that for a given $r$, to find the longest substring ending at $r$ we
should try to expand the left border as much as possible.

So, following this idea, we can try all $r$'s and find their corresponding
$l$'s using the two pointers technique or binary search.


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
int solve(string s, int k)
{
    int n = (int)(s).size();
    vi a(n, 0), b(n, 0);
    for (int i = 0; i < n; ++i)
    {
        a[i] += s[i] == 'a';
        b[i] += s[i] == 'b';
        if (i > 0)
            a[i] += a[i - 1], b[i] += b[i - 1];
    }
    auto cnt = [](vi &c, int l, int r) {
        return c[r] - (l > 0 ? c[l - 1] : 0);
    };
    int ans = 0;
    for (int r = 0, la = 0, lb = 0; r < n; ++r)
    {
        while (cnt(b, la, r) > k)
            ++la;
        while (cnt(a, lb, r) > k)
            ++lb;
        ans = max({ans, r - la + 1, r - lb + 1});
    }
    return ans;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    string s;
    cin >> n >> k >> s;
    cout << solve(s, k) << endl;
    return 0;
}

{% endraw %}
```
</details>

