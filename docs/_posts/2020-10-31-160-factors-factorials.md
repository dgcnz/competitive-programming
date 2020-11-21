---
layout: post
title: 160 Factors Factorials
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using ll = long long;
using vi = vector<int>;
using mii = map<int, int>;
const int NMAX = 1e7 + 11;
bitset<NMAX> is_prime;
vector<int> prime;
mii prime_factors(ll n)
{
    mii factors;
    for (int j = 2; j <= n; ++j)
    {
        int ni = j;
        ll i = 0, pf = prime[i];
        while (pf * pf <= ni)
        {
            while (ni % pf == 0)
            {
                ++factors[pf];
                ni = ni / pf;
            }
            pf = prime[++i];
        }
        if (ni != 1)
            ++factors[ni];
    }
    return factors;
}
void sieve(ll maxn)
{
    ll sieve_size = maxn + 1;
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for (ll i = 2; i <= sieve_size; i++)
        if (is_prime[i])
        {
            for (ll j = i * i; j <= sieve_size; j += i)
                is_prime[j] = 0;
            prime.push_back((int)i);
        }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve(NMAX);
    int n;
    while (cin >> n and n)
    {
        cout << right << setw(3) << n;
        cout << "! =";
        int i = 0;
        for (auto elem : prime_factors(n))
        {
            if (i > 0 && i % 15 == 0)
                cout << endl << "      ";
            cout << right << setw(3) << elem.second;
            ++i;
        }
        cout << endl;
    }
    return 0;
}

{% endraw %}
```
