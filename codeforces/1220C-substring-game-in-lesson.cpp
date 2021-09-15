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
    vector<bool> lost(26, false);
    int          n = s.size();
    for (int i = 0; i < n; ++i)
    {
        bool flag = [&]()
        {
            for (int ch = 0; ch < int(s[i] - 'a'); ++ch)
                if (lost[ch])
                    return true;
            return false;
        }();

        if (flag)
            cout << "Ann" << endl;
        else
        {
            cout << "Mike" << endl;
            lost[s[i] - 'a'] = true;
        }
    }
    return 0;
}
