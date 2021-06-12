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
    int n, x, y;
    cin >> n >> x >> y;
    vi a(n);
    read(all(a));
    for (int i = 0; i < n; ++i)
    {
        bool flag = true;
        for (int j = max(0, j - x - 1); j < i; j++)
            if (a[j] <= a[i])
                flag = false;
        for (int j = i + 1; j < min(n, i + y + 1); ++j)
            if (a[j] <= a[i])
                flag = false;

        if (flag)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }
    return 0;
}
