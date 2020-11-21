---
layout: post
title: 1722 Fibonacci Numbers
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
using ii = pair<int, int>;
using vi = vector<int>;
template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void read_n(InputIterator it, int n)
{
    copy_n(istream_iterator<T>(cin), n, it);
}
template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void write(InputIterator first, InputIterator last, const char *delim = "\n")
{
    copy(first, last, ostream_iterator<T>(cout, delim));
}
int const MOD = 1e9 + 7;
using mat = vector<vector<ll>>;
template <typename T, size_t N>
void multiply(T A[N][N], T B[N][N])
{
    T C[N][N] = {};
    for (int i = 0; i < int(N); i++)
    {
        for (int j = 0; j < int(N); j++)
        {
            for (int k = 0; k < int(N); k++)
            {
                C[i][j] += (A[i][k] * B[k][j]) % MOD;
                if (C[i][j] >= MOD)
                    C[i][j] -= MOD;
            }
        }
    }
    for (int i = 0; i < int(N); i++)
    {
        for (int j = 0; j < int(N); j++)
        {
            A[i][j] = C[i][j];
        }
    }
}
template <typename T, size_t N>
void power(T A[N][N], T base[N][N], long long k)
{
    if (k == 0)
        return;
    else
    {
        power(A, base, k >> 1);
        multiply<T, N>(A, A);
        if (k & 1)
        {
            multiply<T, N>(A, base);
        }
    }
}
template <typename T, size_t N>
void solve(T transition[N][N], T cur[N], ll k, T next[N])
{
    T r[N][N] = {};
    for (size_t i = 0; i < N; i++)
        r[i][i] = 1;
    power<T, N>(r, transition, k);
    for (size_t i = 0; i < N; i++)
    {
        next[i] = 0;
        for (size_t j = 0; j < N; j++)
        {
            next[i] += (r[i][j] * cur[j]) % MOD;
            if (next[i] >= MOD)
                next[i] -= MOD;
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    long long A[2][2] = {{1, 1}, {1, 0}};
    long long cur[2] = {0, 1}, next[2];
    long long k;
    cin >> k;
    solve(A, cur, k, next);
    cout << next[0] << endl;
    return 0;
}

{% endraw %}
```
