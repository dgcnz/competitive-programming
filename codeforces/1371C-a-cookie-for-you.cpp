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

string solve(ll a, ll b, ll n, ll m)
{
    return (a + b < n + m) or (m > min(a, b)) ? "NO" : "YES";
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, n, m;
        cin >> a >> b >> n >> m;
        cout << solve(a, b, n, m) << endl;
    }
    return 0;
}
