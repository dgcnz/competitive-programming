#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;
using vi = vector<ll>;

template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void write(InputIterator first, InputIterator last, const char *delim = "\n")
{
    copy(first, last, ostream_iterator<T>(cout, delim));
}

template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void read_n(InputIterator it, int n)
{
    copy_n(istream_iterator<T>(cin), n, it);
}

ii      med = {-1, -1};
set<ii> bot, top;
ll      sbot, stop;

void fix()
{
    int m = 1 + isz(bot) + isz(top);
    if (isz(bot) < (m - 1) / 2)
    {
        bot.insert(med), sbot += med.first;
        med = *top.begin();
        top.erase(med), stop -= med.first;
    }
    if (isz(bot) > (m - 1) / 2)
    {
        top.insert(med), stop += med.first;
        med = *prev(bot.end());
        bot.erase(med), sbot -= med.first;
    }
}

void add(ii x)
{
    if (med.first == -1)
    {
        med = x;
        return;
    }
    if (x < med)
        bot.insert(x), sbot += x.first;
    else
        top.insert(x), stop += x.first;
    fix();
}

void rem(ii x)
{
    if (x == med)
    {
        med = *top.begin();
        top.erase(med), stop -= med.first;
    }
    else if (x < med)
        bot.erase(x), sbot -= x.first;
    else
        top.erase(x), stop -= x.first;
    fix();
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    cin >> n >> k;

    vi a(n);
    read_n(a.begin(), n);

    if (k == 1)
    {
        for (int i = 0; i < n; ++i)
            cout << 0 << " ";
        cout << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i)
    {
        add({a[i], i});
        if (i >= k - 1)
        {
            auto left  = (isz(bot) * med.first - sbot);
            auto right = (stop - isz(top) * med.first);
            //// dbg(bot, sbot, top, stop);
            // cout << med.first << endl;
            cout << left + right << " ";
            rem({a[i - k + 1], i - k + 1});
        }
    }

    return 0;
}
