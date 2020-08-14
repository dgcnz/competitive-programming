// @idea:
//  - represent path as a permutation of [1..n]
//  - enumerate all and check if path is valid:
//      - starts on 1
//      - adjacent elements in permutation are also adjacent in the graph

#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using ll = long long;

int main(void)
{
    int        n, m, u, v;
    vector<vi> edge_exists;
    vi         node_seq;
    cin >> n >> m;

    edge_exists.resize(n + 1, vi(n + 1, false));

    for (int i = 1; i <= n; ++i)
        node_seq.push_back(i);

    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        edge_exists[u][v] = edge_exists[v][u] = true;
    }

    ll ans = 0;
    do
    {
        bool is_hamiltonian = true;
        for (int i = 1; is_hamiltonian and i < n; ++i)
        {
            u = node_seq[i - 1], v = node_seq[i];
            if (not edge_exists[u][v])
                is_hamiltonian = false;
        }
        ans += is_hamiltonian;
    } while (next_permutation(next(node_seq.begin()), node_seq.end()));

    cout << ans << endl;

    return 0;
}
