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

string solve(int x, int y)
{
    if (y == 0 or (x + y) % 2 == 0 or (y == 1 and x > 0))
        return "No";

    return x >= y - 1 ? "Yes" : "No";
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int x, y;
    cin >> x >> y;
    cout << solve(x, y) << endl;
    return 0;
}
