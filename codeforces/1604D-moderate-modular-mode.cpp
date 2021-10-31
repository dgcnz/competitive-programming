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
        ll x, y;
        cin >> x >> y;

        if (x == y)
        {
            cout << x << endl;
        }
        else if (x > y)
        {
            cout << x + y << endl;
        }
        else
        {
            cout << ((y / x) * x + y) / 2 << endl;
        }
    }
    return 0;
}
