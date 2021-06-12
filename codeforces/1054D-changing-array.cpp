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

ll C2(ll n) { return (n * (n - 1)) / 2LL; }

ll solve(vi a, int k)
{
    map<int, int> cnt;
    int           n = a.size(), sum = 0;
    ll            ans = 0;
    cnt[0]            = 1;
    for (auto ai : a)
    {
        sum ^= min(ai, (1 << k) - 1 - ai);
        cnt[sum]++;
    }
    for (auto [p, c] : cnt)
        ans += C2(c / 2) + C2((c + 1) / 2);
    return C2(n + 1) - ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vi a(n);
    read(all(a));
    cout << solve(a, k) << endl;
    return 0;
}
