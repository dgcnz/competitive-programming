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
    int n;
    cin >> n;
    vi a(n);
    read(all(a));

    sort(all(a));
    if (a[n - 1] >= a[n - 2] + a[n - 3])
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        vi ans;
        for (int i = 0; i < n - 1; i += 2)
            ans.push_back(a[i]);
        ans.push_back(a[n - 1]);
        vi temp;
        for (int i = 1; i < n - 1; i += 2)
            temp.push_back(a[i]);
        reverse(all(temp));
        for (auto x : temp)
            ans.push_back(x);
        write(all(ans), " "), cout << endl;
    }
    return 0;
}
