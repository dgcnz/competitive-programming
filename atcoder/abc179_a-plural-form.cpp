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

int main(void)
{
    string s;
    cin >> s;

    if (s.back() == 's')
        cout << s << "es" << endl;
    else
        cout << s << "s" << endl;
    return 0;
}
