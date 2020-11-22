---
layout: post
mathjax: true
title: 446B Dzy Loves Modification
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
using pqll = priority_queue<ll>;
const ll NMAX = 1e3 + 11;
const ll KMAX = 1e6 + 11;
ll n, m, k, p;
ll rowsum[NMAX], colsum[NMAX];
ll a[KMAX], b[KMAX];
pqll pqrow;
pqll pqcol;
ll solve(void)
{
    ll pleasure(0), maxrow(0), maxcol(0);
    a[0] = b[0] = 0;
    for (int i = 1; i <= k; ++i)
    {
        maxrow = pqrow.top();
        pqrow.pop();
        pqrow.push(maxrow - m * p);
        a[i] = a[i - 1] + maxrow;
        maxcol = pqcol.top();
        pqcol.pop();
        pqcol.push(maxcol - n * p);
        b[i] = b[i - 1] + maxcol;
    }
    pleasure = a[0] + b[k];
    for (ll i = 1; i <= k; ++i)
        pleasure = max(pleasure, a[i] + b[k - i] - (i * (k - i) * p));
    return pleasure;
}
int main(void)
{
    cin >> n >> m >> k >> p;
    ll x;
    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < m; ++col)
        {
            cin >> x;
            rowsum[row] += x;
            colsum[col] += x;
        }
    }
    for (int row = 0; row < n; ++row)
        pqrow.push(rowsum[row]);
    for (int col = 0; col < m; ++col)
        pqcol.push(colsum[col]);
    cout << solve() << endl;
    return 0;
}

{% endraw %}
```