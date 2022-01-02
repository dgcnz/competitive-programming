#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
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
    vector<vi> b(n, vi(m));
    for (auto &bi : b)
        read(all(bi)), decrement(all(bi));

    bool flag = true;
    int  jr   = b[0][0] % 7;
    int  prv  = b[0][0] - 7;
    for (int i = 0; i < n; ++i)
    {
        flag &= b[i][0] == (prv + 7);
        for (int j = 1; j < m; ++j)
            flag &= (b[i][j] - b[i][j - 1]) == 1;
        flag &= (jr + m) <= 7;
        prv = b[i][0];
    }

    cout << (flag ? "Yes" : "No") << endl;

    return 0;
}
