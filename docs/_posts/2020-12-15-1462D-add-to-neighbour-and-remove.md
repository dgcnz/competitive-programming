---
layout: post
mathjax: true
title: 1462D - Add To Neighbour And Remove
problem_url: https://codeforces.com/contest/1462/problem/D
tags: brute_force
memory_complexity: O(n)
time_complexity: O(n^2)
---

Let's say that $b$ is an array reachable from $a$ by applying the described
operation such that $b_i = x$ for all $1 \leq i \leq k$, where $k \leq n$.
Note that $x$ is completely defined by $k$, so call it $x_k$:

$$ x_k =  \frac{\sum_{i = 1}^{n} a_i}{k} $$

The problem reduces to finding the biggest $k$ possible, and that can be
found by testing all possible $1 \leq k \leq n$ in descending order, and
returning the first match. Testing if $x_k$ is feasible can be done in a
simple $O(n)$ check.


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
template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void read_n(InputIterator it, int n)
{
    copy_n(istream_iterator<T>(cin), n, it);
}
bool test(const vi &a, ll x)
{
    int n = (int)(a).size();
    ll cur = 0;
    for (int i = 0; i < n; ++i)
    {
        if (cur + a[i] < x)
            cur += a[i];
        else if (cur + a[i] > x)
            return false;
        else
            cur = 0;
    }
    return cur == 0;
}
int solve(const vi &a)
{
    int n = (int)(a).size();
    ll sum = accumulate(begin(a), end(a), 0LL);
    for (int i = n; i > 1; --i)
        if (sum % i == 0 and test(a, sum / i))
            return n - i;
    return n - 1;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(n);
        read_n(begin(a), n);
        cout << solve(a) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

