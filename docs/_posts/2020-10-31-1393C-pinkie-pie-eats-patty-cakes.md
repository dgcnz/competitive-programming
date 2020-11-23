---
layout: post
mathjax: true
title: 1393C Pinkie Pie Eats Patty Cakes
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
using ii = pair<int, int>;
using vi = vector<int>;
int const NMAX = 1e5 + 11;
int n, a[NMAX], freq[NMAX];
set<ii, greater<ii>> ordered_freq;
int main(void)
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(freq, 0, sizeof(freq));
        ordered_freq.clear();
        for (int i = 0; i < n; ++i)
            cin >> a[i], freq[a[i]]++;
        for (int i = 0; i < NMAX; ++i)
            if (freq[i] > 0)
                ordered_freq.emplace(freq[i], i);
        auto [ftop, xtop] = *ordered_freq.begin();
        int cnt = 0, acc = 0;
        for (auto [fi, i] : ordered_freq)
        {
            if (fi < ftop)
                break;
            ++cnt;
            acc += ftop;
        }
        cout << (n - acc) / (ftop - 1) + cnt - 1 << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

