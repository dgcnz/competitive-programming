---
layout: post
mathjax: true
title: 918B - Radio Station
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---



{% if page.time_complexity != "None" %}
Time complexity: ${{ page.time_complexity }}$
{% endif %}

{% if page.memory_complexity != "None" %}
Memory complexity: ${{ page.memory_complexity }}$
{% endif %}

<details>
<summary>
<p style="display:inline">Click to show code.</p>
</summary>
```cpp
{% raw %}
using namespace std;
string line;
int pos;
map<int, string> ip_to_name;
bool is_char(char c) { return 'a' <= c and c <= 'z'; }
bool is_digit(char c) { return '0' <= c and c <= '9'; }
string parse_name(void)
{
    string name;
    while (is_char(line[pos]))
    {
        name += line[pos];
        ++pos;
    }
    ++pos;
    return name;
}
int parse_ip(void)
{
    int i = 0, ip[4], ans = 0;
    string cnum;
    while (is_digit(line[pos]) or line[pos] == '.')
    {
        if (line[pos] == '.')
        {
            ip[i] = stoi(cnum);
            ++i;
            cnum = string();
        }
        else
            cnum += line[pos];
        ++pos;
    }
    ip[i] = stoi(cnum);
    for (int i = 0; i < 4; ++i)
        ans += ip[i] * pow(256, 4 - (i + 1));
    return ans;
}
int main(void)
{
    string name;
    int n, m, ip;
    cin >> n >> m;
    cin.ignore();
    for (int i = 0; i < n; ++i)
    {
        pos = 0;
        getline(cin, line);
        name = parse_name();
        ip = parse_ip();
        ip_to_name[ip] = name;
    }
    for (int i = 0; i < m; ++i)
    {
        pos = 0;
        getline(cin, line);
        name = parse_name();
        ip = parse_ip();
        cout << line << " #" << ip_to_name[ip] << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

