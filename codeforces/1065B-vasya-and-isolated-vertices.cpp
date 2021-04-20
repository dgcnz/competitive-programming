#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/divide_conquer/binary_search>
#include <cplib/utils/io>
#include <cplib/utils/number_iterator>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll ceil(ll a, ll b) { return (a + b - 1) / b; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll n, m;
    cin >> n >> m;

    if (n == 1)
    {
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    auto ok = [m](ll k) { return (k * (k - 1)) / 2 >= m; };

    ll minis = max(0LL, 2 * (ceil(n, 2) - m) - (n % 2));
    ll maxis = n - *binary_search01(itll(0), itll(n), ok);
    cout << minis << " " << maxis << endl;

    return 0;
}
