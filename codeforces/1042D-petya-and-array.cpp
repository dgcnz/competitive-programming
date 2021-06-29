#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using namespace __gnu_pbds;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

typedef tree<pair<ll, int>,
             null_type,
             less<pair<ll, int>>,
             rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

ll solve(vector<ll> a, ll t)
{
    using plli   = pair<ll, int>;
    int        n = a.size();
    vector<ll> pa(n);
    partial_sum(all(a), begin(pa));

    ll          ans = 0;
    ordered_set pa_l;
    pa_l.insert(plli{0, -1});
    for (int r = 0; r < n; ++r)
    {
        auto it = pa_l.upper_bound(plli{pa[r] - t, (int)2e5});
        ans += distance(it, pa_l.end());
        // if (it != pa_l.end())
        // {
        //     int k = pa_l.order_of_key(*it);
        //     ans += r + 1 - k;
        // }
        pa_l.insert(plli{pa[r], r});
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    ll  t;
    cin >> n >> t;
    vector<ll> a(n);
    read(all(a));

    cout << solve(a, t) << endl;
    return 0;
}
