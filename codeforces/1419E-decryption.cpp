#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/math/factorize>
#include <cplib/math/misc>
#include <cplib/math/primes>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#include <ranges>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
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
        int n;
        cin >> n;

        auto div = factorize(n);
        div.erase(remove(all(div), 1), div.end());
        sort(all(div));

        if (div.size() == 3 and is_prime(div[0]) and is_prime(div[1]))
            write(all(div), " "), cout << endl << 1 << endl;
        else
        {
            auto           prime_factors = prime_factorize(n);
            vector<int>    connect(prime_factors.size());
            map<int, bool> used;
            for (int i = 0; i < (int)prime_factors.size(); ++i)
            {
                int p = prime_factors[i].first,
                    q = prime_factors[(i + 1) % prime_factors.size()].first;
                for (int j = 0; j < (int)div.size(); ++j)
                {
                    if (!used[div[j]] && div[j] % p == 0 && div[j] % q == 0)
                    {
                        used[div[j]] = true;
                        connect[i]   = div[j];
                        break;
                    }
                }
            }

            for (int i = 0; i < (int)prime_factors.size(); ++i)
            {
                int p   = prime_factors[i].first;
                used[p] = true;
                cout << p << ' ';
                for (int j = 0; j < (int)div.size(); ++j)
                {
                    if (!used[div[j]] && div[j] % p == 0)
                    {
                        used[div[j]] = true;
                        cout << div[j] << ' ';
                    }
                }
                if (prime_factors.size() > 1)
                    cout << connect[i] << ' ';
            }
            cout << '\n' << 0 << '\n';
        }
    }
    return 0;
}
