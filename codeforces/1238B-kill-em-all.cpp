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

int solve(int r, vi x)
{
    sort(all(x));
    x.erase(unique(all(x)), x.end());
    int shots = 0, i = (int)x.size() - 1;
    while (i >= 0 and (x[i] - shots * r > 0))
        shots++, i--;

    return shots;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;
        vi x(n);
        read(all(x));
        cout << solve(r, x) << endl;
    }
    return 0;
}
