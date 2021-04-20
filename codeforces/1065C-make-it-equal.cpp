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

ll solve(vector<ll> h, ll k)
{
    sort(all(h));
    int        n = h.size();
    vector<ll> ph(n);
    partial_sum(all(h), ph.begin());

    auto sum = [&](int l, int r) { return ph[r] - (l ? ph[l - 1] : 0); };
    ll   ch = h.back(), cut = 0, ans = 0;
    auto cost = [&](ll height) {
        auto it = upper_bound(all(h), height);
        int  j  = distance(h.begin(), it);
        return sum(j, n - 1) - height * (n - j) - cut;
    };
    while (ch > h.front())
    {
        while (cost(ch - 1) <= k)
            ch--;
        cut += cost(ch);
        ans += 1;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    ll  k;
    cin >> n >> k;
    vector<ll> h(n);
    read(all(h));
    cout << solve(h, k) << endl;
    return 0;
}
