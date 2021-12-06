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
        int n;
        cin >> n;
        vector<int> a(n);
        read(all(a));

        vector<bool> l1(n, false), l2(n, false);
        set<int>     num;
        for (int i = 0; i < n; ++i)
        {
            num.insert(a[i]);
            if ((int)num.size() == i + 1 and *num.rbegin() == i + 1)
                l1[i] = true;
        }

        num.clear();
        for (int i = n - 1; i >= 0; --i)
        {
            num.insert(a[i]);
            if ((int)num.size() == n - i and *num.rbegin() == n - i)
                l2[i] = true;
        }

        vector<ii> ans;
        for (int i = 1; i < n; ++i)
            if (l1[i - 1] and l2[i])
                ans.emplace_back(i, n - i);
        cout << ans.size() << endl;
        for (auto [l, r] : ans)
            cout << l << " " << r << endl;
    }
    return 0;
}
