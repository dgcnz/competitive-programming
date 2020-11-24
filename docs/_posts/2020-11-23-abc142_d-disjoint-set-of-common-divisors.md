---
layout: post
mathjax: true
title: abc142_d - Disjoint Set Of Common Divisors
problem_url: https://atcoder.jp/contests/abc142/tasks/abc142_d
tags: math, sorting
memory_complexity: O(\sqrt{n})
time_complexity: O(\sqrt{n})
---

First note that all the common divisors of $A$ and $B$ are the factors of
$gcd(A, B)$.

The key observation is that the optimal answer is the set of all prime
factors of $gcd(A, B)$ and 1. It is trivial to see that such a set is indeed
mutually coprime.

The intuition behind this is that if we were to add a composite factor to our
answer set, then it would always be a better choice to add its prime factors.



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
using vi = vector<int>;
vi prime_factors(ll n)
{
    vi factors;
    for (ll i = 2; i * i <= n; ++i)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        factors.push_back(n);
    return factors;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll A, B;
    cin >> A >> B;
    ll g = gcd(A, B);
    auto factors = prime_factors(g);
    cout << 1 + distance(begin(factors), unique(begin(factors), end(factors))) << endl;
    return 0;
}

{% endraw %}
```
</details>

