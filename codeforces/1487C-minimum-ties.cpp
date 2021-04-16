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
        int n;
        cin >> n;
        int k = ((n * (n - 1)) / 2) / n;

        vector<vi> ans(n, vi(n, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j <= i + k; ++j)
            {
                ans[i][j % n] = 1;
                ans[j % n][i] = -1;
            }
        }
        for (int i = 0; i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j)
                cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}
