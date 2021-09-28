#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define rall(c) rbegin(c), rend(c)
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
    int x;
    cin >> x;
    while(x % 10 == 0)
        x /= 10;

    string s = to_string(x);

    if (s == string(rall(s)))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}

