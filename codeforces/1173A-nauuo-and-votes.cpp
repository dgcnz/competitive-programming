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

char solve(int x, int y, int z)
{
    if (x - y > 0 and x > y + z)
        return '+';
    if (y - x > 0 and y > x + z)
        return '-';
    if (x - y == 0 and z == 0)
        return '0';
    return '?';
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int x, y, z;
    cin >> x >> y >> z;

    cout << solve(x, y, z) << endl;
    return 0;
}
