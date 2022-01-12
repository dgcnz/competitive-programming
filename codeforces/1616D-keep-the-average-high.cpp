#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int solve(vector<int> a, int x)
{
    int n = a.size(), ans = 0;
    transform(all(a), begin(a), [&](int ai) { return ai - x; });
    for (int i = 0; i < n; ++i)
    {
        ans++;
        int j = i + 1;
        while (j < n)
        {
            if (a[j] + a[j - 1] < 0)
                break;
            if (j > i + 1 and a[j - 2] + a[j - 1] + a[j] < 0)
                break;
            ans++;
            j++;
        }
        i = j;
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
        int x;
        cin >> x;
        cout << solve(a, x) << endl;
    }
    return 0;
}
