#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int taken[200] = { 0 };

vector<int> al[200];

void dfs(int x)
{
    cout<< x <<" ";
    taken[x] = 1;
    for(auto it = al[x].begin(); it !=al[x].end(); it++ )
    {
        if( taken[ *it ] != 1) dfs( *it );
    }

}

//Driver

int main()
{
    ifstream file ("data");
    int n,e;
    int u,v;
    file >> n >> e;
    for( int lisa = 0; lisa < e ; lisa++)
    {
        file >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
    }
    dfs(u);

}
data:
7 9

3 4 
3 2
3 5 
3 0
0 6
0 1
1 5
1 4 
6 2

