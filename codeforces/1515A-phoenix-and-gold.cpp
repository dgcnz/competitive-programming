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
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vi w(n), pw(n);
        read(all(w));
        sort(all(w));
        partial_sum(all(w), begin(pw));

        auto it = find(all(pw), x);
        if (pw.back() == x)
            cout << "NO" << endl;
        else if (it == pw.end())
        {
            cout << "YES" << endl;
            write(all(w), " "), cout << endl;
        }
        else
        {
            int i = distance(begin(pw), it);
            swap(w[i], w.back());
            cout << "YES" << endl;
            write(all(w), " "), cout << endl;
        }
    }
    return 0;
}
