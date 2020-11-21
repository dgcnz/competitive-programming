---
layout: post
mathjax: true
title: 1370B Gcd Compression
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
const int NMAX = 1e3 + 11;
int n, a[2 * NMAX];
void solve(void)
{
    vi rem[2];
    for (int i = 0; i < 2 * n; ++i)
        rem[a[i] % 2].push_back(i);
    if ((int)rem[0].size() % 2 == 1)
    {
        rem[0].pop_back();
        rem[1].pop_back();
    }
    else
    {
        int j = 0;
        if ((int)rem[j].size() < (int)rem[1 - j].size())
            j = 1 - j;
        rem[j].pop_back();
        rem[j].pop_back();
    }
    for (int r = 0; r < 2; ++r)
    {
        for (int i = 0; i < (int)rem[r].size(); ++i)
        {
            cout << rem[r][i] + 1 << " ";
            if (i % 2 == 1)
                cout << endl;
        }
    }
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < 2 * n; ++i)
            cin >> a[i];
        solve();
    }
    return 0;
}

{% endraw %}
```
