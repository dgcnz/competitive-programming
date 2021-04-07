#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/segtree>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

using S = int;
S e() { return 1e9; }

S op(S a, S b) { return min(a, b); }

int solve(vi a, vi b)
{
    using RMinQuery = atcoder::segtree<S, op, e>;
    RMinQuery rmq(b);

    int n = a.size(), ans = 1e9;
    for (int i = 0; i < n; ++i)
    {
        ans = min(ans, a[i] + b[i]);
        ans = min(ans, max(a[i], min(rmq.prod(0, i), rmq.prod(i + 1, n))));
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];

    cout << solve(a, b) << endl;

    return 0;
}
