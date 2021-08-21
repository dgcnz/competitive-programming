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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    read(all(a));

    ll sum = 0, minv = *min_element(all(a)), ans = 0;
    for (int i = 0; i < k; ++i)
        sum += a[i];

    for (int i = k - 1; sum >= 0 and i >= 0; --i)
    {
        ll delta = min(sum + 1, a[i] - minv);
        ans += delta;
        a[i] -= delta;
        sum -= delta;
    }
    for (int i = k; i < n; ++i)
    {
        sum -= a[i - k];
        if (sum + a[i] >= 0)
        {
            int delta = a[i] - (-sum - 1);
            ans += delta;
            a[i] -= delta;
        }
        sum += a[i];
    }
    cout << ans << endl;
    write(all(a), " "), cout << endl;

    return 0;
}
