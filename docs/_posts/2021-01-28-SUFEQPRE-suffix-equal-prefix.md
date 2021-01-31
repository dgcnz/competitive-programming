---
layout: post
mathjax: true
title: SUFEQPRE - Suffix Equal Prefix
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
const int NMAX = 1e6 + 11;
string s;
int n, pi[NMAX];
void prefix_function(void)
{
    memset(pi, 0, sizeof(pi));
    for (int i = 1; i < n; ++i)
    {
        int j = pi[i - 1];
        while (j > 0 and s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            ++j;
        pi[i] = j;
    }
}
int main(void)
{
    int t, ans, j;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        cin >> s;
        n = s.size();
        prefix_function();
        ans = 0;
        j = pi[n - 1];
        while (j != 0)
        {
            j = pi[j - 1];
            ans += 1;
        }
        cout << "Case " << tc << ": " << ans << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

