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
using mint = modint1000000007;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vi ps(n);
    ps[0] = s[0] - '0';
    for (int i = 1; i < n; ++i)
        ps[i] = ps[i - 1] + (s[i] - '0');

    auto ones = [&](int l, int r) { return ps[r] - (l > 0 ? ps[l - 1] : 0); };

    while (q--)
    {
        int l, r;
        cin >> l >> r, l--, r--;
        int  o = ones(l, r), z = r - l + 1 - o;
        mint ans = mint(2).pow(o) - 1;
        ans *= mint(2).pow(z);
        cout << ans.val() << endl;
    }
    return 0;
}
