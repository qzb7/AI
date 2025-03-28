#include<iostream>
#include<string>
#include<unordered_map>
#include<queue>

using namespace std;

unordered_map<string, int> used;
unordered_map<string, string> act;
string target = "123456780";
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
char actions[4] = {'d','u','r','l'};

int can_solve(string s)
{
    int cnt = 0;
    for (int i = 1; i < 9; i++)
    {
        if (s[i] != '0')
        {
            for (int j = 0; j < i; j++)
            {
                if (s[i] < s[j]) cnt++;
            }
        }
    }
    return cnt % 2 == 0;
}

int mhd(string s)
{
    int d = 0;
    for (int i = 0; i < 9; i++)
    {
        if (s[i] != '0')
        {
            int dx = abs((s[i] - '1') / 3 - i / 3);
            int dy = abs((s[i] - '1') % 3 - i % 3);
            d += dx + dy;
        }
    }
    return d;
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
    if (!can_solve(s))
    {
        cout << "unsolvable" << endl;
        return 0;
    }
    priority_queue<tuple<int, string, string>, vector<tuple<int, string, string>>, greater<>> q;
    q.push({mhd(s), s, ""});
    used[s] = 0;
    act[s] = "";
    while(!q.empty())
    {
        auto a = q.top();
        string s1 = get<1>(a);
        string acts = get<2>(a);
        q.pop();
        if (s1 == target)
        {
            cout << acts << endl;
            return 0;
        }
        int index = s1.find('0');
        int x = index / 3, y = index % 3;
        for (int i = 0; i < 4; i++)
        {
            string s2 = s1;
            int x1 = x + dx[i], y1 = y + dy[i];
            if (x1 >= 0 && x1 < 3 && y1 >= 0 && y1 < 3)
            {
                swap(s2[index], s2[x1 * 3 + y1]);
                char c = actions[i];
                int costnow = used[s1] + 1;
                if (used.find(s2) == used.end() || used[s2] > costnow) 
                {
                    used[s2] = costnow;
                    act[s2] = acts + c;
                    q.push({costnow + mhd(s2), s2, act[s2]});
                }
            }
        }
    }
    return 0;
}
