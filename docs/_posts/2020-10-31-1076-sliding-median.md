---
layout: post
mathjax: true
title: 1076 Sliding Median
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
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using ordered_set = tree<ii,
                         null_type,
                         less<ii>,
                         rb_tree_tag,
                         tree_order_statistics_node_update>;
int n, k;
vector<int> a;
ordered_set s;
void build(void)
{
    for (int i = 0; i < k; ++i)
        s.insert({a[i], i});
}
int query(void) { return s.find_by_order((k - 1) / 2)->first; }
void increment(int l)
{
    s.erase(s.find({a[l], l}));
    s.insert({a[l + k], l + k});
}
int main(void)
{
    cin >> n >> k;
    a.resize(n);
    for (auto &ai : a)
        cin >> ai;
    build();
    for (int l = 0; l < n - k + 1; ++l)
    {
        cout << query() << " ";
        if (l + k != n)
            increment(l);
    }
    return 0;
}

{% endraw %}
```