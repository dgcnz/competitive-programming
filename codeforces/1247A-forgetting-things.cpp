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
    int da, db;
    cin >> da >> db;

    if (da == db)
    {
        cout << da << 0 << " " << db << 1 << endl;
    }
    else if (da + 1 == db)
    {
        cout << da << 9 << " " << db << 0 << endl;
    }
    else if (da == 9 and db == 1)
    {
        cout << da << " " << db << 0 << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}
