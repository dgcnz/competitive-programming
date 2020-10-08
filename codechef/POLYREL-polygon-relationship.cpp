#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    int t, x, y;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> x >> y;

        ll ans = 0;
        do
        {
            ans += n;
            n /= 2;
        } while (n >= 3);

        cout << ans << endl;
    }
    return 0;
}
