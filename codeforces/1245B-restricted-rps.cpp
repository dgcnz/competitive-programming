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
        int    n, a, b, c;
        string s;
        cin >> n >> a >> b >> c >> s;

        string ans(n, 0);
        int    wins = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'R' and b)
                ans[i] = 'P', b--, wins++;
            else if (s[i] == 'P' and c)
                ans[i] = 'S', c--, wins++;
            else if (s[i] == 'S' and a)
                ans[i] = 'R', a--, wins++;
        }

        for (int i = 0; i < n; ++i)
        {
            if (!ans[i])
            {
                if (a)
                    ans[i] = 'R', a--;
                else if (b)
                    ans[i] = 'P', b--;
                else
                    ans[i] = 'S', c--;
            }
        }
        if (wins * 2 >= n)
        {
            cout << "YES" << endl;
            cout << ans << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}
