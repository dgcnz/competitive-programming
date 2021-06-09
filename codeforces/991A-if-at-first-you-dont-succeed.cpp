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
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    if (c > a or c > b)
    {
        cout << -1 << endl;
        return 0;
    }
    int ans = n - (a + b - c);
    if (ans >= 1)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}
