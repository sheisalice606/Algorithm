#include <string>
#include <set>
#include <vector>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
// U D R L 순서

int px;
int py;

struct Position {
    int x1;
    int y1;
    int x2;
    int y2;
    
    bool operator < (const Position& A) const
    {
        if (x1 != A.x1) {
            return x1 < A.x1;
        }
        if (y1 != A.y1) {
            return y1 < A.y1;
        }
        if (x2 != A.x2) {
            return x2 < A.x2;
        }
        return y2 < A.y2;
    }
    
};

set<Position> Set;


void Move(char C)
{
    int nx;
    int ny;
    
    switch(C) 
    {
        case 'U' : 
            nx = px + dx[0];
            ny = py + dy[0];
            break;
            
        case 'D' :
            nx = px + dx[1];
            ny = py + dy[1];
            break;
        
        case 'R' :
            nx = px + dx[2];
            ny = py + dy[2];
            break;
            
        case 'L' :
            nx = px + dx[3];
            ny = py + dy[3];
            break;          
    }
    
    if(nx < -5 || ny < -5 || nx > 5 || ny > 5) return;
    //좌표 밖을 벗어난 경우 중단.
    

    Set.insert({px, py, nx, ny});
    Set.insert({nx, ny, px, py});
    //해당 길의 좌표를 왕복 체크
    
    px = nx;
    py = ny;
    //현재 좌표 갱신
    
}

int solution(string dirs) {
    px = 0;
    py = 0;
    
    for(int i = 0; i < dirs.length(); i++)
    {
        Move(dirs[i]);
    }
    return Set.size() / 2;
}