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

bool test(vi a)
{
    int n   = a.size();
    int sum = accumulate(all(a), 0);
    return 2 * sum >= n * 9;
}

int solve(vi a)
{
    int n = a.size();
    sort(all(a));
    if (test(a))
        return 0;
    for (int i = 0; i < n; ++i)
    {
        a[i] = 5;
        if (test(a))
            return i + 1;
    }
    return n;
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
