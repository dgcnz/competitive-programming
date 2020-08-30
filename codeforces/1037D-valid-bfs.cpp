#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()

using namespace std;

int const NMAX = 2e5 + 11;

int      n, a[NMAX]; // check 1vs0 index
set<int> g[NMAX];

bool bfs_check(void)
{
    int        i = 0;
    queue<int> q;
    g[0].insert(1), g[1].insert(0);
    q.push(0);

    while (not q.empty())
    {
        auto p = q.front();
        q.pop();

        while (i < n and g[p].find(a[i]) != g[p].end())
            q.push(a[i++]);
    }
    return i == n;
}

int main(void)
{
    cin >> n;

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }

    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << (bfs_check() ? "Yes" : "No") << endl;

    return 0;
}
