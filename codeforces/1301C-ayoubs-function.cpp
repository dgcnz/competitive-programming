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

ll  sq(ll n) { return (n * (n + 1)) / 2; }
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll zeros = n - m, groups = m + 1, block = zeros / groups;

        ll ans = sq(n);
        ans -= sq(block) * (groups - (zeros % groups)) +
               sq(block + 1) * (zeros % groups);
        cout << ans << endl;
    }
    return 0;
}
