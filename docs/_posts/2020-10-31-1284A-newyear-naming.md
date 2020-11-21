---
layout: post
title: 1284A Newyear Naming
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
int n, m;
string S[22];
string T[22];
string solve(int year)
{
    string ans;
    ans = S[(year - 1) % n] + T[(year - 1) % m];
    return ans;
}
int main(void)
{
    int q;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
       cin >> S[i];
    for (int i = 0; i < m; ++i)
       cin >> T[i];
    cin >> q;
    while (q--)
    {
        int year;
        cin >> year;
        cout << solve(year) << endl;
    }
    return 0;
}

```
