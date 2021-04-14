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

vector<ll> solve(vector<ll> b)
{
    int n   = b.size();
    ll  sum = accumulate(all(b), 0LL);
    sort(all(b));
    for (int i = 0; i < n; ++i)
    {
        ll x = b[i], maxix = i == n - 1 ? i - 1 : n - 1;
        if (sum - x == 2 * b[maxix])
        {
            vector<ll> ans;
            for (int j = 0; j < n; ++j)
                if (j != i and j != maxix)
                    ans.push_back(b[j]);
            return ans;
        }
    }
    return {};
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
        vector<ll> b(n + 2);
        read(all(b));
        if (auto ans = solve(b); !ans.empty())
            write(all(ans), " "), cout << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
