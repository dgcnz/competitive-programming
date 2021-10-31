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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(n);
        read(all(a));

        bool inv = false;
        for (int i = 1; i < n; ++i)
            inv |= a[i] <= a[i - 1];

        cout << ((n % 2 == 0) or (n % 2 == 1 and inv > 0) ? "YES" : "NO")
             << endl;
    }
    return 0;
}
