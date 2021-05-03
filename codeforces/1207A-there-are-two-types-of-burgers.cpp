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
    int t;
    cin >> t;
    while (t--)
    {
        int b, p, f, h, c;
        cin >> b >> p >> f >> h >> c;
        if (h < c)
            swap(h, c), swap(p, f);

        int burgers = min(p, b / 2);
        b -= burgers * 2;
        p -= burgers;
        int ans = burgers * h;
        ans += c * min(b / 2, f);
        cout << ans << endl;
    }
    return 0;
}
