---
layout: post
title: 1322A Unusual Competitions
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
int n;
string s;
int solve(void)
{
    int ans, open_br, l;
    ans = open_br = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '(')
        {
            open_br += 1;
            if (open_br == 0)
                ans += i - l + 1;
        }
        else
        {
            open_br -= 1;
            if (open_br == -1)
                l = i;
        }
    }
    if (open_br != 0)
        return -1;
    return ans;
}
int main(void)
{
    cin >> n >> s;
    cout << solve() << endl;
    return 0;
}

```
