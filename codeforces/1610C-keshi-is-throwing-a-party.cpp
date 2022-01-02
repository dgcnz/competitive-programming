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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i] >> b[i];

        itint first(0), last(n + 1);
        auto  ok = [&](int k)
        {
            if (k == 0 or k == 1)
                return true;

            int got = 0;
            for (int i = 0; i < n; ++i)
                if (b[i] >= got and a[i] >= k - got - 1)
                    ++got;
            // dbg(k, got);
            return got >= k;
        };
        auto it = binary_search10(first, last, ok);
        cout << *it << endl;
    }
    return 0;
}
