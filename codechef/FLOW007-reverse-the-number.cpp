#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1000000 + 11;

string s;
bool   leading_zero[NMAX];

int main(void)
{
    int n;

    cin >> n;
    while (n--)
    {
        cin >> s;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (i == s.size() - 1)
                while (s[i] == '0')
                    --i;
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}
