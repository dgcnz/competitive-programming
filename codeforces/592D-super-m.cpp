#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

const int NMAX = 123456 + 11;

int  n, m, node_end1, node_end2, diameter, edges;
bool in_attack[NMAX], st_in_attack[NMAX];
vi   g[NMAX];

void dfs1(int u, int p, int depth)
{
    if (in_attack[u] and
        (depth > diameter or (depth == diameter and u < node_end1)))
    {
        diameter  = depth;
        node_end1 = u;
    }
    for (auto v : g[u])
        if (v != p)
            dfs1(v, u, depth + 1);
}

void dfs2(int u, int p, int depth)
{
    if (in_attack[u] and
        (depth > diameter or (depth == diameter and u < node_end2)))
    {
        diameter  = depth;
        node_end2 = u;
    }
    st_in_attack[u] = in_attack[u];
    for (int v : g[u])
    {
        if (v != p)
        {
            dfs2(v, u, depth + 1);
            st_in_attack[u] |= st_in_attack[v];
        }
    }
    if (p != -1 and st_in_attack[u])
        edges += 1;
}

int main(void)
{
    int u, v;
    cin >> n >> m;

    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> u;
        in_attack[u - 1] = true;
    }

    edges = 0;
    dfs1((node_end1 = u - 1), -1, 0);
    dfs2((node_end2 = node_end1), -1, 0);

    cout << 1 + min(node_end1, node_end2) << endl;
    cout << 2 * edges - diameter << endl;

    return 0;
}
