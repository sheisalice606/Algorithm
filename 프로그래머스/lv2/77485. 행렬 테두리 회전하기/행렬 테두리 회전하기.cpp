#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
    int x;
    int y;
    int num;
};

int x1, y1;
int x2, y2;

vector<Node> Vector;
int Map[101][101];

void Rotation() {
    
    for(auto& E : Vector)
    {
        if(E.x == x1)
        {
            if(E.y == y2)
            {
                E.x++;
            }
            else 
            {
                E.y++;
            }
        }
        else if(E.x == x2)
        {
            if(E.y == y1)
            {
                E.x--;
            }
            else
            {
                E.y--;
            }
        }
        else
        {
            if(E.y == y1)
            {
                E.x--;
            }
            else if(E.y == y2)
            {
                E.x++;
            }
        }
    }
    
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    
    vector<int> Ans;
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            Map[i][j] = (i - 1) * columns + j;
        }
    }
    //전역 변수 초기화
    
    for(vector<int> v : queries)
    {
        x1 = v[0];
        y1 = v[1];
        x2 = v[2];
        y2 = v[3];
        
        //꼭지점 노드 삽입
        Vector.push_back({x1, y1, Map[x1][y1]});
        Vector.push_back({x1, y2, Map[x1][y2]});
        Vector.push_back({x2, y1, Map[x2][y1]});
        Vector.push_back({x2, y2, Map[x2][y2]});
        
        for(int i = x1 + 1; i < x2; i++)
        {
            Vector.push_back({i, y1, Map[i][y1]});
            Vector.push_back({i, y2, Map[i][y2]});
        }
        
        for(int i = y1 + 1; i < y2; i++)
        {
            Vector.push_back({x1, i, Map[x1][i]});
            Vector.push_back({x2, i, Map[x2][i]});
        }
        
        Rotation();
        int Min = 100000000;
        for(auto E : Vector)
        {
            Map[E.x][E.y] = E.num;
            
            // Ans.push_back(E.x);
            // Ans.push_back(E.y);
            
            Min = min(Min, E.num); 
        }
    
        Ans.push_back(Min);
        Vector.clear();
        
    }
    
    return Ans;
    
}