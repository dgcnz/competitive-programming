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

int const NMAX = 1e6 + 11;

string solve(vi a)
{
    int         amax = *max_element(all(a));
    vector<int> num(amax + 1, 0);
    int         g = 0;
    for (auto ai : a)
    {
        g = gcd(g, ai);
        num[ai]++;
    }
    for (int i = 2; i <= amax; ++i)
    {
        int cnt = 0;
        for (int j = i; j <= amax; j += i)
            cnt += num[j];
        if (cnt > 1)
        {
            if (g == 1)
                return "setwise coprime";
            else
                return "not coprime";
        }
    }
    return "pairwise coprime";
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    read(all(a));
    cout << solve(a) << endl;
    return 0;
}
