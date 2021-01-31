---
layout: post
mathjax: true
title: CNTPRIME - Counting Primes
problem_url: https://www.spoj.com/problems/CNTPRIME/
tags: lazy_segment_tree, data_structures, number_theory
memory_complexity: O(n)
time_complexity: O(q \log{n})
---

With a sieve precompute a function `is_prime(x)` in order to know if a number
$x$ is prime in $O(1)$ and trasform our initial array $a$ into an array $b$
such that `b[i] = is_prime[a[i]]`. We now have an array of $0$s and $1$s.

Note that the queries reduce to:
1. Query 1: Range sum of $l, r$.
2. Query 2: Change interval $l, r$ to $1$ if $v$ is prime, $0$ otherwise.

We can support these queries using a lazy segment tree.


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
template <int SIZE>
struct Sieve
{
    static_assert(0 <= SIZE and SIZE <= 1e8, "0 <= SIZE <= 1e8");
    using byte = unsigned char;
    std::bitset<SIZE> is_prime;
    std::vector<int> primes;
    Sieve()
    {
        is_prime.set();
        is_prime[0] = is_prime[1] = 0;
        for (int i = 4; i < SIZE; i += 2)
            is_prime[i] = 0;
        for (int i = 3; i * i < SIZE; i += 2)
            if (is_prime[i])
                for (int j = i * i; j < SIZE; j += i * 2)
                    is_prime[j] = 0;
        for (int i = 2; i < SIZE; ++i)
            if (is_prime[i])
                primes.push_back(i);
    }
};
struct S
{
    int n, np;
};
S op(S a, S b) { return {a.n + b.n, a.np + b.np}; }
S e() { return {0, 0}; };
struct F
{
    bool lazy, is_prime;
};
S mapping(F f, S x) { return f.lazy ? S{x.n, x.n * f.is_prime} : x; }
F composition(F f, F g) { return f.lazy ? f : g; }
F id() { return {0, 0}; }
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    int const AMAX = 1e6 + 11;
    Sieve<AMAX> sieve;
    using SegmentTree =
        atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;
    for (int tc = 1; tc <= t; ++tc)
    {
        cout << "Case " << tc << ":" << endl;
        int n, q;
        cin >> n >> q;
        vector<S> a(n);
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            a[i] = {1, sieve.is_prime[x]};
        }
        SegmentTree st(a);
        while (q--)
        {
            int type;
            cin >> type;
            if (type)
            {
                int l, r;
                cin >> l >> r, l--;
                auto ans = st.prod(l, r);
                cout << ans.np << endl;
            }
            else
            {
                int l, r, v;
                cin >> l >> r >> v, l--;
                st.apply(l, r, F{true, sieve.is_prime[v]});
            }
        }
    }
    return 0;
}

{% endraw %}
```
</details>

