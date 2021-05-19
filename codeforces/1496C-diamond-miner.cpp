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

double norm(ll x, ll y) { return sqrt(x * x + y * y); }

double solve(vector<int> miners, vector<int> diamonds)
{
    int    n   = miners.size();
    double ans = 0;
    sort(all(miners)), sort(all(diamonds));
    for (int i = 0; i < n; ++i)
        ans += norm(diamonds[i], miners[i]);
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
        vector<int> miners, diamonds;
        for (int i = 0; i < 2 * n; ++i)
        {
            int x, y;
            cin >> x >> y;
            if (x == 0)
                miners.push_back(abs(y));
            else
                diamonds.push_back(abs(x));
        }
        cout << fixed << setprecision(12) << solve(miners, diamonds) << endl;
    }
    return 0;
}
