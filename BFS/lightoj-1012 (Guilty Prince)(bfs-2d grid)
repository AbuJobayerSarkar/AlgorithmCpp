#include<iostream>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0,  0, 1,-1};
char cell[20][20];
int vis[20][20];
int cn ;
void bfs(int ppx, int ppy,int ccx, int ccy)
{
    vis[ppy][ppx] = 1;
    cn++;
    for(int i = 0; i < 4 ; i++)
    {
        int nx = ppx + dx[i];
        int ny = ppy + dy[i];
       if(nx>=0 && nx<ccx && ny>=0 && ny<ccy && vis[ny][nx] == 0)
       {
         if( cell[ny][nx] == '.') bfs(nx,ny,ccx,ccy); 
                 }
    }
}
int main()
{
    int n;
    cin >> n;
    int coun = 1;
    while(n--)
    {
        int cx,cy;
        int px,py;
        cin>>cx >>cy;
        for(int i = 0; i < cy; i++)
        {
            for(int j = 0; j < cx; j++)
            {
                cin>>cell[i][j];
                vis[i][j] = 0;

                 if( cell[i][j] == '@' )
                 {
                     px = j;
                     py = i;
                 }
            }
        }
        cn = 0;
        bfs(px,py,cx,cy);
        cout << "Case " << coun++ <<": " << cn <<"\n";
    }
}

