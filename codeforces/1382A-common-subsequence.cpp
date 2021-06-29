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
        int n, m;
        cin >> n >> m;
        vi a(n), b(m);
        read(all(a));
        read(all(b));
        sort(all(a));
        sort(all(b));
        int i = 0, j = 0;
        int x = -1;
        while (i < n and j < m)
        {
            if (a[i] == b[j])
            {
                x = a[i];
                break;
            }
            else if (a[i] < b[j])
                ++i;
            else
                ++j;
        }
        if (x == -1)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            cout << 1 << " " << x << endl;
        }
    }
    return 0;
}
