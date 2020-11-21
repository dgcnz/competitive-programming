---
layout: post
title: 1420B Rock And Lever
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<ll>;
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(n), cnt(64, 0);
        for (auto &ai : a)
        {
            cin >> ai;
            cnt[__builtin_clz(ai)]++;
        }
        ll ans = 0;
        for (auto x : cnt)
        {
            if (x == 0 or x == 1)
                continue;
            ans += (x * (x - 1)) / 2;
        }
        cout << ans << endl;
    }
    return 0;
}

```
