---
layout: post
mathjax: true
title: 284A - Cows And Primitive Roots
problem_url: https://codeforces.com/problemset/problem/284/A
tags: brute_force, modulo
memory_complexity: O(1)
time_complexity: O(p^2)
---

Brute force and test all $x < p$. Check this
[editorial](https://codeforces.com/blog/entry/7037) for a more mathy
solution.


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
int solve(int p)
{
    int ans = 0;
    for (int x = 1; x < p; ++x)
    {
        bool flag = true;
        int y = x % p;
        for (int i = 1; i <= p - 2; ++i)
        {
            if (y == 1)
            {
                flag = false;
                break;
            }
            y = (y * x) % p;
        }
        if (y % p != 1)
            flag = false;
        ans += flag;
    }
    return ans;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int p;
    cin >> p;
    cout << solve(p) << endl;
    return 0;
}

{% endraw %}
```
</details>

