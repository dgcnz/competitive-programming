---
layout: post
mathjax: true
title: 1733 Finding Periods
url: None
tags: None
time_complexity: None
memory_complexity: None
---

{% raw %}
None
{% endraw %}

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
void solve(string s)
{
    int n = s.size();
    vi pi = prefix_function(s), ans;
    int j = n - 1;
    while (pi[j])
    {
        ans.push_back(n - pi[j]);
        j = pi[j] - 1;
    }
    ans.push_back(n);
    for_each(ans.begin(), ans.end(), [](int x) { cout << x << " "; }),
        cout << endl;
}
int main(void)
{
    string s;
    cin >> s;
    solve(s);
    return 0;
}

{% endraw %}
```
