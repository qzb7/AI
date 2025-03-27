#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

unordered_set<string> used;
string target = "123456780";
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int dfs(string s,int depth)
{
    if (depth > 31) return 0;
    used.insert(s);
    if (s == target) return 1;
    int index = s.find('0');
    int x = index / 3, y = index % 3;
    for (int i = 0; i < 4; i++)
    {
        string s1 = s;
        int x1 = x + dx[i], y1 = y + dy[i];
        if (x1 >= 0 && x1 < 3 && y1 >= 0 && y1 < 3)
        {
            swap(s1[index], s1[x1 * 3 + y1]);
            if (used.find(s1) == used.end())
            {
                if (dfs(s1,depth++) == 1) return 1;
            }
        }
    }
    used.erase(s);
    return 0;
}
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
    if (dfs(s,0) == 1) cout << "1" << endl;
    else cout << "0" << endl;
}