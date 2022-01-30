#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
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
        int a, b;
        cin >> a >> b;
        int ans = b - a, inc = 0;
        while (a < b)
        {
            int x = a, y = b;
            for (int i = 21; i >= 0; --i)
            {
                if ((a >> i) & 1 and not((b >> i) & 1))
                    break;
                x &= ~(1 << i);
                y &= ~(1 << i);
            }
            ans = min(ans, inc + x - y + 1);
            a++;
            inc++;
        }
        cout << ans << endl;
    }
    return 0;
}
