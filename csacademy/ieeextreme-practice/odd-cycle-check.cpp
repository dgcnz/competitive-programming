#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;

int const NMAX = 2e4 + 11;

ii   parent[NMAX];
int  rnk[NMAX];
bool bipartite[NMAX];

void make_set(int u)
{
    parent[u]    = make_pair(u, 0);
    rnk[u]       = 0;
    bipartite[u] = true;
}

ii find_set(int u)
{
    if (u != parent[u].first)
    {
        int parity = parent[u].second;
        parent[u]  = find_set(parent[u].first);
        parent[u].second ^= parity;
    }
    return parent[u];
}

void add_edge(int a, int b)
{
    auto [u, x] = find_set(a);
    auto [v, y] = find_set(b);

    if (u == v)
    {
        if (x == y)
        {
            bipartite[u] = false;
        }
    }
    else
    {
        if (rnk[u] < rnk[v])
            swap(u, v);
        parent[v] = make_pair(u, x ^ y ^ 1);
        bipartite[u] &= bipartite[v];
        if (rnk[u] == rnk[v])
            ++rnk[u];
    }
}

bool is_bipartite(int u) { return bipartite[find_set(u).first]; }

int main(void)
{
    int n, u, v;
    cin >> n;
    for (int u = 0; u < n; ++u)
        make_set(u);

    do
    {
        cin >> u >> v, u--, v--;
        add_edge(u, v);
        cout << is_bipartite(u) << endl;
    } while (is_bipartite(u));
    return 0;
}
