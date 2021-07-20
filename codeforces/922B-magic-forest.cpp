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
    int n;
    cin >> n;

    int ans = 0;
    for (int c = 1; c <= n; ++c)
    {
        for (int a = 1; a <= c; ++a)
        {
            int b = c ^ a;
            ans += (a + b > c) and (a <= b and b <= c);
        }
    }
    cout << ans << endl;
    return 0;
}
