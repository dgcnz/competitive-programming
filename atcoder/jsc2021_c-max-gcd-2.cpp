#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/math/utils>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int solve(int a, int b)
{
    for (int g = b; g >= 2; --g)
        if (range_remainder_count(a, b, g, 0) >= 2)
            return g;
    return 1;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;
    return 0;
}
