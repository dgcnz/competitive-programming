---
layout: post
mathjax: true
title: 1399C Boats Competition
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

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
