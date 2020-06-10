#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

struct edge
{
    int a, b, c;
};

const int INF = 1e9;

int          n, m;
vector<edge> edges;

bool solve(void)
{
    vi d(n, INF);
    d[0] = 0;

    bool negcycle;

    // If any change is made on the n-th iteration of bellman-ford, then a
    // negative cycle is reachable from the source node

    for (int i = 0; i < n; ++i)
    {
        negcycle = false;
        for (const auto &e : edges)
        {
            if (d[e.a] < INF and d[e.b] > d[e.a] + e.c)
            {
                d[e.b]   = max(-INF, d[e.a] + e.c);
                negcycle = true;
            }
        }
    }

    return negcycle;
}

int main(void)
{
    int t; // number of test cases
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        edges.assign(m, {});
        for (auto &e : edges)
            cin >> e.a >> e.b >> e.c;

        cout << (solve() ? "possible" : "not possible") << endl;
    }

    return 0;
}
