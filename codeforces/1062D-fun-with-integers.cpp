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
    int n;
    cin >> n;
    ll ans = 0;
    for (int x = 2; x < n; ++x)
    {
        int cnt = n / x - 1;
        if (cnt <= 0)
            break;
        ans += 4 * (sq(cnt + 1) - 1);
    }
    cout << ans << endl;
    return 0;
}
