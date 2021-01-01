---
layout: post
mathjax: true
title: 1466C - Canine Poetry
problem_url: https://codeforces.com/contest/1466/problem/C
tags: greedy
memory_complexity: O(n)
time_complexity: O(n)
---

Note that you only have to worry about substrings of the form: `xx` or `xyx`.

Strategy: if element in in a substring of one of the previous form, change it
so that it doesn't (don't forget to check that it won't form another
palindrome).


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
int solve(string s)
{
    int n = (int)(s).size(), ans = 0;
    s += "{{";
    vector<vector<bool>> prohibited(n + 2, vector<bool>(27, false));
    for (int i = 0; i < n; ++i)
    {
        if (prohibited[i][s[i] - 'a'])
        {
            for (int ch = 0; ch < 26; ++ch)
            {
                if (!prohibited[i][ch] and s[i + 1] != (ch + 'a') and
                    s[i + 2] != (ch + 'a'))
                {
                    s[i] = ch + 'a';
                    break;
                }
            }
            ans++;
        }
        prohibited[i + 1][s[i] - 'a'] = prohibited[i + 2][s[i] - 'a'] = true;
    }
    return ans;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

