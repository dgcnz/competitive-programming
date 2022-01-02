#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/graph/graph>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

char query(int a, int b, int c, int d)
{
    cout << "? " << a << " " << b << " " << c << " " << d << endl;
    cout.flush();
    char ch;
    cin >> ch;
    return ch;
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
        Graph<void> g(n);

        auto        multi_query = [&](vector<int> x)
        {
            vector<char> res(3);
            res[0] = query(x[0], x[1], x[2], x[3]);
            res[1] = query(x[0], x[2], x[1], x[3]);
            res[2] = query(x[0], x[3], x[1], x[2]);

            vector<ii> lr(4, {0, 3});

        };
    }

    return 0;
}
