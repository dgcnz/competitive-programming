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

ll ceil(ll a, ll b) { return (a + b - 1) / b; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (ceil(n - 2, 2) < k)
            cout << -1 << endl;
        else
        {
            vector<int> ans(n);
            int         x = n, y = 1;
            for (int i = 0; i < n; ++i)
            {
                if (i & 1 and k)
                    ans[i] = x--, k--;
                else
                    ans[i] = y++;
            }
            write(all(ans), " "), cout << endl;
        }
    }
    return 0;
}
