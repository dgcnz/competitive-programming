#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

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

int solve(int n, string s)
{
    map<char, vi> pm = {
        {'A', vi(n, 0)}, {'T', vi(n, 0)}, {'C', vi(n, 0)}, {'G', vi(n, 0)}};

    string opts = "AGCT";

    for (int i = 0; i < n; ++i)
    {
        for (auto c : opts)
        {
            pm[c][i] += s[i] == c;
            if (i != 0)
                pm[c][i] += pm[c][i - 1];
        }
    }

    auto sum = [&pm](int l, int r, char c) {
        return pm[c][r] - (l > 0 ? pm[c][l - 1] : 0);
    };

    int ans = 0;
    for (int l = 0; l < n - 1; ++l)
    {
        for (int r = l + 1; r < n; ++r)
        {
            ans += (sum(l, r, 'A') == sum(l, r, 'T') and
                    sum(l, r, 'C') == sum(l, r, 'G'));
        }
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int    n;
    string s;
    cin >> n >> s;

    cout << solve(n, s) << endl;
    return 0;
}
