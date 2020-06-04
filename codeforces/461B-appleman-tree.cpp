#include <bits/stdc++.h>

// Thanks a lot to this article :D
// https://abitofcs.blogspot.com/2014/12/dynamic-programming-on-tree-forming-up.html

using namespace std;
using vi = vector<int>;
using ll = long long;

const int NMAX = 1e5 + 11;
const int MOD  = 1e9 + 7;

int  n;
bool black[NMAX];
vi   g[NMAX];
ll   B[NMAX], W[NMAX];

inline ll m(ll x, ll y) { return ((x % MOD) * (y % MOD)) % MOD; }
inline ll p(ll x, ll y) { return ((x % MOD) + (y % MOD)) % MOD; }

void dfs(int u, int parent)
{
    ll bu, wu;
    B[u] = (black[u]);  // B[u] = 1 if u is black, 0 otherwise
    W[u] = (!black[u]); // W[u] = 0 if u is black, 1 otherwise
    for (auto v : g[u])
    {
        if (v == parent)
            continue;
        dfs(v, u);

        bu   = B[u];
        wu   = W[u];
        B[u] = W[u] = 0;

        // Case 1: v is part of u's subtree
        W[u] = m(W[v], wu);
        B[u] = p(m(bu, W[v]), m(B[v], wu));
        // Case 2: v is not part of u' subtree
        W[u] = p(W[u], m(wu, B[v]));
        B[u] = p(B[u], m(bu, B[v]));
    }
}
int main(void)

{
    int pi, root;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> pi;
        g[pi].push_back(i + 1);
        g[i + 1].push_back(pi);
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> black[i];
        if (black[i])
            root = i;
    }
    dfs(root, -1);
    cout << B[root] << endl;

    return 0;
}
