#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

const int NMAX = 1e5 + 11;

vi  g[NMAX];
int dp[NMAX];

void compdp(int u, int p)
{
    dp[u] = 0;
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        compdp(v, u);

        if (dp[v] == 0)
            dp[u] = 1;
    }
}

int main(void)
{
    int n, u, v;

    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    compdp(1, 0);
    cout << accumulate(dp + 1, dp + n + 1, 0) << endl;
    return 0;
}
