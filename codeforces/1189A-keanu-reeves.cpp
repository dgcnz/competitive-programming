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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int    n;
    string s;
    cin >> n >> s;

    int zeros = count(all(s), '0'), ones = n - zeros;

    if (ones == zeros)
    {
        cout << 2 << endl;
        char c = s.back();
        s.pop_back();
        cout << s << " " << c << endl;
    }
    else
    {
        cout << 1 << endl;
        cout << s << endl;
    }
    return 0;
}
