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

        string s(2 * n, ' ');
        s[0] = '(', s[2 * n - 1] = ')';

        int cnt = n;

        function<void(int, int, int, int)> solve =
            [&](int i, int l, int r, int acc)
        {
            if (i == 2 * n - 1 and acc)
            {
                cnt--;
                cout << s << endl;
                return;
            }
            if (l < n and cnt)
            {
                s[i] = '(';
                solve(i + 1, l + 1, r, acc + 1);
            }
            if (acc > 0 and r < n and cnt)
            {
                s[i] = ')';
                solve(i + 1, l, r + 1, acc - 1);
            }
        };

        solve(1, 1, 1, 1);
    }
    return 0;
}
