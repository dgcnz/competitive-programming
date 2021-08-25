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
    int ca, ba, pa, cr, br, pr;
    cin >> ca >> ba >> pa;
    cin >> cr >> br >> pr;

    int ans = max(0, cr - ca) + max(0, br - ba) + max(0, pr - pa);
    cout << ans << endl;
    return 0;
}
