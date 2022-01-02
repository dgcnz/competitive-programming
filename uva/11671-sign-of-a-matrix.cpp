#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/graph/graph>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

template <typename W, W INF = numeric_limits<W>::max()>
struct SPFA
{
    Graph<W> const &g;
    vector<W>       dist;
    SPFA(Graph<W> const &g) : g(g) {}
    bool operator()(int s)
    {
        int n = g.size();
        dist.assign(n, INF);
        vector<int>  cnt(n, 0);
        vector<bool> inqueue(n, false);
        queue<int>   q;

        dist[s] = 0;
        q.push(s);
        inqueue[s] = true;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            inqueue[v] = false;

            for (auto edge : g[v])
            {
                int to  = edge.first;
                int len = edge.second;

                if (dist[v] + len < dist[to])
                {
                    dist[to] = dist[v] + len;
                    if (!inqueue[to])
                    {
                        q.push(to);
                        inqueue[to] = true;
                        cnt[to]++;
                        if (cnt[to] > n)
                            return false; // negative cycle
                    }
                }
            }
        }
        return true;
    }
};

int solve(vector<string> a)
{
    int n = a.size();
    // 0: Make difference constraints
    // https://courses.csail.mit.edu/6.006/spring11/lectures/lec17.pdf

    // 1: Construct graph on difference constraints
    Graph<int> g(2 * n + 1);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (a[i][j] == '+')
                g.add_edge(j + n, i, -1);
            else if (a[i][j] == '-')
                g.add_edge(i, j + n, -1);
            else
                g.add_undirected_edge(i, j + n, 0);
        }
    }

    // 2: Add dummy fully-connected 0-weight vertex for mssp
    for (int i = 0; i < 2 * n; ++i)
        g.add_edge(2 * n, i, 0);

    SPFA<int> spfa(g);

    if (spfa(2 * n)) // negative cycles mean no answer
    {
        auto d = spfa.dist;
        d.pop_back(); // remove dummy node
        sort(all(d));

        int median = d[n];
        ll  ans    = 0;
        for (auto di : d)
            ans += abs(di - median);
        return ans;
    }
    else
        return -1;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, tc = 1;
    while (cin >> n and n != -1)
    {
        vector<string> a(n);
        read(all(a));
        cout << "Case " << tc++ << ": " << solve(a) << endl;
    }
    return 0;
}
