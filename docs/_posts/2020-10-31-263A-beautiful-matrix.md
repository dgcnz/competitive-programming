---
layout: post
title: 263A Beautiful Matrix
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
int main(void)
{
    int cell, ans = 0;
    for (int i = 1; i <= 5; ++i)
    {
        for (int j = 1; j <= 5; ++j)
        {
            cin >> cell;
            if (cell)
                ans = abs(3 - i) + abs(3 - j);
        }
    }
    cout << ans << endl;
    return 0;
}

```
