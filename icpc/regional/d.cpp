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

char solve(vi a)
{
    int n = a.size();
    if (n == 1)
        return 'N';

    int const   AMAX = 1e5 + 11;
    vector<int> cnt(AMAX, 0);

    for (auto ai : a)
        cnt[ai]++;

    int rem = 0;
    for (int x = 0; x < AMAX - 1; ++x)
    {
        cnt[x + 1] += cnt[x] / 2;
        cnt[x] %= 2;
        rem += cnt[x];
    }
    return (rem > 2 ? 'N' : 'Y');
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    read(all(a));
    cout << solve(a) << endl;

    return 0;
}
