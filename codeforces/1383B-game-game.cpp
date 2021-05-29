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

string solve(vi a)
{
    int n = a.size();
    for (int i = 31; i >= 0; --i)
    {
        int ones = 0;
        for (auto ai : a)
            ones += (ai >> i) & 1;
        if (ones % 2)
            return ones % 4 == 3 and (n - ones) % 2 == 0 ? "LOSE" : "WIN";
    }
    return "DRAW";
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
        vi a(n);
        read(all(a));
        cout << solve(a) << endl;
    }
    return 0;
}
