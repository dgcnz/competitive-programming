---
layout: post
mathjax: true
title: Abc170_E Smart Infants
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
using vi = vector<int>;
using ii = pair<int, int>;
int const NMAX = 2e5 + 11;
int const INF = 1e9 + 100;
vector<int> a, b;
vector<multiset<ii, greater<ii>>>
    bs(NMAX);
multiset<pair<int, int>> ds;
void update(int i, int new_b)
{
    int cur_b = b[i];
    auto it = bs[cur_b].find({a[i], i});
    if (it == bs[cur_b].begin())
    {
        ds.erase({it->first, cur_b});
        if (bs[cur_b].size() == 1)
            ds.insert({INF, cur_b});
        else
            ds.insert({next(bs[cur_b].begin())->first, cur_b});
    }
    bs[cur_b].erase(it);
    if (bs[new_b].empty() or
        a[i] > bs[new_b].begin()->first)
    {
        ds.erase({bs[new_b].empty() ? INF : bs[new_b].begin()->first,
                  new_b});
        ds.insert({a[i], new_b});
    }
    bs[new_b].insert({a[i], i});
    b[i] = new_b;
}
int query(void) { return ds.begin()->first; }
int main(void)
{
    int n, q, i, d;
    cin >> n >> q;
    a.resize(n), b.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i] >> b[i], b[i]--;
        bs[b[i]].insert({a[i], i});
    }
    for (int i = 0; i < NMAX; ++i)
    {
        if (not bs[i].empty())
            ds.insert({bs[i].begin()->first, i});
        else
            ds.insert({INF, i});
    }
    while (q--)
    {
        cin >> i >> d, i--, d--;
        update(i, d);
        cout << query() << endl;
    }
    return 0;
}

{% endraw %}
```