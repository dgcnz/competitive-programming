#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
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
        string s, t;
        cin >> s >> t;
        if (t != "abc")
        {
            sort(all(s));
            cout << s << endl;
        }
        else
        {
            vector<int> cnt(26, 0);
            for (auto si : s)
                cnt[si - 'a']++;
            if (cnt[0] and cnt[1] and cnt[2])
            {
                string ans;
                ans.resize(ans.size() + cnt[0], 'a');
                ans.resize(ans.size() + cnt[2], 'c');
                ans.resize(ans.size() + cnt[1], 'b');
                for (int ch = 3; ch < 26; ++ch)
                    ans.resize(ans.size() + cnt[ch], char(ch + 'a'));
                cout << ans << endl;
            }
            else
            {
                sort(all(s));
                cout << s << endl;
            }
        }
    }
    return 0;
}
