---
layout: post
mathjax: true
title: Abc146_C Buy Integer
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
int const NMAX = 1e5 + 10;
int const PTWO = 30;
int const BITS = sizeof(int) * 8;
int _succ[NMAX][PTWO];
int succ(int u, int k)
{
    if (k == 0)
        return u;
    do
    {
        int i = BITS - __builtin_clz(k) - 1;
        u = _succ[u][i];
        k ^= 1 << i;
    } while (k > 0);
    return u;
}
int main(void)
{
    int n;
    string s;
    cin >> s;
    n = s.size();
    for (int u = 1; u <= n; ++u)
        _succ[u][0] = (s[u - 1] == 'R' ? u + 1 : u - 1);
    for (int p = 1; p < PTWO; ++p)
        for (int u = 1; u <= n; ++u)
            _succ[u][p] = _succ[_succ[u][p - 1]][p - 1];
    vector<int> ans(n, 0);
    for (int u = 1; u <= n; ++u)
        ans[succ(u, NMAX) - 1]++;
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}

{% endraw %}
```
