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
        int n, k;
        cin >> n >> k;

        vi valid(n + 1, true);
        valid[k] = false;
        for (int i = 1; i <= (k - 1) / 2; ++i)
            valid[i] = false;

        vi ans;
        for (int i = 1; i <= n; ++i)
            if (valid[i])
                ans.push_back(i);
        cout << size(ans) << endl;
        write(all(ans), " "), cout << endl;
    }
    return 0;
}
