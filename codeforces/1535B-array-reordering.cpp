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

ll solve(vi a)
{
    int        n = a.size();
    deque<int> b;
    for (auto ai : a)
    {
        if (ai % 2)
            b.push_back(ai);
        else
            b.push_front(ai);
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (b[i] % 2 == 0)
            ans += n - i - 1;
        else
            for (int j = i + 1; j < n; ++j)
                ans += gcd(b[i], b[j]) > 1;
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
        vi a(n);
        read(all(a));
        cout << solve(a) << endl;
    }
    return 0;
}
