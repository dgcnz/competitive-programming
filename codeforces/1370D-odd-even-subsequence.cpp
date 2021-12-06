#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/divide_conquer/binary_search>
#include <cplib/utils/io>
#include <cplib/utils/misc>
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
    int n, k;
    cin >> n >> k;
    vi a(n);
    read(all(a));

    auto ok = [&](bool odd, int x)
    {
        bool minimize = odd;
        int  m        = k;
        for (int i = 0; i < n; ++i)
        {
            if (minimize and a[i] <= x)
                m--, minimize = !minimize;
            else if (!minimize)
                m--, minimize = !minimize;
        }
        return m <= 0;
    };

    using placeholders::_1;
    auto ok_odd  = bind(ok, true, _1);
    auto ok_even = bind(ok, false, _1);

    int const INF = 1e9;
    itint     l(1), r(INF);

    auto ans = *binary_search01(l, r, ok_odd);
    ans      = min(ans, *binary_search01(l, r, ok_even));

    cout << ans << endl;

    return 0;
}
