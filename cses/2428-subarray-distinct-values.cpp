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

ll solve(vector<int> x, int k)
{
    map<int, int> cnt;
    int           l = 0, r = 0, uniq = 0, ans = 0, n = x.size();
    while (l < n)
    {
        while (r < n and uniq + (cnt[x[r]] == 0) <= k)
        {
            cnt[x[r]]++;
            uniq += cnt[x[r]] == 1;
            ++r;
        }
        ans += r - l;
        uniq -= cnt[x[l]] == 1;
        cnt[x[l]]--;
        ++l;
    }

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    cin >> n >> k;

    vector<int> x(n);
    read(all(x));

    cout << solve(x, k) << endl;

    return 0;
}
