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
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> pa(n);

    read(all(a));
    sort(all(a));
    partial_sum(all(a), begin(pa));

    int m;
    cin >> m;

    while (m--)
    {
        ll x, y;
        cin >> x >> y;

        auto cost = [&](auto it)
        {
            ll defense = pa.back() - *it;
            ll attack  = *it;
            return max(0LL, x - attack) + max(0LL, y - defense);
        };

        auto it  = upper_bound(all(a), x);
        ll   ans = x + y;
        if (it != a.end())
            ans = min(ans, cost(it));
        if (it != a.begin())
            ans = min(ans, cost(prev(it)));
        cout << ans << "\n";
    }
    return 0;
}
