#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll  = long long;
using ii  = pair<int, int>;
using vi  = vector<int>;
using vll = vector<ll>;

int const MOD = 1e9 + 7;

int const SMAX = 2000 + 11;
ll        mem[SMAX];
bool      vis[SMAX];

ll add(ll a, ll b) { return ((a + MOD % MOD) + (b + MOD % MOD)) % MOD; }

ll dp(int s)
{
    if (s == 0)
        return 1;
    if (vis[s])
        return mem[s];

    ll &ans = mem[s];
    vis[s]  = true;
    for (int d = 3; d <= s; ++d)
        ans = add(ans, dp(s - d));
    return ans;
}

int main(void)
{
    int s;
    cin >> s;
    cout << dp(s) << endl;

    return 0;
}
