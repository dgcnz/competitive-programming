#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

struct BitTrie
{
    int                   n;
    vector<array<int, 2>> t;

    BitTrie() : n(0), t(1) {}
    int new_node()
    {
        t.push_back(array<int, 2>());
        fill(all(t.back()), 0);
        return ++n;
    }

    template <size_t BITS>
    void add(bitset<BITS> a, bool reverse = true)
    {
        static_assert(BITS > 0);
        int cur = 0, first = (reverse ? BITS - 1 : 0),
            last = (reverse ? -1 : n), delta = (reverse ? -1 : +1);
        for (int i = first; i != last; i += delta)
        {
            if (!t[cur][a[i]])
                t[cur][a[i]] = new_node();
            cur = t[cur][a[i]];
        }
    }

    array<int, 2> &operator[](int u) { return t[u]; }
    array<int, 2>  operator[](int u) const { return t[u]; }
};

int solve(vi a)
{
    BitTrie t;
    for (auto ai : a)
        t.add(bitset<31>(ai));

    ii ans = {(1 << 30) - 1, (1 << 30) - 1};

    function<void(int, int, int, int)> dfs =
        [&](int u, int i = 31, int x = 0, int axorx = 0) {
            auto [v0, v1] = t[u];
            if (v0 and v1)
                dfs(v0, i - 1, (x << 1), (axorx << 1) | 1),
                    dfs(v1, i - 1, (x << 1), (axorx << 1) | 1);
            else if (v0)
                dfs(v0, i - 1, (x << 1), (axorx << 1));
            else if (v1)
                dfs(v1, i - 1, (x << 1) | 1, (axorx << 1));
            else
                ans = min(ans, {axorx, x});
        };
    dfs(0, 31, 0, 0);
    return ans.first;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    read(all(a));

    cout << solve(a) << endl;
    return 0;
}
