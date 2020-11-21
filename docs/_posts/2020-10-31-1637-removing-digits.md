---
layout: post
title: 1637 Removing Digits
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
    int n, num, x, ans;
    cin >> n;
    ans = 0;
    while (n != 0)
    {
        x = n;
        num = 0;
        while (x != 0)
        {
            num = max(num, x % 10);
            x /= 10;
        }
        n -= num;
        ans += 1;
    }
    cout << ans << endl;
    return 0;
}

```
