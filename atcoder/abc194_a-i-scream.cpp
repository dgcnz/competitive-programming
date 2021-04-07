#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int solve(int a, int b)
{
    a += b;

    if (a >= 15 and b >= 8)
        return 1;
    else if (a >= 10 and b >= 3)
        return 2;
    else if (a >= 3)
        return 3;
    else
        return 4;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int a, b;
    cin >> a >> b;

    cout << solve(a, b) << endl;
    return 0;
}
