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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll c, m, x;
        cin >> c >> m >> x;

        auto ok = [&](int k) {
            if (k > min(c, m))
                return false;
            return (c + m - 2 * k + x) >= k;
        };

        auto ans = *binary_search10(itll(0), itll(1e8 + 10), ok);
        cout << ans << endl;
    }
    return 0;
}
