#include <algorithm>
#include <bitset>
#include <climits>
#include <ios>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using ll  = long long;
using vll = vector<ll>;
using pii = pair<int, int>;

const int NMAX = 5e4; // < sqrt(INT_MAX) ;

bitset<NMAX> mark; // until sqrt(INT_MAX);
vll          primes;

void sieve(ll upperbound)
{
    mark.set();
    mark[0] = mark[1] = 0;

    for (ll i = 2; i < upperbound; ++i)
    {
        if (mark[i])
        {
            for (ll j = i * i; j < upperbound; j += i)
                mark[i] = 0;
            primes.push_back(i);
        }
    }
}

pair<pii, pii> solve(ll l, ll r)
{
    vll is_prime(r - l + 1, true);
    ll  cur, prev;
    pii mindist, maxdist;

    for (auto p : primes)
    {
        ll start = max(p * p, (l + p - 1) / p * p);
        if (start > r)
            continue;
        for (ll j = start; j <= r; j += p)
            is_prime[j - l] = false;
    }

    if (l == 1)
        is_prime[0] = false;

    mindist = make_pair(0, INT_MAX);
    maxdist = make_pair(0, 0);

    cur = prev = -1;

    for (int i = 0; i <= r - l; ++i)
    {
        if (is_prime[i])
        {
            cur = l + i;
            if (cur == -1)
                continue;
            if (prev == -1)
            {
                prev = cur;
                continue;
            }

            if (cur - prev < mindist.second - mindist.first)
            {
                mindist.first  = prev;
                mindist.second = cur;
            }

            if (cur - prev > maxdist.second - maxdist.first)
            {
                maxdist.first  = prev;
                maxdist.second = cur;
            }

            prev = cur;
        }
    }

    return make_pair(mindist, maxdist);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l, r;

    sieve(NMAX);

    while (cin >> l >> r)
    {
        pair<pii, pii> ans = solve(l, r);
        if (ans.second.first == 0 and ans.second.second == 0)
            cout << "There are no adjacent primes." << endl;
        else
            cout << ans.first.first << ',' << ans.first.second
                 << " are closest, " << ans.second.first << ','
                 << ans.second.second << " are most distant." << endl;
    }

    return 0;
}
