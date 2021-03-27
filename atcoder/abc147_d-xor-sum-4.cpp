#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace atcoder;
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using mint = modint1000000007;

int solve(vector<ll> a)
{
    int const   N = 62;
    int         n = a.size();
    vector<int> cnt(N, 0);
    for (auto ai : a)
        for (int i = 0; i < N; ++i)
            cnt[i] += (ai >> i) & 1;

    mint ans = 0;
    for (int i = 0; i < N; ++i)
        ans += mint(cnt[i] * ll(n - cnt[i])) * (1LL << i);
    return ans.val();
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
