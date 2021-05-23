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
    int n, p, k;
    cin >> n >> p >> k;
    mint::set_mod(p);

    vi a(n), b(n);
    read(all(a));
    transform(all(a), begin(b), [k](int ai) {
        return (mint(ai).pow(4) - k * mint(ai)).val();
    });

    map<int, int> cnt;
    ll            ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += cnt[b[i]];
        cnt[b[i]]++;
    }
    cout << ans << endl;
    return 0;
}
