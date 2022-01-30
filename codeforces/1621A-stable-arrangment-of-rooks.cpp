#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
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

ll iceil(ll a, ll b) { return (a + b - 1) / b; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (iceil(n, 2) >= k)
        {
            vector<string> ans(n, string(n, '.'));
            for (int i = 0, cnt = 0; cnt < k and i < n; i += 2, cnt++)
                ans[i][i] = 'R';
            write(all(ans));
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
