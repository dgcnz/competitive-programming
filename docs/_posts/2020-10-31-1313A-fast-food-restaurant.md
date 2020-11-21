---
layout: post
mathjax: true
title: 1313A Fast Food Restaurant
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
int ps[7][3] = {{0, 0, 1},
                {0, 1, 0},
                {0, 1, 1},
                {1, 0, 0},
                {1, 0, 1},
                {1, 1, 0},
                {1, 1, 1}};
unsigned char set(unsigned char u, int pos)
{
    u |= 1UL << pos;
    return u;
}
unsigned char clear(unsigned char u, int pos)
{
    u &= ~(1UL << pos);
    return u;
}
bool get(unsigned char u, int pos) { return u & (1UL << pos); }
int solve(int a, int b, int c, unsigned char &taken)
{
    int ans = 0;
    unsigned char maxtaken = taken;
    for (int i = 0; i < 7; ++i)
    {
        unsigned char localtaken = maxtaken;
        auto [ap, bp, cp] = ps[i];
        if (get(taken, i))
            continue;
        if (a - ap < 0 or b - bp < 0 or c - cp < 0)
            continue;
        localtaken = set(localtaken, i);
        int cur = 1 + solve(a - ap, b - bp, c - cp, localtaken);
        if (cur > ans)
        {
            ans = cur;
            maxtaken = localtaken;
        }
        localtaken = clear(localtaken, i);
    }
    taken = maxtaken;
    return ans;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, ans;
        unsigned char taken = 0;
        cin >> a >> b >> c;
        ans = solve(a, b, c, taken);
        cout << ans << endl;
    }
    return 0;
}

{% endraw %}
```
