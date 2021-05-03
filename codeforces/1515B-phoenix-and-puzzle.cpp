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

bool is_perfect_square(int n)
{
    int sq = sqrt(n);
    return sq * sq == n;
}
bool solve(int n)
{
    if (n % 2 == 0 and is_perfect_square(n / 2))
        return true;
    if (n % 4 == 0 and is_perfect_square(n / 4))
        return true;
    return false;
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
        cout << (solve(n) ? "YES" : "NO") << endl;
    }
    return 0;
}
