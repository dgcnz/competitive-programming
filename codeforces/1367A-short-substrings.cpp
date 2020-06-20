#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string b;
    int    t;
    cin >> t;
    while (t--)
    {
        cin >> b;
        for (int i = 0; i < (int)b.size(); ++i)
        {
            if (i % 2 == 0)
                cout << b[i];
        }
        cout << b.back() << endl;
    }

    return 0;
}
