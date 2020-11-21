---
layout: post
title: 1341C Nastya Strange Generator
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
const int NMAX = 1e5 + 11;
int n, pos[NMAX], p[NMAX];
bool solve(void)
{
    bool vis[n];
    memset(vis, false, sizeof(*vis) * n);
    int cur = 0;
    while (cur < n)
    {
        if (vis[pos[cur]])
        {
            ++cur;
            continue;
        }
        if (not vis[pos[cur]])
        {
            vis[pos[cur++]] = true;
            while (pos[cur - 1] + 1 < n and not vis[pos[cur - 1] + 1])
            {
                if (pos[cur] != pos[cur - 1] + 1)
                    return false;
                vis[cur++] = true;
            }
        }
    }
    return true;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, pi;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> pi;
            p[i] = pi - 1;
            pos[pi - 1] = i;
        }
        cout << (solve() ? "Yes" : "No") << endl;
    }
    return 0;
}

```
