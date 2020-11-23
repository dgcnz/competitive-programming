---
layout: post
mathjax: true
title: 1753 String Matching
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

```cpp
{% raw %}
using namespace std;
using vi = vector<int>;
vi prefix_function(string s)
{
    int n = s.size();
    vi pi(n, 0);
    for (int i = 1; i < n; ++i)
    {
        int j = pi[i - 1];
        while (j > 0 and s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            ++j;
        pi[i] = j;
    }
    return pi;
}
int solve(string s, string p)
{
    int m = p.size();
    auto pi = prefix_function(p + '#' + s);
    return count_if(pi.begin(), pi.end(), [m](int x) { return x == m; });
}
int main(void)
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    string s, p;
    cin >> s >> p;
    cout << solve(s, p) << endl;
    return 0;
}

{% endraw %}
```