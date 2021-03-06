#include <iostream>

using namespace std;

int main(void)
{
    int t;

    cin >> t;

    while (t--)
    {
        int    a, b, p;
        string s;

        cin >> a >> b >> p;
        cin >> s;
        int  length      = s.size();
        char pchar       = s[length - 1];
        int  size_travel = 1;
        int  ctrav;
        int  i;
        int  ans = length - 1;

        for (i = length - 2; i >= 0; i--)
        {
            while (i >= 0 and s[i] == pchar)
            {
                ++size_travel;
                --i;
            }
            ctrav = s[i + 1] == 'A' ? a : b;

            if (i < 0)
                break;

            if (i + 1 == length - 1)
                ctrav = 0;

            pchar = s[i];

            if (p - ctrav < 0)
                break;

            p -= ctrav;
            ans = i + 1;
        }
        if (i == -1)
        {
            ctrav = s[i + 1] == 'A' ? a : b;
            if (p - ctrav >= 0)
                ans = i + 1;
        }
        cout << ans + 1 << endl;
    }
    return 0;
}
