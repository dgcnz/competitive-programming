#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using namespace atcoder;
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using mint = modint;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll n, x, m;
    cin >> n >> x >> m, n--;

    mint::set_mod(m);
    vector<int> vis(m, -1);
    vector<ll>  psum(2 * m, 0);
    ll          i = 0;
    mint        y = x;
    while (vis[y.val()] == -1)
    {
        psum[i] = y.val();
        if (i > 0)
            psum[i] += psum[i - 1];
        vis[y.val()] = i++;
        y *= y;
    }

    auto sum = [&](int l, int r) { return psum[r] - (l ? psum[l - 1] : 0); };
    if (n < i)
        cout << psum[n] << endl;
    else
    {
        ll first = vis[y.val()], last = i - 1, d = last - first + 1;
        n -= last + 1;
        ll ans = psum[last];
        ans += (n / d) * sum(first, last);
        ans += sum(first, first + n % d);
        cout << ans << endl;
    }

    return 0;
}
