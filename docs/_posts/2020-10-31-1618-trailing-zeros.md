---
layout: post
title: 1618 Trailing Zeros
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
int solve(int n)
{
    if (n == 0)
        return 0;
    return n / 5 + solve(n / 5);
}
int main(void)
{
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}

```
