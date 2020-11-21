---
layout: post
mathjax: true
title: 1397A Juggling Letters
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
bool possible(vi cnt, int n)
{
    for (auto freq : cnt)
    {
        if (freq % n != 0)
            return false;
    }
    return true;
}
int main(void)
{
    int t, n;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vi cnt(26, 0);
        for (int i = 0; i < n; ++i)
        {
            cin >> s;
            for (auto c : s)
                cnt[c - 'a']++;
        }
        cout << (possible(cnt, n) ? "YES" : "NO") << endl;
    }
    return 0;
}

{% endraw %}
```
