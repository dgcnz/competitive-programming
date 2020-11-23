---
layout: post
mathjax: true
title: 1642 Sum Of Four Values
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
using ii = pair<int, int>;
using vi = vector<int>;
int const NMAX = 1e3 + 11;
int n, x, a[NMAX];
map<ll, vector<ii>> sums;
int main(void)
{
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            sums[a[i] + a[j]].emplace_back(i + 1, j + 1);
    for (auto [sum, positions] : sums)
    {
        if (auto it = sums.find(x - sum); it != sums.end())
        {
            for (auto [i, j] : positions)
            {
                for (auto [k, l] : it->second)
                {
                    if (i != k and i != l and j != k and j != l)
                    {
                        cout << i << " " << j << " " << k << " " << l << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}

{% endraw %}
```