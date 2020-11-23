---
layout: post
mathjax: true
title: 578C Weakness And Poorness
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
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
int const NMAX = 2e5 + 11;
int n, a[NMAX];
double f(double x)
{
    double mn = 0, mx = 0, sm = 0;
    for (int i = 0; i < n; i++)
    {
        sm += a[i] - x;
        mn = min(mn, sm);
        mx = max(mx, sm);
    }
    return abs(mx - mn);
};
double ternary_search(double l, double r, function<double(double)> f)
{
    double eps = 5e-12;
    while (r - l > eps)
    {
        double m1 = l + (r - l) / 3.0;
        double m2 = r - (r - l) / 3.0;
        if (f(m1) > f(m2))
            l = m1;
        else
            r = m2;
    }
    return f(l);
}
int main(void)
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << setprecision(15) << fixed << ternary_search(-1e4, 1e4, f) << endl;
    return 0;
}

{% endraw %}
```
</details>

