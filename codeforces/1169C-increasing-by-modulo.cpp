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
    int n, m;
    cin >> n >> m;
    vi a(n);
    read(all(a));

    auto ok = [&](int k) {
        vi b(a);
        b[n - 1] = min(a[n - 1] + k, m - 1) % m;
        for (int i = n - 2; i >= 0; --i)
        {
            if (b[i] > b[i + 1])
            {
                b[i] = b[i] + k;
                if (b[i] >= m)
                    b[i] = min(b[i] % m, b[i + 1]);
            }
            else
                b[i] = min(b[i] + k, b[i + 1]) % m;
        }
        return is_sorted(all(b));
    };

    itint l(0), r(m);
    int   k = *binary_search01(l, r, ok);
    cout << k << endl;
    return 0;
}
