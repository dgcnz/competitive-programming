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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll x;
        cin >> x;
        bool flag = false;
        for (ll n = 1; n == 1 || n * n - (n / 2) * (n / 2) <= x; ++n)
        {
            if (n * n < x)
                continue;
            int sq = sqrt(n * n - x);
            if (sq == 0)
                continue;
            int m = n / sq;
            if (m == 0)
                continue;
            if (n * n - (n / m) * (n / m) == x)
            {
                flag = true;
                cout << n << " " << m << endl;
                break;
            }
        }
        if (!flag)
            cout << -1 << endl;
    }
    return 0;
}
