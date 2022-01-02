#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int solve(vector<int> a)
{
    map<int, int> cnt;
    for (auto ai : a)
        cnt[-abs(ai)]++;

    int ans = 0;
    for (auto [k, v] : cnt)
    {
        ans += 1;
        if (v >= 2 and k < 0)
            ans += 1;
    }
    return ans;
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
