#include <bitset>
#include <climits>
#include <ios>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using vi = vector<int>;

const int NMAX = 1e7 + 11;

vector<int>  prime;
bitset<NMAX> is_prime;

void sieve(ll n)
{
    ll sieve_size = n + 1;
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;

    for (ll i = 2; i <= sieve_size; ++i)
    {
        if (is_prime[i])
        {
            prime.push_back(i);
            for (ll j = i * i; j <= sieve_size; j += i)
                is_prime[j] = 0;
        }
    }
}
bool solve(ll n, ll m)
{
    if (m == 0)
        return true;

    ll i = 0, pf = prime[i], pf2, count1, count2;

    while (pf * pf <= m)
    {
        count1 = count2 = 0;
        while (m % pf == 0)
        {
            ++count1;
            m /= pf;
        }

        pf2 = pf;
        while (pf2 <= n)
        {
            count2 += n / pf2;
            pf2 *= pf;
        }

        if (count2 < count1)
            return false;
        pf = prime[i++];
    }

    if (m != 1) // if m is prime
    {
        if (n < m)
            return false;
    }
    return true;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve(NMAX);

    ll n, m;
    while (cin >> n >> m)
    {
        cout << m << " ";
        if (solve(n, m))
            cout << "divides ";
        else
            cout << "does not divide ";

        cout << n << "!\n";
    }

    return 0;
}
