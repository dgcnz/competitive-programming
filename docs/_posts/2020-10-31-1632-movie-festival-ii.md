---
layout: post
mathjax: true
title: 1632 Movie Festival Ii
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
</details>

