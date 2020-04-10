#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    int    t;
    string s;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc)
    {
        stack<int> d;
        cin >> s;
        s.push_back('0');
        d.push('0');

        cout << "Case #" << tc << ": ";

        for (int i = 0, n = s.size(); i < n; ++i)
        {
            if (s[i] > d.top())
            {
                for (int j = 0, len = s[i] - d.top(); j < len; ++j)
                    cout << "(";
                d.push(s[i]);
            }
            if (s[i] < d.top())
            {
                for (int j = 0, len = d.top() - s[i]; j < len; ++j)
                    cout << ")";
                while (s[i] < d.top())
                    d.pop();
                d.push(s[i]);
            }

            if (i != n - 1)
                cout << s[i];
        }

        cout << endl;
    }
}
