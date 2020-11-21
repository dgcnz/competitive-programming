---
layout: post
title: 519D A B Interesting Substrings
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using ll = long long;
const int CMAX = 26;
map<ll, ll> m[CMAX + 1];
int x[CMAX + 1];
ll solve(string s)
{
    int n = s.size(), cur;
    ll ans = 0, sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cur = s[i] - 'a';
        ans += m[cur][sum];
        sum += x[cur];
        ++m[cur][sum];
    }
    return ans;
}
int main(void)
{
    string s;
    for (int i = 0; i < CMAX; ++i)
        cin >> x[i];
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}

{% endraw %}
```
