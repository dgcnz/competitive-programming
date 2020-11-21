---
layout: post
mathjax: true
title: 11475 Extend To Palindromes
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
const int NMAX = 1e5 + 11;
const int INF = 1e7;
int n, d1[NMAX], d2[NMAX];
void manacher(const string &s)
{
    for (int i = 0, l = 0, r = -1; i < n; ++i)
    {
        int j = l + r - i;
        int k = (i > r) ? 1 : min(d1[j], j - l + 1);
        while (0 <= i - k and i + k < n and s[i - k] == s[i + k])
            ++k;
        d1[i] = k--;
        if (i + k > r)
        {
            l = i - k;
            r = i + k;
        }
    }
    for (int i = 0, l = 0, r = -1; i < n; ++i)
    {
        int j = l + r - i;
        int k = (i > r) ? 0 : min(d2[j + 1], j - l + 1);
        while (0 <= i - k - 1 and i + k < n and s[i - k - 1] == s[i + k])
            ++k;
        d2[i] = k--;
        if (i + k > r)
        {
            l = i - k - 1;
            r = i + k;
        }
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int i1, i2, k1, k2, r1, r2, l1, l2, l;
    while (cin >> s)
    {
        memset(d1, 0, sizeof(d1));
        memset(d2, 0, sizeof(d2));
        n = s.size();
        manacher(s);
        i1 = i2 = n - 1;
        for (int i = n - 1; i >= 0; --i)
        {
            k1 = d1[i], k2 = d2[i];
            r1 = i + d1[i] - 1, r2 = i + d2[i] - 1;
            if (r1 == n - 1 and k1 > d1[i1])
                i1 = i;
            if (r2 == n - 1 and k2 > d2[i2])
                i2 = i;
        }
        l1 = i1 - (d1[i1] - 1);
        l2 = i2 - d2[i2];
        l = min(l1, (d2[i2] > 0 ? l2 : INF));
        if (l == 0)
        {
            cout << s << endl;
        }
        else
        {
            cout << s;
            for (int i = l - 1; i >= 0; --i)
                cout << s[i];
            cout << endl;
        }
    }
    return 0;
}

{% endraw %}
```
