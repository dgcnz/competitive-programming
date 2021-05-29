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

int solve(vector<ll> a)
{
    int n = a.size(), ans = 0;
    ll  h = 0;

    priority_queue<ll, vector<ll>, greater<ll>> q;

    for (int i = 0; i < n; ++i)
    {
        if (h + a[i] >= 0)
        {
            h += a[i];
            q.push(a[i]);
            ans++;
        }
        else if (q.size() and q.top() < a[i])
        {
            h += a[i] - q.top();
            q.pop();
            q.push(a[i]);
        }
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    read(all(a));
    cout << solve(a) << endl;
    return 0;
}
