---
layout: post
mathjax: true
title: 1463B - Find The Array
problem_url: https://codeforces.com/contest/1463/problem/B
tags: math, observation
memory_complexity: O(n)
time_complexity: O(n \log{n})
---

Idea: for each $a_i$, let $b_i$ be the biggest power of $2$ less than or
equal to $a_i$.

So, if $b_i = 2^k$, then $2^k \leq a_i \leq 2^{k + 1}$. This tells us that
the difference between $a_i$ and $b_i$ is at most $b_i$ (remember that the
length of the range $2^k, 2^{k + 1}$ is $2^k$).

Equivalently, $\frac{a_i}{2} \leq b_i \leq a_i$, which tells us that:

$$ a_i - b_i \leq \frac{a_i}{2} $$

Therefore, by picking $b_i$'s with the following strategy, the sum of
differences will be at most $\frac{S}{2}$, begin $S$ the total sum of
$a_i$'s.


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
template <typename InputIt,
          typename T = typename std::iterator_traits<InputIt>::value_type>
void write(InputIt first, InputIt last, const char *delim = "\n")
{
    copy(first, last, std::ostream_iterator<T>(std::cout, delim));
}
int prevpow2(int n)
{
    int ans = 1;
    while (ans <= n)
        ans <<= 1;
    return (ans >>= 1);
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
        vi b(n, 0);
        for (auto &bi : b)
        {
            int ai;
            cin >> ai;
            bi = prevpow2(ai);
        }
        write(begin(b), end(b), " "), cout << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

