---
layout: post
mathjax: true
title: 1405B Array Cancellation
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---



{% if page.time_complexity != "None" %}
Time complexity: ${{ page.time_complexity }}$
{% endif %}

{% if page.memory_complexity != "None" %}
Memory complexity: ${{ page.memory_complexity }}$
{% endif %}

```cpp
{% raw %}
using namespace std;
using ll = long long;
using vll = vector<ll>;
ll solve(vll &a)
{
    int n = (int)a.size();;
    ll ans = 0;
    int l = 0, r = n - 1;
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] > 0)
        {
            while (r > i and a[i] > 0)
            {
                if (a[r] < 0)
                {
                    auto diff = min(a[i], abs(a[r]));
                    a[i] -= diff;
                    a[r] += diff;
                }
                if (a[r] == 0)
                    --r;
            }
            while (l < i and a[i] > 0)
            {
                if (a[l] < 0)
                {
                    auto diff = min(a[i], abs(a[l]));
                    a[i] -= diff;
                    a[l] += diff;
                    ans += diff;
                }
                if (a[l] >= 0)
                    ++l;
            }
        }
    }
    return ans;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vll a(n);
        for (auto &ai : a)
            cin >> ai;
        cout << solve(a) << endl;
    }
    return 0;
}

{% endraw %}
```