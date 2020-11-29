---
layout: post
mathjax: true
title: 977F - Consecutive Subsequence
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
vi solve(int n, vi a)
{
    set<ii> sorted;
    for (int i = 0; i < n; ++i)
        sorted.emplace(a[i], i);
    vi dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = 1;
        auto it = sorted.lower_bound({a[i - 1] - 1, i - 1});
        if (it == sorted.begin() or prev(it)->first != a[i - 1] - 1)
            continue;
        auto [aj, j] = *prev(it);
        dp[i] += dp[j + 1];
    }
    int i = distance(dp.begin(), max_element(dp.begin(), dp.end())) - 1, m = dp[i + 1],
        x = a[i];
    vi ans(m);
    for (int j = m - 1; j >= 0; --j)
    {
        ans[j] = i + 1;
        auto it = sorted.lower_bound({x - 1, i});
        if (j > 0)
        {
            it--;
            x = it->first;
            i = it->second;
        }
    }
    return ans;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    read_n(a.begin(), n);
    vi ans = solve(n, a);
    cout << (int)ans.size() << endl;
    write(ans.begin(), ans.end(), " "), cout << endl;
    return 0;
}

{% endraw %}
```
</details>

