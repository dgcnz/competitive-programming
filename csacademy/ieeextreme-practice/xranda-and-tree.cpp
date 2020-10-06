#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

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

template <long long M, typename T = long long>
class NumMod
{
    static_assert(std::is_integral<T>::value, "Integral required.");
    T x;

  public:
    NumMod<M, T>(T x) : x(x) {}
    void         operator=(const T &y) { x = y % M; }
    explicit     operator T() const { return x; }
    NumMod<M, T> operator+(NumMod<M, T> y) { return (x + y.x) % M; }
    NumMod<M, T> operator+(T y) { return this->operator+(NumMod<M, T>(y)); }
    NumMod<M, T> operator*(NumMod<M, T> y) { return (x * y.x) % M; }
    NumMod<M, T> operator*(T y) { return this->operator*(NumMod<M, T>(y)); }
};

int const MOD = 1e9 + 7;

int find_root(int u, vi &root)
{
    if (root[u] == u)
        return u;
    return root[u] = find_root(root[u], root);
}

ll solve(int n, vector<pair<int, ii>> edges)
{
    NumMod<MOD> ans(0);
    vi          root(n + 1), sz(n + 1, 1);
    for (int i = 1; i <= n; ++i)
        root[i] = i;
    sort(all(edges));

    for (auto [w, uv] : edges)
    {
        int u = find_root(uv.first, root), v = find_root(uv.second, root);
        ans     = ans + (NumMod<MOD>(w) * sz[u] * sz[v]);
        root[u] = v;
        sz[v] += sz[u];
    }
    return ll(ans);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    vector<pair<int, ii>> edges;

    int n;
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        int w, u, v;
        cin >> u >> v >> w;
        edges.emplace_back(w, ii{u, v});
    }
    cout << solve(n, edges) << endl;

    return 0;
}
