#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;


vector<int> al[200];


int taken[200] ;




bool bfs(int x) //not bicolorable,return true 0---1---2
{

  memset(taken,-1,sizeof(taken)/sizeof(int));
  queue<int> q;
  q.push(x);

  taken[x] = 0; // taken[x] =0 means x is pushed in queue


  while(!q.empty())
  {
      int yy = q.front();
      q.pop();
      taken[yy] = 1 ; //taken[x] = 1 means 1 is popped from queue

      for( auto it = al[yy].begin(); it != al[yy].end() ; it++)
      {
          if( taken[*it] == 1 ) continue;

          if( taken[*it] == 0 ) //if yy's any adjacent node xx is taken[xx]=0 ,means cycle
          {
              return true;
          }
          q.push(*it);
          taken[*it] = 0;
      }


  }
  return false;
}



int main()
{
    int n;

    while(cin>>n && n!=0)
    {
        int e;
        cin>>e;

        for(int j = 0; j < n; j++ )
        {
           al[j].clear();
        }

        int u,v;
        for(int i = 0; i < e; i++)
        {

            cin>>u>>v;
            al[u].push_back(v);
            al[v].push_back(u);
        }

        if( bfs(u) ) cout<<"NOT BICOLORABLE."<<"\n";
        else cout<<"BICOLORABLE."<<"\n";

    }

}
