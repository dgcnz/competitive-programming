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
        if (n <= 30)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            int a = n - 30;
            if (a == 6 or a == 14 or a == 10)
            {
                int a = n - 31;
                cout << a << " " << 6 << " " << 15 << " " << 10 << endl;
            }
            else
            {
                cout << a << " " << 6 << " " << 14 << " " << 10 << endl;
            }
        }
    }
    return 0;
}
