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
    string s;
    while (cin >> s and s == "start")
    {
        auto ask = [](ll x, ll y) {
            cout << "? " << x << " " << y << endl;
            cout.flush();
            char ans;
            cin >> ans;
            assert(ans != 'e');
            return ans;
        };

        ll x = 0, y = 1;
        if (ask(x, y) != 'x')
        {
            x = 1, y = 2;
            while (ask(x, y) != 'x')
                x *= 2, y *= 2;
        }

        auto ok = [x](int y) {
            cout << "? " << x << " " << y << endl;
            cout.flush();
            char ans;
            cin >> ans;
            assert(ans != 'e');
            return ans == 'x';
        };

        int l = x + 1, r = y;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (ok(m))
                r = m;
            else
                l = m + 1;
        }
        cout << "! " << l << endl;
        cout.flush();
    }
    assert(s == "end");

    return 0;
}
