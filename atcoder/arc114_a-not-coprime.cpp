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

ll solve(vector<int> x)
{
    vector<int> primes = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    int NP = primes.size();

    ll ans = accumulate(all(primes), 1LL, multiplies<ll>());

    for (int mask = 1; mask < (1 << NP); ++mask)
    {
        ll y = 1;
        for (int i = 0; i < NP; ++i)
            if ((mask >> i) & 1)
                y *= primes[i];

        if (all_of(all(x), [y](int xi) { return gcd(y, xi) != 1; }))
            ans = min(y, ans);
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> x(n);
    for (auto &xi : x)
        cin >> xi;
    cout << solve(x) << endl;
    return 0;
}
