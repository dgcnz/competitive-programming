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
        vi a(n);
        read(all(a));
        sort(all(a));
        if (a.front() < 0)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            cout << a.back() + 1 << endl;
            for (int x = 0; x <= a.back(); ++x)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
