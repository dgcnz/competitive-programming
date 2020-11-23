---
layout: post
mathjax: true
title: 1399C Boats Competition
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
using vi = vector<int>;
int const NMAX = 55;
int solve(int n, vi w)
{
    map<int, int> sum_count;
    vi freq(NMAX, 0);
    for (int i = 0; i < n; ++i)
        freq[w[i]]++;
    for (int i = 1; i < NMAX; ++i)
    {
        for (int j = i; j < NMAX; ++j)
        {
            if (i == j)
                sum_count[i + j] += freq[i] / 2;
            else
                sum_count[i + j] += min(freq[i], freq[j]);
        }
    }
    return max_element(sum_count.begin(),
                       sum_count.end(),
                       [](const auto &p1, const auto &p2) {
                           return p1.second < p2.second;
                       })
        ->second;
}
int main(void)
{
    int t, n;
    vi w;
    cin >> t;
    while (t--)
    {
        cin >> n;
        w.resize(n);
        for (auto &wi : w)
            cin >> wi;
        cout << solve(n, w) << endl;
    }
    return 0;
}

{% endraw %}
```