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
using ll  = long long;
using ii  = pair<int, int>;
using pll = pair<ll, ll>;
using vi  = vector<int>;

ll solve(vector<pll> ba)
{
    int n = ba.size();
    sort(all(ba));
    int l = 0, r = n - 1;
    ll  cnt = 0, ans = 0;
    while (l <= r)
    {
        while (r >= l and (ba[l].second and ba[l].first > cnt))
        {
            ll k = min(ba[l].first - cnt, ba[r].second);
            ans += 2 * k;
            cnt += k;
            ba[r].second -= k;
            if (ba[r].second == 0)
                r--;
        }
        cnt += ba[l].second;
        ans += ba[l].second;
        l++;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<pll> ba(n);
    for (auto &[b, a] : ba)
        cin >> a >> b;
    cout << solve(ba) << endl;
    return 0;
}
