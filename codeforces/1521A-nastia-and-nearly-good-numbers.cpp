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
        ll a, b;
        cin >> a >> b;
        if (b > 1)
        {
            cout << "YES" << endl;
            if (b == 2)
                b *= 2;
            ll z = a * b, x = a, y = z - a;
            cout << x << " " << y << " " << z << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}
