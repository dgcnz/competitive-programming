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

vi solve(vi a)
{
    vi ans;
    sort(all(a));
    int n = a.size(), l = 0, r = n - 1;
    while (l < r)
    {
        ans.push_back(a[r]);
        ans.push_back(a[l]);
        l++, r--;
    }
    if (l == r)
        ans.push_back(a[r]);
    reverse(all(ans));
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
        auto ans = solve(a);
        write(all(ans), " "), cout << endl;
    }
    return 0;
}
