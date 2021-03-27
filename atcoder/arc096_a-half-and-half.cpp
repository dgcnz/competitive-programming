#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = 1e9;
    for (int kab = 0; kab <= 2 * max(x, y); kab += 2)
    {
        int ka = max(0, x - kab / 2), kb = max(0, y - kab / 2);
        ans = min(ans, a * ka + c * kab + b * kb);
    }
    cout << ans << endl;
    return 0;
}
