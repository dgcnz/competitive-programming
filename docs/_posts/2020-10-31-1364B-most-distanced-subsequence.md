---
layout: post
title: 1364B Most Distanced Subsequence
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
const int NMAX = 1e5 + 11;
int n, a[NMAX];
bool increasing[NMAX];
void solve(void)
{
    vi ans;
    ans.push_back(a[0]);
    for (int i = 1; i <= n; ++i)
    {
        if (increasing[i] != increasing[i - 1])
            ans.push_back(a[i - 1]);
    }
    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            if (i > 0)
                increasing[i] = (a[i] >= a[i - 1]);
        }
        increasing[0] = increasing[1];
        increasing[n] = !increasing[n - 1];
        solve();
    }
    return 0;
}

{% endraw %}
```
