---
layout: post
mathjax: true
title: 10490 - Mr Azad And His Son
problem_url: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1431
tags: number_theory, primes
memory_complexity: O(1)
time_complexity: O(\sqrt{2^n})
---

- Testing primality up to the square root does the trick.

Implementation details:
- Make sure you precompute the square root, instead of constantly squaring x.
That did all the difference for me (from 3s TLE to 0ms AC).


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
bool is_prime(int n)
{
    if (n < 2)
        return false;
    for (int x = 2, sq = sqrt(n); x <= sq; ++x)
        if (n % x == 0)
            return false;
    return true;
}
int main(void)
{
    int n;
    while (scanf("%d", &n) == 1 && n)
    {
        if (not is_prime(n))
            printf(
                "Given number is NOT prime! NO perfect number is available.\n");
        else if (is_prime((1LL << n) - 1))
            printf("Perfect: %lld!\n", (1LL << (n - 1)) * ((1LL << n) - 1));
        else
            printf("Given number is prime. But, NO perfect number is "
                   "available.\n");
    }
    return 0;
}

{% endraw %}
```
</details>

