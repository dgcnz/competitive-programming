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

int ask(int t, int i, int j, int x)
{
    int ans;
    cout << "? " << t << ' ' << i << ' ' << j << ' ' << x << endl;
    cin >> ans;
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int idx = -1;
        for (int i = 1; i + 1 <= n; i += 2)
        {
            int x = ask(2, i, i + 1, 1);
            if (x == 1)
            {
                idx = i;
                break;
            }
            else if (x == 2)
            {
                x = ask(2, i + 1, i, 1);
                if (x == 1)
                {
                    idx = i + 1;
                    break;
                }
            }
        }
        if (idx == -1)
            idx = n;
        vi p(n + 1);
        p[idx] = 1;
        for (int i = 1; i <= n; ++i)
            if (i != idx)
                p[i] = ask(1, idx, i, n - 1);
        cout << "! ";
        for (int i = 1; i <= n; ++i)
            cout << p[i] << ' ';
        cout << endl;
    }
    return 0;
}
