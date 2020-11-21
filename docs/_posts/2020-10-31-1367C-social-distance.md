---
layout: post
title: 1367C Social Distance
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
const int INF = 1e6;
int main(void)
{
    int t, n, k, last;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cin >> s;
        last = -INF;
        int ans = 0;
        for (int i = 0; i < (int)s.size(); ++i)
        {
            if (s[i] == '1')
                last = i;
            else if (s[i] == '0' and last + k < i)
            {
                int j = i + 1;
                bool possible = true;
                while (j < n and j <= i + k)
                {
                    if (s[j] == '1')
                    {
                        possible = false;
                        break;
                    }
                    ++j;
                }
                if (possible)
                {
                    ans += 1;
                    s[i] = '1';
                    last = i;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

```
