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
        ll n;
        cin >> n;
        auto sum = [](ll n) {
            ll ans = 0;
            while (n)
            {
                ans += n % 10;
                n /= 10;
            }
            return ans;
        };
        while (gcd(n, sum(n)) == 1)
            n++;

        cout << n << endl;
    }
    return 0;
}
