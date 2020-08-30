#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define sz(c) (int)c.size()

using namespace std;
using vi = vector<int>;

int const INF  = 1e9;
int const NMAX = 2e5 + 11;

int        k, best_cost[NMAX];
deque<int> costs[NMAX]; // sorted by default

void build() { fill(best_cost, best_cost + NMAX, INF); }
int  query(int x) { return sz(costs[x]) == k ? best_cost[x] : INF; }
void insert(int x, int cur_cost)
{
    if (sz(costs[x]) == 0)
        best_cost[x] = 0;
    costs[x].push_back(cur_cost);

    if (sz(costs[x]) > k)
    {
        best_cost[x] -= costs[x].front();
        costs[x].pop_front();
    }
    best_cost[x] += cur_cost;
}

int solve(vi a)
{
    int        ans = INF;
    vi         cnt(NMAX, 0);
    vector<vi> best_cost(NMAX, vi(log2(NMAX) + 5, 0));

    sort(all(a));
    for_each(a.rbegin(), a.rend(), [&ans](int ai) {
        for (int i = 0, m = log2(ai) + 2; i < m; ++i, ai /= 2)
        {
            insert(ai, i);
            ans = min(ans, query(ai));
        }
    });
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n;
    vi  a;

    cin >> n >> k;
    a.resize(n);
    for (auto &ai : a)
        cin >> ai;

    build();
    cout << solve(a) << endl;

    return 0;
}
