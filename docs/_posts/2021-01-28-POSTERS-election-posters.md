---
layout: post
mathjax: true
title: POSTERS - Election Posters
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
using vii = vector<ii>;
using vi = vector<int>;
using si = set<int>;
using mii = map<int, int>;
const int NMAX = 4e4 + 11;
int seg[4 * NMAX], lazy[4 * NMAX];
void lazy_propagate(int v, int tl, int tr, int new_val)
{
    seg[v] = new_val;
    if (tl != tr)
    {
        lazy[2 * v] = new_val;
        lazy[2 * v + 1] = new_val;
    }
    lazy[v] = 0;
}
void update(int v, int tl, int tr, int ql, int qr, int new_val)
{
    if (lazy[v] != 0)
        lazy_propagate(v, tl, tr, lazy[v]);
    if (ql > qr)
        return;
    else if (ql == tl and qr == tr)
        lazy_propagate(v, tl, tr, new_val);
    else
    {
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, ql, min(qr, tm), new_val);
        update(v * 2 + 1, tm + 1, tr, max(ql, tm + 1), qr, new_val);
    }
}
int query(int v, int tl, int tr, int ql, int qr)
{
    if (lazy[v] != 0)
        lazy_propagate(v, tl, tr, lazy[v]);
    if (ql > qr)
        return 0;
    if (ql == tl and qr == tr)
        return seg[v];
    else
    {
        int tm = (tl + tr) / 2;
        return query(2 * v, tl, tm, ql, min(qr, tm)) +
               query(2 * v + 1, tm + 1, tr, max(ql, tm + 1), qr);
    }
}
pair<int, vii> compress(vii qranges)
{
    vi values;
    mii compressed;
    for (auto [l, r] : qranges)
        values.push_back(l), values.push_back(r);
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    for (int i = 0, maxv = values.size(); i < maxv; i++)
        compressed[values[i]] = i + 1;
    for (auto &[l, r] : qranges)
        l = compressed[l], r = compressed[r];
    return {(int)values.size(), qranges};
}
int main(void)
{
    int t, n;
    cin >> t;
    while (t--)
    {
        memset(seg, 0, sizeof(seg));
        memset(lazy, 0, sizeof(lazy));
        cin >> n;
        vii qranges(n);
        for (auto &[l, r] : qranges)
            cin >> l >> r;
        auto [max_val, cranges] = compress(qranges);
        for (int i = 0; i < n; ++i)
        {
            auto [l, r] = cranges[i];
            update(1, 1, max_val, l, r, i + 1);
        }
        si ans;
        for (int i = 1; i <= max_val; ++i)
            ans.insert(query(1, 1, max_val, i, i));
        ans.erase(0);
        cout << ans.size() << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

