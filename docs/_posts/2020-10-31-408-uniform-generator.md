---
layout: post
title: 408 Uniform Generator
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int main(void)
{
    int a, b;
    string ans;
    while (cin >> a >> b)
    {
        if (gcd(a, b) == 1)
            ans = "Good Choice";
        else
            ans = "Bad Choice";
        cout << setw(10) << right << a << setw(10) << b << setw(4) << " "
             << left << ans << endl
             << endl;
    }
}

```
