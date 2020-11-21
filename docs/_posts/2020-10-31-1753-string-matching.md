---
layout: post
mathjax: true
title: 1753 String Matching
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

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
