#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

bool is_palindrome(vector<int> a) { return vector<int>(rall(a)) == a; }

bool attempt(vector<int> &a, int x)
{
    vector<int> b;
    for (auto ai : a)
        if (ai != x)
            b.push_back(ai);

    return is_palindrome(b);
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
        vi a(n);
        read(all(a));
        int l = 0, r = n - 1;
        while (l < r and a[l] == a[r])
            l++, r--;

        // dbg(l, r);
        if (is_palindrome(a) or attempt(a, a[l]) or attempt(a, a[r]))
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}
