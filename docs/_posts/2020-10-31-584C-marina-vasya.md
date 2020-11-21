---
layout: post
title: 584C Marina Vasya
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
int n, t;
string s1, s2;
int count_matching_indexes(void)
{
    int ans = 0;
    for (int i = 0; i < n; ++i)
        if (s1[i] == s2[i])
            ++ans;
    return ans;
}
char anything_but(char c, char d)
{
    for (char x = 'a'; x <= 'z'; ++x)
        if (x != c and x != d)
            return x;
    return 0;
}
string solve(void)
{
    string ans(n, ' ');
    int pt = n - t;
    int match_ix = count_matching_indexes();
    int rm_1 = max(0, pt - match_ix);
    int rm_2 = rm_1;
    int pmatch = min(match_ix, pt);
    for (int i = 0; i < n; ++i)
    {
        if (s1[i] != s2[i])
        {
            if (rm_1 > 0)
            {
                ans[i] = s1[i];
                --rm_1;
            }
            else if (rm_2 > 0)
            {
                ans[i] = s2[i];
                --rm_2;
            }
            else
                ans[i] = anything_but(s1[i], s2[i]);
        }
        else
        {
            if (pmatch > 0)
            {
                ans[i] = s1[i];
                --pmatch;
            }
            else
                ans[i] = anything_but(s1[i], s2[i]);
        }
    }
    if (rm_1 > 0 or rm_2 > 0)
        return "-1";
    else
        return ans;
}
int main(void)
{
    cin >> n >> t >> s1 >> s2;
    cout << solve() << endl;
    return 0;
}

{% endraw %}
```
