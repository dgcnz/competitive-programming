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
    int n;
    cin >> n;
    n--;

    int ans = 0;
    if (n)
    {
        int a, b, c;
        cin >> a >> b >> c;
        auto [cost, ix] = min(ii{a, 2}, ii{b, 3});
        ans += cost;
        n--;
        if (n)
        {
            if (ix == 2)
            {
                auto [cost, ix] = min(ii{a, 1}, ii{c, 3});
                ans += n * cost;
                n = 0;
            }
            else
            {
                auto [cost, ix] = min(ii{b, 1}, ii{c, 2});
                ans += n * cost;
                n = 0;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
