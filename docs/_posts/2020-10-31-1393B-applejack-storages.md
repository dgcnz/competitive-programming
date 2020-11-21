---
layout: post
mathjax: true
title: 1393B Applejack Storages
url: None
tags: None
time_complexity: None
memory_complexity: None
---

{% raw %}
None
{% endraw %}

```cpp
{% raw %}
using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;
int const NMAX = 1e5 + 11;
int n, freq[NMAX];
vi a;
set<ii, greater<ii>> s;
void build(void)
{
    s.emplace(0, 0), s.emplace(0, -1), s.emplace(0, -2);
    for (int i = 1; i < NMAX; ++i)
        s.emplace(freq[i] / 2, i);
}
void update(char type, int x)
{
    s.erase({freq[x] / 2, x});
    if (type == '+')
        freq[x]++;
    else
        freq[x]--;
    s.emplace(freq[x] / 2, x);
}
bool query(void)
{
    auto [m0, x0] = *s.begin();
    auto [m1, x1] = *next(s.begin());
    auto [m2, x2] = *next(next(s.begin()));
    if (m0 < 2)
        return false;
    m0 -= 2;
    if (m0 + m1 + m2 < 2)
        return false;
    return true;
}
int main(void)
{
    int q, x;
    char type;
    cin >> n;
    a.resize(n);
    for (auto &ai : a)
        cin >> ai, freq[ai]++;
    build();
    cin >> q;
    while (q--)
    {
        cin >> type >> x;
        update(type, x);
        cout << (query() ? "YES" : "NO") << endl;
    }
    return 0;
}

{% endraw %}
```
