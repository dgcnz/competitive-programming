---
layout: post
title: 1620 Factory Machines
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
using ll = unsigned long long;
using predicate = function<bool(ll)>;
const ll NMAX = 2e5 + 11;
ll n, nprods, k[NMAX];
bool possible(ll t)
{
    return nprods <= accumulate(k, k + n, (ll)0, [t](ll acc, ll ki) -> ll {
               return acc + t / ki;
           });
}
ll bsearch(ll l, ll r, predicate p)
{
    while (l < r)
    {
        ll mid = l + (r - l) / 2;
        if (p(mid))
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
int main(void)
{
    cin >> n >> nprods;
    for (ll i = 0; i < n; ++i)
        cin >> k[i];
    cout << bsearch(0, 1e18 + 11, possible) << endl;
    return 0;
}

```
