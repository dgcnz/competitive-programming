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
        int    n;
        string s;
        cin >> n >> s;

        bool flag = false;
        for (int i = 1; i < n; ++i)
        {
            if (s[i] != s[i - 1])
            {
                cout << i << " " << i + 1 << endl;
                flag = true;
                break;
            }
        }
        if (not flag)
            cout << -1 << " " << -1 << endl;
    }
    return 0;
}
