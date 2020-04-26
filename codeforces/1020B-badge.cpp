#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1e3 + 11;

int n, vis[NMAX], g[NMAX];

int find_cycle(int u)
{
    if (vis[u] == 2)
        return u;

    ++vis[u];
    return find_cycle(g[u]);
}

int main(void)
{
    int v;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> v;
        g[i] = v - 1;
    }

    for (int i = 0; i < n; ++i)
    {
        memset(vis, 0, n * sizeof(*vis));
        cout << find_cycle(i) + 1 << " ";
    }
    cout << endl;

    return 0;
}
