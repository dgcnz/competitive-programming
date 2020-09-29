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

const double PI = acos(-1);

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

inline double rad(double deg) { return (deg * M_PI) / 180.0; }

int solve(string s, vector<double> alpha, int r)
{
    s.erase(remove_if(all(s), [](char c) { return not isalpha(c); }), s.end());
    transform(all(s), s.begin(), [](char c) { return toupper(c); });
    s.erase(unique(all(s)), s.end());

    if (s.empty())
        return 0;
    double ans  = r;
    char   last = 0;

    for (auto c : s)
    {
        if (last)
        {
            double deg = abs(alpha[last - 'A'] - alpha[c - 'A']);
            deg        = min(deg, 360.0 - deg);
            ans += 2 * r * sin(rad(deg) / 2.0);
        }
        last = c;
    }
    return ceil(ans);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int r;
    cin >> r;

    vector<double> alpha(26);
    for (int i = 0; i < 26; ++i)
    {
        char   c;
        double d;
        cin >> c >> d;
        alpha[toupper(c) - 'A'] = d;
    }

    string s;
    cin.ignore(), getline(cin, s);
    cout << solve(s, alpha, r) << endl;

    return 0;
}
