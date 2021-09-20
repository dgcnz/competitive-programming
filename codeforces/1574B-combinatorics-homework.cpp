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
        vi  v(3);
        int m;
        read(all(v));
        cin >> m;
        sort(all(v), greater<int>());

        int m0 = max(0, v[0] - (v[1] + v[2] + 1));
        int mx = max(0, v[0] + v[1] + v[2] - 3);
        if (m0 <= m and m <= mx)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
