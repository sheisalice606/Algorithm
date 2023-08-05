#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int T;
int main(int argc, char** argv)
{
	cin >> T;
    int Cnt = 0;
    while(T--) 
    {
        string str;
        int len;
        cin >> str;
        len = str.length();
        
        if(len % 2 == 0) cout << "#" << ++Cnt << " " << stoi(str.substr(0, len/2)) + stoi(str.substr(len/2)) << '\n';
        else 
        {
            int first = stoi(str.substr(0, len/2)) + stoi(str.substr(len/2));
            int second = stoi(str.substr(0, len/2 + 1)) + stoi(str.substr(len/2 + 1));
            cout << "#" << ++Cnt << " " << min(first, second) << '\n';
        }
    }
	return 0;
}