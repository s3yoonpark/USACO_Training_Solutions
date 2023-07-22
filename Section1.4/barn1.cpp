/*
ID: s3yoonpark
LANG: C++
PROB: barn1
*/ 

#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
ofstream fout ("barn1.out");
ifstream fin ("barn1.in");
int M, C, S;
vector<int> occupatedStalls;
vector<int> emptySpaces;
int stalls[201];
bool greaterF(int a, int b)
{
    return a > b;
}
int main()
{
    memset(stalls, 0, 201*sizeof(int));
    fin >> M >> S >> C;
    for(int i = 0; i < C; ++i)
    {
        int stallNumber;
        fin >> stallNumber;
        stalls[stallNumber] = 1;
        occupatedStalls.push_back(stallNumber);
    }
    sort(occupatedStalls.begin(), occupatedStalls.end());
    int length = 0;
    int i = occupatedStalls[0];
    while(i <= occupatedStalls[C-1])
    {
        //cout<<" i: "<<i<<" is "<<stalls[i]<<endl;
        if(stalls[i] == 0) ++length;
        else if(length != 0)
        {
            emptySpaces.push_back(length);
            length = 0;
        }
        ++i;
    }
    for(int i = 0; i < emptySpaces.size(); ++i)
    {
        //cout<<"length "<<emptySpaces[i]<<endl;
    }
    sort(emptySpaces.begin(), emptySpaces.end(), greaterF);
    int addedBarns = 0;
    for(int i = 0; i < emptySpaces.size(); ++i)
    {
        if(i+1 <= M - 1) continue;
        addedBarns += emptySpaces[i];
    }
    fout << C + addedBarns << endl;
    return 0;
}
