//BFS for 2D grid(chess)

#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#define pii pair<int,int>
using namespace std;

int fx[] = { 1, -1, 0, 0};
int fy[] = { 0,  0, 1, -1};


queue<pii> Q;

int taken[10][10] = {0};
int d[10][10] = {10000};

int row,col;


void bfs(int x,int y)
{
    Q.push(pii(x,y));
    taken[x][y] = 1;
    d[x][y] = 0;
    while(!Q.empty())
    {
       pii tp = Q.front();
       Q.pop();

        for( int i = 0; i < 4; i++)
        {
            int uu = tp.first;
            int vv = tp.second;

            int tx = uu + fx[i];
            int ty = vv + fy[i];

            if( tx>0 && tx<=row && ty>0 && ty<=col && taken[tx][ty]!=1 )
            {
                taken[tx][ty] = 1;
                d[tx][ty] = d[uu][vv]+1;

                cout<< tx << "," << ty << "  is  " << d[tx][ty] <<"\n";
                Q.push(pii(tx,ty));
            }
        }

    }
}

//Driver
int main()
{
   row = 8;
   col = 8;


   cout << "distances from node 1,1 of node " <<"\n";

      bfs(1,1);

}

