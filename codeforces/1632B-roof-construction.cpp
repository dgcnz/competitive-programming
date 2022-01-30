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
        int n;
        cin >> n;
        int x = 1;
        while (x * 2 <= n - 1)
            x *= 2;

        vector<bool> vis(n, false);
        vector<int>  ans;
        for (int i = x; i <= n - 1; ++i)
        {
            ans.push_back(i);
            vis[i] = true;
        }

        ans.push_back((n - 1) ^ x);
        vis[(n - 1) ^ x] = true;

        for (int i = 0; i < n; ++i)
            if (not vis[i])
                ans.push_back(i);
        write(all(ans), " "), cout << endl;
    }
    return 0;
}
