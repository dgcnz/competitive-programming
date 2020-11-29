---
layout: post
mathjax: true
title: arc109_c - Large Rps Tournament
problem_url: https://atcoder.jp/contests/arc109/tasks/arc109_c
tags: dp
memory_complexity: O(n^3)
time_complexity: O(n^2)
---

- $dp(k, l)$: winner of tournament that starts at position $l$ in string and
has $2^k$ players.


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
int const NMAX = 1e2 + 5;
int n, k;
char dp[NMAX][NMAX];
string s;
ll binpow(ll a, ll b)
{
    a %= n;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % n;
        a = a * a % n;
        b >>= 1;
    }
    return res;
}
char op(char a, char b)
{
    if (a == b)
        return a;
    if ((a == 'P' and b == 'R') or (a == 'S' and (b == 'R' or b == 'P')))
        swap(a, b);
    if (a == 'R' and b == 'P')
        return b;
    else if (a == 'R' and b == 'S')
        return 'R';
    else
        return 'S';
}
char solve(int l, int w)
{
    char &ans = dp[w][l];
    if (ans)
        return ans;
    else if (w == 0)
        return s[l];
    else
    {
        return ans = op(solve(l, w - 1),
                        solve((l + binpow(2, w - 1)) % n, w - 1));
    }
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> k >> s;
    cout << solve(0, k) << endl;
    return 0;
}

{% endraw %}
```
</details>

