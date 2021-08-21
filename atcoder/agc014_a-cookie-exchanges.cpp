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

int solve(int a, int b, int c)
{
    if (a & 1 or b & 1 or c & 1)
        return 0;
    if (a == b and b == c)
        return -1;

    int ans = 0;
    while (not(a & 1 or b & 1 or c & 1))
    {
        int ta = a, tb = b, tc = c;
        a = (tb + tc) / 2, b = (ta + tc) / 2, c = (ta + tb) / 2;
        ans++;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int a, b, c;
    cin >> a >> b >> c;

    cout << solve(a, b, c) << endl;

    return 0;
}
