#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string n;
        cin >> n;
        queue<int> parity[2];
        for (auto c : n)
        {
            int x = c - '0';
            parity[x % 2].push(x);
        }

        string ans(n.size(), '0');
        for (auto &c : ans)
        {
            int even = parity[0].size() ? parity[0].front() : 10,
                odd  = parity[1].size() ? parity[1].front() : 10;
            c        = parity[even > odd].front() + '0';
            parity[even > odd].pop();
        }
        cout << ans << endl;
    }
    return 0;
}
