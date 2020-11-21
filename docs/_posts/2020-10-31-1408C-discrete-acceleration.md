---
layout: post
title: 1408C Discrete Acceleration
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using predicate = function<bool(double)>;
template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void read_n(InputIterator it, int n)
{
    copy_n(istream_iterator<T>(cin), n, it);
}
template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void write(InputIterator first, InputIterator last, const char *delim = "\n")
{
    copy(first, last, ostream_iterator<T>(cout, delim));
}
ll n, L;
vi a, ar;
double T(double d, vi const &flag)
{
    int i = 0, flag_prev = 0;
    double tans = 0.0;
    double cur_speed = 1.0;
    while (i < n and flag[i] < d)
    {
        tans += (flag[i] - flag_prev) / cur_speed;
        flag_prev = flag[i];
        cur_speed++;
        ++i;
    }
    tans += (d - flag_prev) / cur_speed;
    return tans;
}
double bs(double l, double r, predicate p)
{
    for (int iter = 0; iter < 1000; ++iter)
    {
        double m = l + (r - l) / 2.0;
        if (p(m))
            r = m;
        else
            l = m;
    }
    return T(l, a);
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> L;
        a.resize(n), ar.resize(n);
        read_n(a.begin(), n);
        for (int i = 0; i < n; ++i)
            ar[n - i - 1] = L - a[i];
        cout << fixed << setprecision(9) << bs(0.0, double(L), [](double d) {
            return T(d, a) - T(L - d, ar) >= 0.0;
        }) << endl;
    }
    return 0;
}

{% endraw %}
```
