#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

bool is_palindrome(string s)
{
    int l = 0, r = (int)s.size() - 1;
    while (l < r)
    {
        if (s[l] != s[r])
            return false;
        l++, r--;
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        if (is_palindrome(s + 'a'))
        {
            if (is_palindrome('a' + s))
                cout << "NO" << endl;
            else
                cout << "YES" << endl << 'a' + s << endl;
        }
        else
            cout << "YES" << endl << s + 'a' << endl;
    }
    return 0;
}
