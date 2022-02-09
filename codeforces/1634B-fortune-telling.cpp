#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/math/misc>
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
        int n;
        ll  x, y;
        cin >> n >> x >> y;

        vector<ll> a(n);
        read(all(a));

        int odds  = count_if(all(a), [](int ai) { return ai % 2; });
        int y_rem = (y + odds) % 2;

        if (y_rem == x % 2)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }
    return 0;
}
