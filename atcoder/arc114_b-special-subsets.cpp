#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/dsu>
#include <atcoder/modint>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace atcoder;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int solve(vi f)
{
    using mint = modint998244353;

    int n = f.size();
    dsu g(n);
    for (int i = 0; i < n; ++i)
        g.merge(i, f[i]);

    int m = g.groups().size();
    return mint(2).pow(m).val() - 1;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi f(n);
    for (auto &fi : f)
        cin >> fi, fi--;

    cout << solve(f) << endl;
    return 0;
}
