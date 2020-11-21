---
layout: post
title: 102433E Rainbow Strings
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
const int MOD = 11092019;
const int ALPHSZ = 26;
ll freq[ALPHSZ];
inline ll m(ll a, ll b) { return (a % MOD * b % MOD) % MOD; }
inline ll p(ll a, ll b) { return (a % MOD + b % MOD) % MOD; }
int main(void)
{
    int n;
    string s;
    ll ans;
    cin >> s;
    n = (int)s.size();
    for (int i = 0; i < n; i++)
        freq[s[i] - 'a']++;
    ans = 0;
    for (int i = 0; i < ALPHSZ; ++i)
    {
        ans = p(ans, p(m(ans, freq[i]), freq[i]));
    }
    cout << ans + 1 << endl;
    return 0;
}

{% endraw %}
```
