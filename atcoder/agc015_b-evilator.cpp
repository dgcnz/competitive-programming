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
    cin >> s;

    int n = s.size(), ans = 0, d = 0, u = 0;
    for (int i = 1; i < n; ++i)
    {
        u += s[i] == 'U';
        ans += 1 + u;
    }

    for (int i = n - 2; i >= 0; --i)
    {
        d += s[i] == 'D';
        ans += 1 + d;
    }
    cout << ans << endl;

    return 0;
}
