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
    int n, m;
    cin >> n >> m;
    int r = 0;
    for (int k = 1; k <= m; k += 2, r++)
    {
        int a = (r - k + n) % n, b = r % n;
        cout << a + 1 << " " << b + 1 << endl;
    }

    int l = r;
    for (int k = 2 * (m / 2); k > 0; k -= 2, l++)
    {
        int a = l % n, b = (l + k) % n;
        cout << a + 1 << " " << b + 1 << endl;
    }

    return 0;
}
