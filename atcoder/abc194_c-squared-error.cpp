#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/fenwicktree>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll solve(vector<ll> a)
{
    using namespace atcoder;

    int n = a.size();
    sort(all(a));

    fenwick_tree<ll> sum(n), sq(n);
    for (int i = 0; i < n; ++i)
        sum.add(i, a[i]), sq.add(i, a[i] * a[i]);

    ll ans = 0;
    for (int i = n - 1; i > 0; i--)
        ans += i * a[i] * a[i] + sq.sum(0, i) - 2 * a[i] * sum.sum(0, i);

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cout << solve(a) << endl;
    return 0;
}
