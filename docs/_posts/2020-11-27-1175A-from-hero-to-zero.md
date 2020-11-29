---
layout: post
mathjax: true
title: 1175A - From Hero To Zero
problem_url: https://codeforces.com/contest/1175/problem/A
tags: number_theory, euclidean_algorithm
memory_complexity: O(1)
time_complexity: O( \log{n})
---

Intuition tells us that it is always better to divide by $k$ whenever
possible. Following this reasoning, the procedure is as follows:

For a number $n = d_1 * k + r_1$, subtract $r_1$ and perform one division.
Our new number will be $d_1$. Proceed until 0.

One way to think about the problem is to convert the number $n$ to base-$k$.
The problem would then be to wipe out all numbers to get a sequence of zeros,
by subtracting $1$ or shifting left one position if the last position is $0$.

I think it becomes more evident why the aforementioned strategy is optimal.


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
ll solve(ll n, ll k)
{
    if (n == 0)
        return 0;
    ll r = n % k, d = n / k;
    return r + (d == 0 ? 0 : 1 + solve(d, k));
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

