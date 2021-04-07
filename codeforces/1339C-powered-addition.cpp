#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/divide_conquer/binary_search>
#include <cplib/math/binary_exponentiation>
#include <cplib/utils/io>
#include <cplib/utils/number_iterator>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll solve(vector<ll> a)
{
    auto ok = [&](int t) {
        ll prev = a.front();
        ll maxv = binpow(ll(2), ll(t)) - 1;
        for (auto ai : a)
        {
            if (ai < prev)
            {
                if (prev - ai > maxv)
                    return false;
                ai = prev;
            }
            prev = ai;
        }
        return true;
    };

    int  amax = 2 * max(*max_element(all(a)), abs(*min_element(all(a))));
    auto l = itint(0), r = itint(log2(amax) + 10);
    int  t = *binary_search01(l, r, ok);
    return t;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        read(all(a));
        cout << solve(a) << endl;
    }
    return 0;
}
