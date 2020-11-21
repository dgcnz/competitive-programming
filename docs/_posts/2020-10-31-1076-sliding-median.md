---
layout: post
mathjax: true
title: 1076 Sliding Median
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

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
