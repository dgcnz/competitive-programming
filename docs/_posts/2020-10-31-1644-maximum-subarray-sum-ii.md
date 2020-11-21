---
layout: post
mathjax: true
title: 1644 Maximum Subarray Sum Ii
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
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
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
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, minsz, maxsz;
    cin >> n >> minsz >> maxsz;
    vector<ll> a(n + 1, 0), psum(n + 1, 0);
    read_n(next(a.begin()), n);
    for (int i = 1; i <= n; ++i)
        psum[i] = psum[i - 1] + a[i];
    multiset<ll> window;
    ll ans = -1e18;
    window.insert(psum[0]);
    for (int i = minsz; i <= n; ++i)
    {
        ans = max(ans, psum[i] - *window.begin());
        if (i - minsz + 1 > 0)
            window.insert(psum[i - minsz + 1]);
        if (i - maxsz >= 0)
            window.erase(window.find(psum[i - maxsz]));
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
