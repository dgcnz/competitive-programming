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

ll sq(ll n) { return (n * (n + 1)) / 2; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, r;
        cin >> n >> r;
        ll kmax = min(r, n - 1);
        ll ans  = sq(kmax) + (kmax != r);
        cout << ans << endl;
    }
    return 0;
}
