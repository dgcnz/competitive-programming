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
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    read(all(a));
    if (n > 3)
        cout << -1 << endl;
    else if (n == 1)
        cout << 0 << endl;
    else
    {
        vector<int> x(m, 0), y(m, 0);
        vector<vi>  cnt(2, vi(2, 0));
        for (int i = 0; i < m; i++)
        {
            x[i] = (a[0][i] - '0' + a[1][i] - '0' + i) % 2;
            if (n == 3)
                y[i] = (a[0][i] - '0' + a[2][i] - '0') % 2;
            cnt[x[i]][y[i]]++;
        }
        cout << m - max(max(cnt[0][0], cnt[1][0]), max(cnt[0][1], cnt[1][1]))
             << endl;
    }
    return 0;
}
