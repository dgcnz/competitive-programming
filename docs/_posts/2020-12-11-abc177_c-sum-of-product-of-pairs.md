---
layout: post
mathjax: true
title: abc177_c - Sum Of Product Of Pairs
problem_url: https://atcoder.jp/contests/abc177/tasks/abc177_c
tags: math
memory_complexity: O(n)
time_complexity: O(n)
---

By doing some algebra on the expression you will note that the contribution
of $a_i$ is:

$$ a_i \times \sum_{j = i + 1}^{n} a_j $$


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
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll const MOD = 1e9 + 7;
    int n;
    cin >> n;
    vi a(n);
    read_n(begin(a), n);
    ll sfxsum = 0, ans = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        ans += a[i] * sfxsum;
        sfxsum += a[i];
        ans %= MOD, sfxsum %= MOD;
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
</details>

