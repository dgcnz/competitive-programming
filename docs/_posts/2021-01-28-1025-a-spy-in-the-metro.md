---
layout: post
mathjax: true
title: 1025 - A Spy In The Metro
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
int const INF = 1e9;
int n, atime, m1, m2;
vi t, dep_left, dep_right, acc_time;
int solve(void)
{
    vector<vi> dp(n + 2, vi(atime + 1, INF));
    dp[1][0] = 0;
    for (int tt = 1; tt <= atime; ++tt)
    {
        for (int i = 1; i <= n; ++i)
        {
            auto &ans = dp[i][tt];
            ans = min(INF, dp[i][tt - 1] + 1);
            if (i - 1 >= 1 and tt - acc_time[i] >= 0 and
                binary_search((dep_left).begin(), (dep_left).end(), tt - acc_time[i]))
            {
                ans = min(ans, dp[i - 1][tt - t[i]]);
            }
            if (i + 1 <= n and tt - (acc_time[n] - acc_time[i]) >= 0 and
                binary_search((dep_right).begin(), (dep_right).end(), tt - (acc_time[n] - acc_time[i])))
            {
                ans = min(ans, dp[i + 1][tt - t[i + 1]]);
            }
        }
    }
    return dp[n][atime] == INF ? -1 : dp[n][atime];
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int tc = 1;
    while (cin >> n and n)
    {
        cin >> atime;
        t.resize(n + 1, 0), read_n(t.begin() + 2, n - 1);
        acc_time.resize(n + 1, 0), partial_sum((t).begin(), (t).end(), begin(acc_time));
        cin >> m1;
        dep_left.resize(m1, 0), read_n(dep_left.begin(), m1);
        cin >> m2;
        dep_right.resize(m2, 0), read_n(dep_right.begin(), m2);
        cout << "Case Number " << tc << ": ";
        if (auto ans = solve(); ans != -1)
            cout << ans << endl;
        else
            cout << "impossible" << endl;
        tc++;
    }
    return 0;
}

{% endraw %}
```
</details>

