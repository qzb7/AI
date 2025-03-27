#include<iostream>
#include<string>
#include<unordered_set>
#include<queue>

using namespace std;

unordered_set<string> used;
string target = "123456780";
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int main()
{
    string input[9];
    string s;
    for (int i = 0; i < 9; i++)
    {
        cin >> input[i];
        if (input[i] == "x") s += '0';
        else s += input[i];
    }
    queue<pair<string, int>> q;
    q.push({s, 0});
    while(!q.empty())
    {
        auto a = q.front();
        q.pop();
        used.insert(a.first);
        if (a.first == target)
        {
            cout << a.second << endl;
            return 0;
        }
        int index = a.first.find('0');
        int x = index / 3, y = index % 3;
        for (int i = 0; i < 4; i++)
        {
        string s1 = a.first;
        int x1 = x + dx[i], y1 = y + dy[i];
            if (x1 >= 0 && x1 < 3 && y1 >= 0 && y1 < 3)
            {
                swap(s1[index], s1[x1 * 3 + y1]);
                if (used.find(s1) == used.end()) 
                {
                    q.push({s1, a.second + 1});
                }
            }
        }
    }
    cout << "-1" << endl;
    return 0;
}