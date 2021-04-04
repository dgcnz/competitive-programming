#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace atcoder;
using namespace cplib;
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using mint = modint998244353;

ll solve(vector<ll> a)
{
    int const  DIGITS = 12;
    vector<ll> cnt(2 * DIGITS, 0);
    vector<ll> ndig(DIGITS, 0);

    for (auto ai : a)
    {
        int c = 0;
        while (ai)
        {
            ai /= 10;
            c++;
        }
        ndig[c]++;
    }

    for (auto ai : a)
    {
        for (int j = 0; j < DIGITS; j++)
        {
            if (ai == 0)
                break;
            for (int k = 1; k < DIGITS; ++k)
            {
                if (k >= j + 1)
                {
                    cnt[2 * j] += ndig[k] * (ai % 10);
                    cnt[2 * j + 1] += ndig[k] * (ai % 10);
                }
                else
                {
                    cnt[k + j] += 2 * ndig[k] * (ai % 10);
                }
            }

            ai /= 10;
        }
    }

    mint ans = 0;
    for (int i = 2 * DIGITS - 1; i >= 0; --i)
    {
        ans *= 10;
        ans += cnt[i];
    }
    return ans.val();
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
