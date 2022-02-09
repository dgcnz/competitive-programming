#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/math/misc>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
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
        int n, k;
        cin >> n >> k;

        int mx0 = 2 * (n / 2) * k;
        int mx1 = 2 * integer::ceil(n, 2) * k - 1;

        if (abs(mx1 - mx0) == 1)
        {
            cout << "YES" << endl;
            int x = 2, y = 1;
            for (int i = 0; i < n; ++i)
            {
                if (i % 2 == 1)
                    for (int j = 0; j < k; ++j, x += 2)
                        cout << x << " ";
                else
                    for (int j = 0; j < k; ++j, y += 2)
                        cout << y << " ";
                cout << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
