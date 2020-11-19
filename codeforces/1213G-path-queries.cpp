/**
 * @title Path Queries
 * @url https://codeforces.com/contest/1213/problem/G
 * @status AC
 * @score 9
 * @difficulty 7
 * @tags dsu, trees, sorting, contribution_method, offline, binary_search
 * @reading_time 5
 * @thinking_time 15
 * @coding_time 40
 * @idea Sort edges increasingly and add them to a dsu in chunks of equal
 * weight. Compute answer for each weight. For queries, binary search the
 * answer.
 * @time_complexity O(m*log(n))
 * @memory_complexity O(n)
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll  = long long;
using ii  = pair<int, int>;
using iii = array<int, 3>;
using vi  = vector<int>;

template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void read_n(InputIterator it, int n)
{
    copy_n(istream_iterator<T>(cin), n, it);
}

template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void write(InputIterator first, InputIterator last, const char *delim = "\n")
{
    copy(first, last, ostream_iterator<T>(cout, delim));
}

struct DisjointSetUnion
{
    using vi = vector<int>;
    using ll = long long;

    int n;
    ll  ans = 0;
    vi  parent, ssize;

    DisjointSetUnion(int n) : n(n)
    {
        parent.resize(n);
        ssize.resize(n, 1);
        for (int u = 0; u < n; ++u)
            parent[u] = u;
    }

    int find_set(int u)
    {
        if (u == parent[u])
            return u;
        return (parent[u] = find_set(parent[u])); // path compression
    }

    inline ll contribution(ll m) { return (m * (m - 1)) / 2; }

    void union_sets(int u, int v)
    {
        u = find_set(u);
        v = find_set(v);
        if (u != v)
        {
            if (ssize[u] < ssize[v]) // union by size
                swap(u, v);
            ans -= contribution(ssize[v]);
            ans -= contribution(ssize[u]);
            ans += contribution(ssize[u] + ssize[v]);
            parent[v] = u;
            ssize[u] += ssize[v];
        }
    }
};

ll const INF = 1e16;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<iii> edges(n - 1);
    for (auto &[w, u, v] : edges)
        cin >> u >> v >> w, u--, v--;

    DisjointSetUnion      dsu(n);
    vector<pair<int, ll>> ans = {{0, 0}};

    sort(all(edges));

    auto it = edges.begin();
    while (it != end(edges))
    {
        auto it_temp = it;
        while (it_temp != end(edges) and it_temp->at(0) == it->at(0))
        {
            dsu.union_sets(it_temp->at(1), it_temp->at(2));
            it_temp++;
        }
        ans.emplace_back(it->at(0), dsu.ans);
        it = it_temp;
    }

    while (m--)
    {
        int qi;
        cin >> qi;
        auto it = prev(upper_bound(all(ans), make_pair(qi, INF)));
        cout << it->second << " ";
    }
    cout << endl;

    return 0;
}
