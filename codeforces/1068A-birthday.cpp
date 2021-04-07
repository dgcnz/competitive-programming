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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll n, m, k, l;
    cin >> n >> m >> k >> l;
    ll c = (k + l + m - 1) / m;
    if (m * c > n)
        cout << -1 << endl;
    else
        cout << c << endl;

    return 0;
}
