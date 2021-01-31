---
layout: post
mathjax: true
title: 1475E - Advertising Agency
problem_url: https://codeforces.com/contest/1475/problem/E
tags: counting, sorting
memory_complexity: O(n)
time_complexity: O(n \log{n})
---

[Comment](https://codeforces.com/blog/entry/87161?#comment-753182)



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
using mint = atcoder::modint1000000007;
ll C(int n, int k)
{
    mint up = 1, down = 1;
    for (int i = 0; i < k; ++i)
    {
        up *= n - i;
        down *= k - i;
    }
    return (up / down).val();
}
ll solve(vi a, int k)
{
    map<int, int, greater<int>> freq;
    for (auto ai : a)
        freq[ai]++;
    for (auto [x, cnt] : freq)
    {
        if (cnt < k)
            k -= cnt;
        else
            return C(cnt, k);
    }
    return 1;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vi a(n);
        for (auto &ai : a)
            cin >> ai;
        cout << solve(a, k) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

