#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

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

int solve(vector<vi> t, int k)
{
    int n = t.size();

    vi order(n);
    for (int i = 0; i < n; ++i)
        order[i] = i;

    int ans = 0;
    do
    {
        int cur = 0;
        for (int i = 0; i < n; ++i)
            cur += t[order[i]][order[(i + 1) % n]];
        ans += cur == k;
    } while (next_permutation(order.begin() + 1, order.end()));

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    cin >> n >> k;

    vector<vi> t(n, vi(n));
    for (auto &ti : t)
        read_n(ti.begin(), n);

    cout << solve(t, k) << endl;
    return 0;
}
