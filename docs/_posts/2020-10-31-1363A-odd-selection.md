---
layout: post
title: 1363A Odd Selection
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
bool solve(int x, int evens, int odds)
{
    if (odds == 0)
        return false;
    if (odds % 2 == 0)
        odds -= 1;
    int xp = x - 1;
    odds -= 1;
    xp -= min(odds, 2 * (xp / 2));
    return (xp - evens <= 0);
}
int main(void)
{
    int t, n, x, ai;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        int rem[2] = {0, 0};
        for (int i = 0; i < n; ++i)
        {
            cin >> ai;
            rem[ai % 2]++;
        }
        cout << (solve(x, rem[0], rem[1]) ? "Yes" : "No") << endl;
    }
    return 0;
}

```
