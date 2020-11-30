---
layout: post
mathjax: true
title: arc065_a - Daydream
problem_url: https://atcoder.jp/contests/abc049/tasks/arc065_a
tags: backtracking
memory_complexity: O(n)
time_complexity: O(n)
---

- For position $i$, try all possible matches and backtrack if one doesn't
work.


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
int n;
string s, opts[4] = {"dream", "dreamer", "erase", "eraser"};
bool solve(int i)
{
    if (i == n)
        return true;
    bool ans = false;
    for (auto const &opt : opts)
    {
        int m = (int)(opt).size();
        if (m + i <= n and s.substr(i, m) == opt)
            ans = solve(i + m);
        if (ans)
            break;
    }
    return ans;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin >> s;
    n = (int)(s).size();
    cout << (solve(0) ? "YES" : "NO") << endl;
    return 0;
}

{% endraw %}
```
</details>

