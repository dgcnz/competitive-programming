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

vector<vi> try_sorted(vector<int> a)
{
    int        n = a.size();
    vector<vi> m(n, vi(n, 0));
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > i + 1)
            return {};
        else
            for (int j = i; j > i - a[i]; --j)
                m[i][j] = 1;
    }
    return m;
}

template <typename T>
long long count_inversions(vector<T> const &a)
{
    int       n   = a.size();
    long long ans = 0;
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < i; ++j)
            ans += a[i] < a[j];
    return ans;
}

long long permutation_sign(vector<int> const &sigma)
{
    return count_inversions(sigma) & 1LL ? -1 : +1;
}

vector<vi> rotate(vector<vi> const &a)
{
    int        n = a.size();
    vector<vi> b(n, vi(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            b[n - i - 1][n - j - 1] = a[i][j];
    return b;
}

template <typename InputIt,
          typename T    = typename iterator_traits<InputIt>::value_type,
          class Compare = std::less<T>>
vector<int> argsort(InputIt first, InputIt last, Compare cmp = std::less<T>())
{
    vector<int> indices(distance(first, last));
    std::iota(indices.begin(), indices.end(), 0);
    std::sort(indices.begin(),
              indices.end(),
              [&](int i, int j) { return cmp(*(first + i), *(first + j)); });
    return indices;
}

template <typename InputIt,
          typename T    = typename iterator_traits<InputIt>::value_type,
          class Compare = std::less<T>>
vector<int>
stable_argsort(InputIt first, InputIt last, Compare cmp = std::less<T>())
{
    vector<int> indices(distance(first, last));
    std::iota(indices.begin(), indices.end(), 0);
    std::sort(indices.begin(),
              indices.end(),
              [&](int i, int j)
              {
                  T a = *(first + i), b = *(first + j);
                  if (!cmp(a, b) and !cmp(b, a)) // equal
                      return i < j;
                  return cmp(a, b);
              });
    return indices;
}

template <typename InputIt,
          typename T = typename iterator_traits<InputIt>::value_type>
vector<T> apply_permutation(InputIt first, InputIt last, vector<int> sigma)
{
    int n = distance(first, last);
    assert(n == (int)sigma.size());
    vector<T> a_sigma(n);
    for (int i = 0; i < n; ++i)
        a_sigma[i] = *(first + sigma[i]);
    return a_sigma;
}

vector<int> inverse_permutation(vector<int> sigma)
{
    int         n = sigma.size();
    vector<int> inv(n);
    for (int i = 0; i < n; ++i)
        inv[sigma[i]] = i;
    return inv;
}

void swap_columns(vector<vi> &a, int x, int y)
{
    for (int i = 0; i < (int)a.size(); ++i)
        swap(a[i][x], a[i][y]);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vector<int> a(n);

    read(all(a));
    auto sigma    = argsort(all(a));
    auto sorted_a = apply_permutation(all(a), sigma);
    int  k        = sorted_a.front() - 1;
    decrement(all(sorted_a), k);
    int  sigma_sign = permutation_sign(sigma);
    bool uniq =
        is_sorted(all(sorted_a), [](auto l, auto r) { return r - l > 0; });
    bool distinct_sorted_sign = (n / 2) % 2 == 1;

    if (not uniq or sigma_sign == +1 or distinct_sorted_sign)
    {
        auto m = try_sorted(sorted_a);
        if (not m.empty())
        {
            vector<vi> ans(n, vi(n));
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    ans[sigma[i]][j] = m[i][j];

            if (sigma_sign == -1)
                swap_columns(ans, 0, 1);
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                    cout << ans[i][j] << " ";
                cout << endl;
            }
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}
