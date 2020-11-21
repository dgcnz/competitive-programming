---
layout: post
title: 612D Union K Segments
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
using ii = pair<int, int>;
using vii = vector<ii>;
int n, k;
vii events;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int li, ri;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> li >> ri;
        events.push_back({li, -1});
        events.push_back({ri, +1});
    }
    sort(events.begin(), events.end());
    int ck = 0;
    int cl, cr;
    vii ans;
    for (auto [t, sign] : events)
    {
        sign = -sign;
        if (sign > 0 and ck + 1 == k)
            cl = t;
        else if (sign < 0 and ck == k)
        {
            cr = t;
            ans.push_back({cl, cr});
        }
        ck += sign;
    }
    cout << ans.size() << endl;
    for (auto [l, r] : ans)
        cout << l << " " << r << endl;
    return 0;
}

```
