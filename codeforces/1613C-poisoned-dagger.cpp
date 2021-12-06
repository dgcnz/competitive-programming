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
    const ll INF = 2e18;
    int      t;
    cin >> t;
    while (t--)
    {
        int n;
        ll  h;
        cin >> n >> h;

        vector<ll> a(n);
        read(all(a));
        a.push_back(INF);

        auto f = [&](ll k)
        {
            ll prev = a.front();
            ll acc  = 0;
            for (auto ai : a)
            {
                acc += min(k, ai - prev);
                prev = ai;
            }
            return acc;
        };
        auto ok = [&](ll k) { return f(k) >= h; };

        itll l(0), r(INF);
        auto k = *binary_search01(l, r, ok);
        cout << k << endl;
    }
    return 0;
}
