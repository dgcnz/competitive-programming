---
layout: post
mathjax: true
title: abc148_c - Super Ryuma
problem_url: https://atcoder.jp/contests/abc184/tasks/abc184_c
tags: binary_search, math
memory_complexity: O(1)
time_complexity: O(\log{n})
---


See [Editorial](https://atcoder.jp/contests/abc184/editorial/374) for a much
better $O(1)$ solution.

To ease our analysis, let's paint the board with two colors, black and white,
in the same way as a chess board.

Note that if both pieces are on a cell with the same color, then the maximum
number of moves is 2 (two diagonals). Otherwise it is 3.

Compute the two points $p_3$ and $p_4$ that are closest to $p_2$ if I take
the respective diagonals from $p_1$ (using Binary Search). Let's say that
$p_3$ is the closest one to $p_2$.

If $p_3$ is at more distance than $3$, and both points are at the same color,
then we will only need another diagonal move, otherwise we'll need a move to
change colors and another diagonal move to reach $p_2$.

There are some cases to handle left, but that's the gist.


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
using predicate = function<bool(ll)>;
inline ll manhattan(ii p1, ii p2)
{
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}
ll bs(ll l, ll r, predicate p)
{
    while (l < r)
    {
        ll m = l + (r - l) / 2;
        if (p(m))
            r = m;
        else
            l = m + 1;
    }
    return l;
}
bool argmin(function<ll(ll)> f, ll x) { return f(x + 1) - f(x) >= 0; }
ii diag1(ii p, ll x) { return ii{p.first + x, p.second + x}; }
ii diag2(ii p, ll x) { return ii{p.first + x, p.second - x}; }
int solve(ii p1, ii p2)
{
    if (p1 == p2)
        return 0;
    else if (manhattan(p1, p2) <= 3)
        return 1;
    else
    {
        auto f1 = [p1, p2](ll x) { return manhattan(p2, diag1(p1, x)); };
        auto f2 = [p1, p2](ll x) { return manhattan(p2, diag2(p1, x)); };
        ll x1 = bs(-1e9, 1e9, bind(argmin, f1, placeholders::_1));
        ll x2 = bs(-1e9, 1e9, bind(argmin, f2, placeholders::_1));
        ii p3 = f1(x1) <= f2(x2) ? diag1(p1, x1) : diag2(p1, x2);
        if (p3 == p2)
            return 1;
        else if (manhattan(p1, p2) <= 6 or manhattan(p2, p3) <= 3)
            return 2;
        else
            return 2 +
                   !((p3.first + p3.second) % 2 == (p2.first + p2.second) % 2);
    }
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ii p1, p2;
    cin >> p1.first >> p1.second;
    cin >> p2.first >> p2.second;
    cout << solve(p1, p2) << endl;
    return 0;
}

{% endraw %}
```
</details>

