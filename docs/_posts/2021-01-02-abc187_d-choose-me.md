---
layout: post
mathjax: true
title: abc187_d - Choose Me
problem_url: https://atcoder.jp/contests/abc187/tasks/abc187_d
tags: greedy, sorting
memory_complexity: O(n)
time_complexity: O(n \log{n})
---

Greedy pick elements ordered by $2a + b$. Intuitively, we want to maximize
both the contribution of a pick to oneself, $a + b$, and the loss from the
other, $a$. Also, check [this](https://codeforces.com/blog/entry/86297).


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
using ii = pair<ll, ll>;
using vi = vector<int>;
int solve(vector<ii> ab)
{
    auto cmp = [](ii x, ii y) {
        auto [a1, b1] = x;
        auto [a2, b2] = y;
        return 2 * a1 + b1 > 2 * a2 + b2;
    };
    auto sum_first = [](ll acc, ii x) -> ll { return acc + x.first; };
    sort(begin(ab), end(ab), cmp);
    ll atot = accumulate(begin(ab), end(ab), 0LL, sum_first), btot = 0;
    int ans = 0;
    for (auto [a, b] : ab)
    {
        btot += a + b;
        atot -= a;
        ans++;
        if (btot > atot)
            break;
    }
    return ans;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ii> ab(n);
    for (auto &[a, b] : ab)
        cin >> a >> b;
    cout << solve(ab) << endl;
    return 0;
}

{% endraw %}
```
</details>

