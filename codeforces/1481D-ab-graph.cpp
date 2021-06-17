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
        vector<string> a(n);
        read(all(a));

        if (m & 1)
        {
            cout << "YES" << endl;
            for (int i = 0; i <= m; ++i)
                cout << i % 2 + 1 << " ";
            cout << endl;
        }
        else
        {
            if (n == 2)
            {
                cout << (a[0][1] == a[1][0] ? "YES" : "NO") << endl;
                if (a[0][1] == a[1][0])
                {
                    for (int i = 0; i <= m; ++i)
                        cout << i % 2 + 1 << " ";
                    cout << endl;
                }
            }
            else
            {
                cout << "YES" << endl;
                int f = a[0][1] == a[1][2] ? 2 : a[1][2] == a[2][0] ? 3 : 1;
                for (int i = 0; i <= m; ++i)
                    cout << (f + i + m - 1) % 3 + 1 << " ";
                cout << endl;
            }
        }
    }
    return 0;
}
