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

inline bool maxima(int a, int b, int c) { return a <= b and b >= c; }

inline bool minima(int a, int b, int c) { return a >= b and b <= c; }

int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;

        vi a(n + 2, 0); // pad first, last with 0
        for (int i = 1; i <= n; ++i)
            cin >> a[i];

        bool increasing = true;
        ll   ans        = 0;
        for (int i = 1; i <= n; ++i)
        {
            // dbg(i, a[i - 1], a[i], a[i + 1], increasing);
            // dbg(maxima(a[i - 1], a[i], a[i + 1]));
            // dbg(minima(a[i - 1], a[i], a[i + 1]));

            if (maxima(a[i - 1], a[i], a[i + 1]) and increasing)
            {
                ans += a[i];
                increasing = false;
            }
            else if (minima(a[i - 1], a[i], a[i + 1]) and not increasing)
            {
                ans -= a[i];
                increasing = true;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
