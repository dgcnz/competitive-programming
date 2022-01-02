#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

vector<int> solve(vector<int> p, string s)
{
    vector<int> sigma = argsort(all(p));
    stable_sort(all(sigma), [&s](int i, int j) { return s[i] < s[j]; });
    return argsort(all(sigma));
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n);
        read(all(p));
        decrement(all(p));
        string s;
        cin >> s;

        auto ans = solve(p, s);
        increment(all(ans));
        write(all(ans), " "), cout << endl;
    }
    return 0;
}
