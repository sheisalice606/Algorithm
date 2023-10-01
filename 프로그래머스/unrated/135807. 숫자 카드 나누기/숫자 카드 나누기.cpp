#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> A;
vector<int> B;

vector<int> listA;
vector<int> listB;

int solution(vector<int> arrayA, vector<int> arrayB) {
    A = arrayA;
    B = arrayB;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    //정렬 오름차순
    
    for(int i = 2; i <= A[0]; i++)
    {
        bool Flag = true;
        for(int j = 0; j < B.size(); j++)
        {
            if(A[j] % i != 0)
            {
                Flag = false;
                break;
            }
        }
        if(Flag == true) listA.push_back(i);
    }
    
    for(int i = 2; i <= B[0]; i++)
    {
        bool Flag = true;
        for(int j = 0; j < A.size(); j++)
        {
            if(B[j] % i != 0)
            {
                Flag = false;
                break;
            }
        }
        if(Flag == true) listB.push_back(i);
    }
    //listA, listB 초기화
    //cout << listA.size() << " , " << listB.size() << endl;
    
    
    int Ans = 0;
    
    for(int i = 0; i < listA.size(); i++)
    {
        bool Flag = true;
        for(int j = 0; j < B.size(); j++)
        {
            if(B[j] % listA[i] == 0)
            {
                Flag = false;
                break;
            }
        }
        if(Flag == true) Ans = max(Ans, listA[i]);
    }
    
    for(int i = 0; i < listB.size(); i++)
    {
        bool Flag = true;
        for(int j = 0; j < A.size(); j++)
        {
            if(A[j] % listB[i] == 0) 
            {
                Flag = false;
                break;
            }
        }
        if(Flag == true) Ans = max(Ans, listB[i]);
    }
    
    return Ans;
    
    
}

//1. 서로를 모두 나눌 수 있는 정수 set 구하기
