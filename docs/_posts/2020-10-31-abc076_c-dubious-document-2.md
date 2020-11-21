---
layout: post
mathjax: true
title: Abc076_C Dubious Document 2
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
int main(void)
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int k = -1;
    bool ok;
    if (n < m)
    {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    for (int i = 0; i < n - m + 1; ++i)
    {
        ok = true;
        for (int j = 0; j < m; ++j)
        {
            if (s[i + j] != t[j] and s[i + j] != '?')
            {
                ok = false;
            }
        }
        if (ok)
            k = i + m - 1;
    }
    if (k != -1)
    {
        for (int i = 0; i < n; ++i)
        {
            if (i >= k - m + 1 and i <= k)
            {
                cout << t[i - k + m - 1];
            }
            else
            {
                if (s[i] == '?')
                    cout << 'a';
                else
                    cout << s[i];
            }
        }
    }
    else
        cout << "UNRESTORABLE" << endl;
    return 0;
}

{% endraw %}
```
