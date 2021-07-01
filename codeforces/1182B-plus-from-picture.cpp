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

string solve(vector<string> a)
{
    int n = a.size(), m = a[0].size();

    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cnt += a[i][j] == '*';

    for (int i = 1; i < n - 1; ++i)
    {
        for (int j = 1; j < m - 1; ++j)
        {
            if (a[i][j] == '*' and a[i + 1][j] == '*' and a[i - 1][j] == '*' and
                a[i][j + 1] == '*' and a[i][j - 1] == '*')
            {
                cnt -= 1;
                int l = j - 1;
                while (l >= 0 and a[i][l] == '*')
                    --l, --cnt;
                int r = j + 1;
                while (r < m and a[i][r] == '*')
                    ++r, --cnt;

                int u = i - 1;
                while (u >= 0 and a[u][j] == '*')
                    --u, --cnt;
                int d = i + 1;
                while (d < n and a[d][j] == '*')
                    ++d, --cnt;
                if (cnt)
                    return "NO";
                else
                    return "YES";
            }
        }
    }
    return "NO";
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    read(all(a));
    cout << solve(a) << endl;
    return 0;
}
