#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <set>
#include <stdio.h>
#include <vector>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
#define FASTIO                                                                 \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(0);                                                                \
    cout.tie(0);
using namespace std;

typedef long long          ll;
typedef long double        ld;
typedef unsigned long long ull;
typedef pair<int, int>     pii;
typedef pair<ll, ll>       pll;
typedef vector<int>        vi;
typedef vector<ll>         vll;
typedef vector<char>       vc;
typedef vector<bool>       vb;

/*
------------- ANÁLISIS DE LA IDEA -------------


------------- ANÁLISIS DE COMPLEJIDAD TEMPORAL -------------



------------- ANÁLISIS DE COMPLEJIDAD ESPACIAL -------------
*/

const int  N = 1e6 + 10;
ll         n, m, x;
vector<ll> a;
ll         u, v;
ll dp[1011][1011]; // dp[u][c] maxima suma posible de pastillas terminando en el
                   // piso u, y habiendo visitado c pisos.

void solver(vector<vector<ll>> graph)
{
    int const   NMAX = 1011;
    int const   CMAX = 1011;
    int const   INF  = 1e9;
    vector<vi>  dp(NMAX, vi(CMAX, 0));
    vector<int> best(NMAX, 0);

    set<pii> frontier;
    frontier.emplace(0, 0);

    while (!frontier.empty())
    {
        auto [u, C] = *frontier.begin();
        frontier.erase(frontier.begin());
        if (C >= CMAX)
            break;
        auto penalty = (C + 1) * (C + 1) * x;
        for (auto v : graph[u])
        {
            auto new_score = dp[u][C] + a[v];
            if (new_score > dp[v][C + 1] && new_score - penalty >= best[v])
            {
                dp[v][C + 1] = new_score;
                best[v]      = new_score - penalty;
                frontier.emplace(v, C + 1);
            }
        }
    }
    cout << best[0] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> x;
    ll temp;
    for (ll i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    vector<vector<ll>> graph(n);
    for (ll i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
    }
    solver(graph);
    return 0;
}
