#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/dp/subset_sum>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

bool solve(vi a)
{
    vi  b;
    int n = a.size(), i = 0;
    while (i < n)
    {
        int j = i + 1;
        while (j < n and a[j] < a[i])
            ++j;
        b.push_back(j - i);
        i = j;
    }
    int sum = accumulate(all(b), 0);
    return sum % 2 == 0 and SubsetSum(b, sum / 2).solve();
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
        vi a(2 * n);
        decrement(all(a));
        read(all(a));
        cout << (solve(a) ? "YES" : "NO") << endl;
    }
    return 0;
}
