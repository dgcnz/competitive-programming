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
    string s;
    cin >> s;
    int n = s.size();
    cout << 4 << endl;
    cout << "R " << n - 1 << endl;
    n++;
    cout << "R " << n - 1 << endl;
    n++;
    cout << "L " << n - 1 << endl;
    n += (n - 2);
    cout << "L " << 2 << endl;

    return 0;
}
