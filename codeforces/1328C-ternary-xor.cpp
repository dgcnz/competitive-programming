#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main(void)
{
    int    t, n, x, y;
    bool   bigger;
    string s, a, b;
    cin >> t;

    while (t--)
    {
        cin >> n >> s;
        bigger = false;
        for (int i = 0; i < n; ++i)
        {
            if (not bigger)
            {
                y = (s[i] - '0') / 2;
                x = (s[i] - '0') - y;
                a.push_back(x + '0');
                b.push_back(y + '0');

                if (x > y)
                    bigger = true;
            }
            else
            {
                a.push_back('0');
                b.push_back(s[i]);
            }
        }
        cout << a << endl << b << endl;
        a.clear();
        b.clear();
    }
    return 0;
}
