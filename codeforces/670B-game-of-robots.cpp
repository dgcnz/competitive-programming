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

ll sq(ll n) { return (n * (n + 1)) / 2; }

ll solve(vector<ll> id, ll k)
{
    ll ix = 1;
    while (sq(ix) < k)
        ++ix;
    return id[k - sq(ix - 1) - 1];
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<ll> id(n);
    for (auto &i : id)
        cin >> i;

    cout << solve(id, k) << endl;
    return 0;
}
