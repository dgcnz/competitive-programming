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
        vi s(4);
        read(all(s));
        int maxl = max(s[0], s[1]);
        int maxr = max(s[2], s[3]);
        if (maxr < maxl)
            swap(maxl, maxr);
        sort(all(s));
        bool ok = maxr == s[3] and maxl == s[2];
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}
