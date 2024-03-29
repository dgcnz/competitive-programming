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
    int q;
    cin >> q;
    while (q--)
    {
        int    n;
        string s;
        cin >> n >> s;
        if (n == 2 and s[0] >= s[1])
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl << 2 << endl;
            cout << s[0] << " ";
            for (int i = 1; i < n; ++i)
                cout << s[i];
            cout << endl;
        }
    }
    return 0;
}
