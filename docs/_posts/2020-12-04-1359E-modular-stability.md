---
layout: post
mathjax: true
title: 1359E - Modular Stability
problem_url: https://codeforces.com/contest/1359/problem/E
tags: modular_arithmetic, number_theory, counting
memory_complexity: O(n)
time_complexity: O(n)
---

The key observation is that an array is stable if and only if all its
elements are divisible by the minimum element, $a_1$.

Let's try to prove the forward direction of this assertion.

By contradiction, let's assume that there's an array $A$ that contains at
least a non-multiple of $a_1$. Let's call that element $a_r$.

We have that for $x = a_r$:

$$((x \% a_1) \% a_r) \% ... \neq ((x \% a_r) \% a_1) \% ... $$

We can repeat this argument for all elements of the array, so in conclusion,
all elements must be multiples of $a_1$.

Now, let's try to prove the backward direction.

Since $a_1$ is necessarily the minimum element we can reduce the initial
expression:

$$((x \% a_1) \% a_2) ... \% a_n = x \% a_1$$

And since all elements are of the form $a_i = d_i a_1$, we would like to know
if the following congruence holds:

$$ x - d_{p_i} a_1 - d_{p_{i + 1} } a_1 - ... - d_{p_n} a_1 \equiv x
\pmod{a_1}$$

Which is true, since all the terms aside from $x$ are congruent to $0$.

So, with this in mind, the problem reduces to counting the number of arrays
subject to the problem constraints and that have $a_1$ as a common factor.

Or, equivalently:

$$ ans = \sum_{i = 1}^{n} {\frac{n - i}{i} \choose k - 1}  $$

We can then use our favorite method for computing binomial coefficients and
we're done. :)


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
template <int M, typename T = long long>
class NumMod
{
    static_assert(std::is_integral<T>::value, "Integral required.");
    using NM = NumMod<M, T>;
    T x;
  public:
    static const int MOD = M;
    NumMod(T x) : x(x) {}
    NumMod() : x(0) {}
    NumMod(NM const &y) : x(y.v()) {}
    explicit operator T() const { return x; }
    T v(void) const { return (this->x + M) % M; }
    NM & operator=(NM const &y)
    {
        this->x = y.v();
        return *this;
    }
    NM &operator=(T const &y) { return this->operator=(NM(y)); }
    NM &operator+=(NM const &y) { return this->operator=(operator+(y)); }
    NM &operator-=(NM const &y) { return this->operator=(operator-(y)); }
    NM &operator*=(NM const &y) { return this->operator=(operator*(y)); }
    NM operator+(NM const &y) const { return (v() + y.v()) % M; }
    NM operator+(T const &y) const { return this->operator+(NM(y)); }
    NM operator-(NM const &y) const { return (v() - y.v()) % M; }
    NM operator-(T const &y) const { return this->operator-(NM(y)); }
    NM operator*(NM const &y) const { return (v() * y.v()) % M; }
    NM operator*(T const &y) const { return this->operator*(NM(y)); }
};
int const NMAX = 5e5 + 11;
int const MOD = 998244353;
using NM = NumMod<MOD, ll>;
NM fact[NMAX], inv[NMAX], inv_fact[NMAX];
void precompute_fact(void)
{
    inv[1] = fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < NMAX; ++i)
    {
        if (i > 1)
            inv[i] = MOD - ll(inv[MOD % i] * (MOD / i));
        fact[i] = fact[i - 1] * i;
        inv_fact[i] = inv_fact[i - 1] * inv[i];
    }
}
ll C(int n, int k)
{
    if (k > n)
        return 0;
    return ll(fact[n] * inv_fact[k] * inv_fact[n - k]);
}
int solve(int n, int k)
{
    if (k == 1)
        return n;
    int i = 1;
    NM cur, ans = 0;
    while (cur = C((n - i) / i, k - 1), ll(cur))
    {
        ans += cur;
        ++i;
    }
    return ll(ans);
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    precompute_fact();
    cout << solve(n, k) << endl;
    return 0;
}

{% endraw %}
```
</details>

