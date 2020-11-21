---
layout: post
title: 11466 Largest Prime Divisor
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
using ll = long long;
ll qn;
ll trial_division(ll n)
{
    ll count = 0;
    ll max_prime = -1;
    for (ll d = 2; d * d <= n; d++)
    {
        if (n % d == 0)
            ++count;
        while (n % d == 0)
        {
            n /= d;
            max_prime = max(max_prime, d);
        }
    }
    if (n > 1 and n != qn)
    {
        max_prime = max(max_prime, n);
        ++count;
    }
    if (count >= 2)
        return max_prime;
    return -1;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> qn and qn)
    {
        cout << trial_division(abs(qn)) << endl;
    }
    return 0;
}

```
