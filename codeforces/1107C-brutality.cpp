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

ll solve(vector<ll> a, int k, string s)
{
    int n = a.size(), l = 0;

    for (int r = 0; r < n; ++r)
    {
        if (s[l] != s[r])
        {
            sort(a.begin() + l, a.begin() + r, greater<ll>());
            l = r;
        }
    }

    sort(a.begin() + l, a.end(), greater<ll>());

    ll  ans = a[0];
    int cnt = 1;
    for (int i = 1; i < n; ++i)
    {
        if (s[i] == s[i - 1] and cnt >= k)
            continue;

        ans += a[i];
        if (s[i] == s[i - 1])
            cnt++;
        else
            cnt = 1;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    read(all(a));
    string s;
    cin >> s;

    cout << solve(a, k, s) << endl;

    return 0;
}
