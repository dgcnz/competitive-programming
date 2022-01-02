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
        ll n;
        cin >> n;

        multiset<int> nbac;

        ll x = 1, sum = 0;
        while (sum + x <= n)
        {
            nbac.insert(x);
            sum += x;
            x *= 2;
        }
        if (sum < n)
            nbac.insert(n - sum);

        vector<int> ans(all(nbac));
        cout << (int)ans.size() - 1 << endl;
        for (int i = 1; i < (int)ans.size(); ++i)
            cout << ans[i] - ans[i - 1] << ' ';
        cout << endl;
    }
    return 0;
}
