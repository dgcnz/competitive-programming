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

int solve(vector<int> a)
{
    int n = a.size(), first_1 = 0, last_1 = n - 1;
    while (first_1 < n and a[first_1] == 0)
        ++first_1;
    while (last_1 >= 0 and a[last_1] == 0)
        --last_1;
    if (first_1 == n or first_1 == last_1)
        return 0;

    int zeros = 0;
    for (int i = first_1; i < last_1; ++i)
        zeros += a[i] == 0;
    return zeros;
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
        vector<int> a(n);
        read(all(a));
        cout << solve(a) << endl;
    }
    return 0;
}
