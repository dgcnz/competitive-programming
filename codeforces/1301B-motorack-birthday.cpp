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
        int n;
        cin >> n;
        vi a(n);
        read(all(a));
        auto f = [&](int k) {
            int ans = 0;
            for (int i = 1; i < n; ++i)
            {
                int cur  = a[i] == -1 ? k : a[i],
                    prev = a[i - 1] == -1 ? k : a[i - 1];
                ans      = max(ans, abs(cur - prev));
            }
            return ans;
        };
        auto  ok = [&](int k) { return f(k + 1) >= f(k); };
        itint l(0), r(1e9 + 10);
        int   k = *binary_search01(l, r, ok);
        int   m = f(k);
        cout << m << " " << k << endl;
    }
    return 0;
}
