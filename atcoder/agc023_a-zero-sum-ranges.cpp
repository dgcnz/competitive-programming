#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll solve(vector<ll> a)
{
    map<ll, int> cnt;

    ll ans = 0, pa = 0;
    cnt[0] = 1;
    for (auto ai : a)
    {
        pa += ai;
        ans += cnt[pa];
        cnt[pa]++;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &ai : a)
        cin >> ai;

    cout << solve(a) << endl;
    return 0;
}
