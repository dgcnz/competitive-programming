#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
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
        ll n;
        cin >> n;
        if (n % 2 == 0)
        {
            cout << 2 << " " << n - 3 << " " << 1 << "\n";
        }
        else
        {
            for (ll a = 2; a < n - 1; ++a)
            {
                if (gcd(a, n - a - 1) == 1)
                {
                    cout << a << " " << n - a - 1 << " " << 1 << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}
