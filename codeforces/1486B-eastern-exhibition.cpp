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
        int n;
        cin >> n;
        vector<int> x(n), y(n);
        for (int i = 0; i < n; ++i)
            cin >> x[i] >> y[i];

        if (n % 2)
            cout << 1 << endl;
        else
        {
            sort(all(x));
            sort(all(y));
            ll dx = x[n / 2] - x[n / 2 - 1] + 1;
            ll dy = y[n / 2] - y[n / 2 - 1] + 1;
            cout << dx * dy << endl;
        }
    }
    return 0;
}
