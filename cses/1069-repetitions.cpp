#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int    ans, cur;
    char   last;
    string s;
    cin >> s;

    ans = cur = 0;
    last      = s[0];
    for (auto c : s)
    {
        if (c == last)
            ++cur;
        else
        {
            ans = max(ans, cur);
            cur = 1;
        }
        last = c;
    }
    ans = max(ans, cur);
    cout << ans << endl;

    return 0;
}
