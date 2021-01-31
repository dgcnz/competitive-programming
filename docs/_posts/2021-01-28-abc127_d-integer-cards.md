---
layout: post
mathjax: true
title: abc127_d - Integer Cards
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
using ll = long long;
int main(void)
{
    int n, m, ai;
    cin >> n >> m;
    multiset<int> a;
    for (int i = 0; i < n; ++i)
        cin >> ai, a.insert(ai);
    vector<ii> queries;
    queries.resize(m);
    for (auto &[ci, bi] : queries)
        cin >> bi >> ci;
    sort(queries.begin(), queries.end(), greater<ii>());
    for (auto [ci, bi] : queries)
    {
        if (*a.begin() >= ci)
            break;
        while (bi--)
        {
            auto it = a.begin();
            if (*it >= ci)
                break;
            a.erase(it);
            a.insert(ci);
        }
    }
    cout << accumulate(a.begin(), a.end(), (ll)0);
    return 0;
}

{% endraw %}
```
</details>

