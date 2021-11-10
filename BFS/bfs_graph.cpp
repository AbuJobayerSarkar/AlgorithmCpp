//BFS
#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
using namespace std;

vector< vector <int> > alg; //adjacency list of graph
vector<bool> taken;


void bfs(int i)
{
    queue<int> Q;
    Q.push(i); //putting root node in queue

    taken[i] = true;

    while(!Q.empty())
    {
        int k = Q.front();
        cout << k <<" ";
        Q.pop();

        //checking adjacency nodes of root node
        for( auto it = alg[k].begin(); it!= alg[k].end() ; it++ )
        {
            //if the adjacency node not taken,push in Q
            if( !taken[*it] )
            {
                Q.push(*it);
                taken[*it] = true;
            }
        }
    }

}







//Driver
int main()
{
   //reading data from file and creating adjacency list

   ifstream data ("data");
   int n,m;
   data >> n >> m; //n=node number,m=edge number

   alg.assign(n,vector<int>());
   taken.assign(n,false);
   for( int i = 0; i < m; i++)
   {
       int u,v;
       data >> u >> v;
       alg[u].push_back(v);
       alg[v].push_back(u);
   }

   //applying bfs from and for node 0
    for(int j = 0; j < n; j++)
    {
        if(!taken[j])
            bfs(j);
    }
   return 0;
}

input data
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
