---
layout: post
mathjax: true
title: 1641 Sum Of Three Values
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---

None


{% if page.time_complexity != "None" %}
- Time complexity: ${{ page.time_complexity }}$
{% endif %}
{% if page.memory_complexity != "None" %}
- Memory complexity: ${{ page.memory_complexity }}$
{% endif %}
{% if page.tags != "None" %}
- Tags: {{ page.tags }}
{% endif %}

{% if page.problem_url != "None" %}
- [URL]({{ page.problem_url }})
{% endif %}

```cpp
{% raw %}
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
int main(void)
{
    int n;
    ll x;
    cin >> n >> x;
    vii a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i)
    {
        int target = x - a[i].first;
        for (int j = i + 1, k = n - 1; j < k; ++j)
        {
            while (j < k and a[j].first + a[k].first > target)
                --k;
            if (j < k and a[j].first + a[k].first == target)
            {
                cout << a[i].second + 1 << " " << a[j].second + 1 << " "
                     << a[k].second + 1 << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}

{% endraw %}
```