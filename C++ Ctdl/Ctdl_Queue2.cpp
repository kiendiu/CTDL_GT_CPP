#include <bits/stdc++.h>
using namespace std;
int solve(int s, int t)
{
    queue<pair<int, int>> q;
    set<int> se; // tranh cac trang thai da duyet
    se.insert(s);
    q.push({s, 0});
    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
        if (top.first == t)
            return top.second;
        if (top.first * 2 || top.first - 1 == t)
            return (top.second + 1);
        if (se.find(top.first * 2) == se.end() && top.first < t)
        {
            q.push({top.first * 2, top.second + 1});
            se.insert(top.first * 2);
        }
        if (se.find(top.first - 1) == se.end() && top.first < t)
        {
            q.push({top.first - 1, top.second + 1});
            se.insert(top.first - 1);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (--t)
    {
        int s, t;
        cin >> s >> t;
        cout << solve(s, t) << endl;
    }
    return 0;
}