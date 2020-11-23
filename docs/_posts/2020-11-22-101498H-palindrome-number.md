---
layout: post
mathjax: true
title: 101498H Palindrome Number
problem_url: None
tags: greedy 
memory_complexity: O(n) 
time_complexity: O(n) 
---

 - Note that there are 2 ways in which no solutions exist:
     1. n > 1 and s == 1, where placing 1 on both ends would exceed s.
     2. otherwise, when s exceeds placing 9 on all places.
 - The first case can be handled by a if guard.
 - Note that the most significant digits have greater effect in maximizing
the palindrome.
 - The strategy would then be to greedily maximize from i=0 to n/2.



{% if page.time_complexity != "None" %}
- Time complexity: ${{ page.time_complexity }}$
{% endif %}
{% if page.memory_complexity != "None" %}
- Memory complexity: ${{ page.memory_complexity }}$
{% endif %}
{% if page.tags != "None" %}
- Tags: {{ page.tags }}
{% endif %}

{% if page.problem_url != "None" %}
- [URL]({{ page.problem_url }})
{% endif %}

```cpp
{% raw %}
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
string solve(int n, int s)
{
    if (n > 1 and s == 1)
        return "-1";
    string ans(n, '0');
    for (int i = 0, mid = n / 2; i < mid; ++i)
    {
        for (int d = 9; d >= 0; --d)
        {
            if (s - 2 * d >= 0)
            {
                ans[i] = ans[n - 1 - i] = d + '0';
                s -= 2 * d;
                break;
            }
        }
    }
    if (n % 2 == 1)
    {
        for (int d = 9; d >= 0; --d)
        {
            if (s - d >= 0)
            {
                ans[n / 2] = d + '0';
                s -= d;
                break;
            }
        }
    }
    return s == 0 ? ans : "-1";
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        cout << solve(n, s) << endl;
    }
    return 0;
}

{% endraw %}
```