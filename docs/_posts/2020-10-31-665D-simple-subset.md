---
layout: post
mathjax: true
title: 665D Simple Subset
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

<details>
<summary>
<p style="display:inline">Click to show code.</p>
</summary>
```cpp
{% raw %}
using namespace std;
using ll = long long;
using vi = vector<int>;
int const AMAX = 2e6 + 11;
bitset<AMAX> is_prime;
void sieve()
{
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for (ll i = 2; i < AMAX; ++i)
        if (is_prime[i])
            for (ll j = i * i; j < AMAX; j += i)
                is_prime[j] = 0;
}
int main(void)
{
    int n;
    vi a, ans;
    cin >> n;
    a.resize(n);
    for (auto &ai : a)
        cin >> ai;
    sort(a.begin(), a.end());
    sieve();
    if (a[0] == 1)
    {
        auto it = upper_bound(a.begin(), a.end(), 1);
        int ones = distance(a.begin(), it);
        int x = -1;
        for (; it != a.end(); ++it)
        {
            if (is_prime[*it + 1])
            {
                x = *it;
                break;
            }
        }
        ans = vi(a.begin(), a.begin() + ones);
        if (x != -1)
            ans.push_back(x);
    }
    if ((int)ans.size() < 2)
    {
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (is_prime[a[i] + a[j]])
                {
                    ans.clear();
                    ans.push_back(a[i]), ans.push_back(a[j]);
                    break;
                }
            }
            if ((int)ans.size() == 2)
                break;
        }
    }
    if ((int)ans.size() < 1)
        ans = {a[0]};
    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}

{% endraw %}
```
</details>

