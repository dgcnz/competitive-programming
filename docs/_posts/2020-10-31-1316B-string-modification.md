---
layout: post
mathjax: true
title: 1316B String Modification
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---

None


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
int n;
char s[5010];
string rev(int k)
{
    string ans(n, ' ');
    for (int i = 0; i < (n - k + 1); ++i)
        ans[i] = s[k - 1 + i];
    if ((n - k + 1) % 2 == 0)
        for (int i = n - k + 1; i < n; ++i)
            ans[i] = s[i - (n - k + 1)];
    else
        for (int i = n - 1; i >= n - k + 1; --i)
            ans[i] = s[n - i - 1];
    return ans;
}
void solve(void)
{
    string ans(s);
    int mink = 1;
    for (int k = 1; k <= n; ++k)
    {
        string cur = rev(k);
        if (cur < ans)
        {
            ans = cur;
            mink = k;
        }
    }
    cout << ans << endl << mink << endl;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        solve();
    }
}

{% endraw %}
```