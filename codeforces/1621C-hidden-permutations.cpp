#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
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

int query(int i)
{
    cout << "? " << i + 1 << endl;
    cout.flush();
    int ans;
    cin >> ans;
    return ans - 1;
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

        vector<int> ans(n, -1);

        auto solve_cycle = [&](int x)
        {
            int prv = query(x), fst = prv, cur;
            while ((cur = query(x)) != fst)
            {
                ans[prv] = cur;
                prv      = cur;
            }
            ans[prv] = cur;
        };
        for (int x = 0; x < n; ++x)
            if (ans[x] == -1)
                solve_cycle(x);

        cout << "! ";
        increment(all(ans));
        write(all(ans), " "), cout << endl;
    }
    return 0;
}
