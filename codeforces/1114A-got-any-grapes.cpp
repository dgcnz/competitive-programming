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

string solve(int x, int y, int z, int a, int b, int c)
{
    int k = min(x, a);
    x -= k;
    a -= k;

    if (x != 0)
        return "NO";
    k = min(y, a);
    y -= k;
    a -= k;

    k = min(y, b);
    y -= k;
    b -= k;

    if (y != 0)
        return "NO";
    if (a + b + c < z)
        return "NO";
    return "YES";
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int x, y, z;
    cin >> x >> y >> z;
    int a, b, c;
    cin >> a >> b >> c;

    cout << solve(x, y, z, a, b, c) << endl;

    return 0;
}
