// Preprocessing O(n)
// Query O(1)

int inv[NMAX], fact[NMAX], inv_fact[NMAX];

int mult(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
int add(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }

void build()
{
    inv[1] = fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < NMAX; ++i)
    {
        if (i > 1)
            inv[i] = mult(MOD - inv[MOD % i], MOD / i);
        fact[i]     = mult(fact[i - 1], i);
        inv_fact[i] = mult(inv_fact[i - 1], inv[i]);
    }
}

int C(int n, int k)
{
    if (n < k)
        return 0;
    return mul(fact[n], mul(inv_fact[k], inv_fact[n - k]));
}

// Preprocessing O(n)
// Query O(logn)

ll binpow(ll a, ll b)
{
    a %= MOD;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll inv(ll a) { return binpow(a, MOD - 2); }

ll C(ll n, ll k)
{
    if (k > n)
        return 1;
    return mult(fact[n], inv(mult(fact[n - k], fact[k])));
}
