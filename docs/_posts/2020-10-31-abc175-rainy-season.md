---
layout: post
title: Abc175 Rainy Season
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
    string s;
    cin >> s;
    int ans = 0, cnt = 0;
    for (auto c : s)
    {
        if (c == 'R')
            ++cnt;
        else
        {
            ans = max(cnt, ans);
            cnt = 0;
        }
    }
    ans = max(cnt, ans);
    cout << ans << endl;
    return 0;
}

```
