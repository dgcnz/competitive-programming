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
    int n, m;
    cin >> n >> m;

    vi a(n);
    read(all(a));
    decrement(all(a));
    vi  sigma = inverse_permutation(a);
    int ans   = 1;
    for (int i = 1; i < n; ++i)
        ans += sigma[i - 1] > sigma[i];

    while (m--)
    {
        int i, j;
        cin >> i >> j, i--, j--;
        for (int k = 0, sign = -1; k < 2; sign *= -1, k++)
        {
            set<int> b;
            if (a[i] > 0)
                b.emplace(a[i]);
            if (a[i] + 1 < n)
                b.emplace(a[i] + 1);
            if (a[j] > 0)
                b.emplace(a[j]);
            if (a[j] + 1 < n)
                b.emplace(a[j] + 1);
            for (auto ix : b)
                ans += sign * (sigma[ix - 1] > sigma[ix]);
            if (k == 0)
            {
                sigma[a[i]] = j;
                sigma[a[j]] = i;
                swap(a[i], a[j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
