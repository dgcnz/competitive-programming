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

ll solve(int n)
{
    ll ans = 1;
    for (int d = n; d > n / 2; --d)
        ans *= d;
    for (int d = 1; d <= n / 2; ++d)
        ans /= d;
    ans /= 2;

    ll cyclic = 1;
    for (int d = 1; d <= n / 2 - 1; ++d)
        cyclic *= d;

    return ans * cyclic * cyclic;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
