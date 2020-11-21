---
layout: post
mathjax: true
title: 1632 Movie Festival Ii
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
    int n, k;
    cin >> n >> k;
    vector<ii> movies(n);
    for (auto &[e, s] : movies)
        cin >> s >> e;
    sort(movies.begin(), movies.end());
    set<ii> tavailable;
    for (int i = 1; i <= k; ++i)
        tavailable.emplace(0, i);
    int ans = 0;
    for (auto [e, s] : movies)
    {
        auto it = tavailable.upper_bound({s, 1e9});
        if (it != tavailable.begin())
        {
            --it;
            auto [free_time, ix] = *it;
            tavailable.erase(it);
            tavailable.emplace(e, ix);
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
