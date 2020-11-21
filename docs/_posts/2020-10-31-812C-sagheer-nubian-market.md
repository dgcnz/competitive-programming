---
layout: post
title: 812C Sagheer Nubian Market
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using ll = long long;
const int NMAX = 10e5 + 11;
ll n, S;
ll a[NMAX], ka[NMAX];
ll compute(ll k)
{
    ll ans = 0;
    for (int i = 0; i < n; ++i)
        ka[i] = a[i] + (i + 1) * k;
    sort(ka, ka + n);
    for (int i = 0; i < k; ++i)
        ans += ka[i];
    return ans;
}
int binary_search(ll low, ll high, ll target)
{
    auto p = [&](ll k) { return compute(k + 1) > target; };
    while (low < high)
    {
        ll mid = low + (high - low + 1) / 2;
        if (p(mid))
            high = mid - 1;
        else
            low = mid;
    }
    if (p(low))
        return -1;
    return low;
}
int main(void)
{
    cin >> n >> S;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int index = binary_search(0, n - 1, S);
    cout << index + 1 << " " << (index == -1 ? 0 : compute(index + 1)) << endl;
    return 0;
}

{% endraw %}
```
