/** @file
 * @date                2020-12-11
 * @url                 https://atcoder.jp/contests/abc177/tasks/abc177_d
 * @tags                dsu, data_structures
 * @status              AC
 * @score               3
 * @difficulty          2
 * @editorial           no
 * @reading_time        2
 * @thinking_time       10
 * @coding_time         20
 * @time_complexity     O(m \log^*{n})
 * @memory_complexity   O(n)
 * @idea
 * Note that the the transitive and symmmetric properties of friendship
 * described on the problem statement imply that we'll have fully connected hubs
 * of people that are mutually friends.
 *
 * The only way to divide the people in groups where no two people are
 * friends would be to place all the members of a friendship group in different
 * answer groups.
 *
 * Note that the upper bound on groups created would be equal to the size of the
 * biggest friendship hub. Use a Disjoint Set Structure to maintain such hubs
 * efficiently.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

struct UnionFind
{
    int n;
    vi  parent, sz;
    UnionFind(int n) : n(n)
    {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; ++i)
            make_set(i);
    }
    void make_set(int v)
    {
        parent[v] = v;
        sz[v]     = 1;
    }
    int find_set(int v)
    {
        if (v == parent[v])
            return v;
        return (parent[v] = find_set(parent[v]));
    }
    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
    int biggest_component(void)
    {
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (i == find_set(i))
                ans = max(ans, sz[i]);
        return ans;
    }
};

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    UnionFind dsu(n);
    while (m--)
    {
        int a, b;
        cin >> a >> b, a--, b--;
        dsu.union_sets(a, b);
    }
    cout << dsu.biggest_component() << endl;

    return 0;
}
