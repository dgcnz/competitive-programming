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

ll iceil(ll a, ll b) { return (a + b - 1) / b; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }

        n--;
        ll mx = 1, steps = 0;
        while (n > 0 and mx <= k)
        {
            steps++;
            n -= mx;
            mx *= 2;
        }
        // dbg(n, mx, steps);

        mx = min(k, mx);
        steps += iceil(n, mx);
        cout << steps << endl;
    }
    return 0;
}
