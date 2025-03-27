#include<iostream>
#include<string>
#include<unordered_map>
#include<queue>

using namespace std;

unordered_map<string, int> used;
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
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> q;
    q.push({0, s});
    used[s] = 0;
    while(!q.empty())
    {
        auto a = q.top();
        q.pop();
        
        if (a.first > used[a.second])
        {
            continue;
        }
        if (a.second == target)
        {
            cout << a.first << endl;
            return 0;
        }
        int index = a.second.find('0');
        int x = index / 3, y = index % 3;
        for (int i = 0; i < 4; i++)
        {
            string s1 = a.second;
            int x1 = x + dx[i], y1 = y + dy[i];
            if (x1 >= 0 && x1 < 3 && y1 >= 0 && y1 < 3)
            {
                swap(s1[index], s1[x1 * 3 + y1]);
                if (used.find(s1) == used.end() || used[s1] > a.first + 1) 
                {
                    used[s1] = a.first + 1;
                    q.push({a.first + 1, s1});
                }
            }
        }
    }
    cout << "-1" << endl;
    return 0;
}