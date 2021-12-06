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
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vi a(n);
        read(all(a));

        vector<bool> vis(300, false);

        for (auto ai : a)
            vis[ai] = true;

        int v = 1;
        while (v < (int)vis.size())
        {
            if (!vis[v] and x)
                x--, vis[v] = true;
            if (!vis[v] and x == 0)
                break;
            v++;
        }
        cout << v - 1 << endl;
    }
    return 0;
}
