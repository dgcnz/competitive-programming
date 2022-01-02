#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    read(all(a));

    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans = max(ans, a[i]);
        for (int j = i + 1; j < n; ++j)
        {
            ans = max(ans, a[i] | a[j]);
            for (int k = j + 1; k < n; ++k)
            {
                ans = max(ans, a[i] | a[j] | a[k]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
