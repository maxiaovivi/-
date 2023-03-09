#include<iostream>
#include<stack>
#include<vector>
using namespace std;
const int N =100 ;
const int INF=100000;
int p[N][N] , d[N],path[N];

void dijkstra(int bgn,int n)  //出发节点与图中节点总数
{
    //更新初始距离
    int i,j,min,min_num;
    int mark[N] ={0} ; //记录是否遍历过
    for(i=1;i<=n;i++)
        {
            d[i]=p[bgn][i];
        }
        mark[bgn] = 1;
        d[bgn] = 0;
        
   for(i=1;i<n;i++)
        {
            min=INF;
            for(j=1;j<=n;j++)
                {
                    if(!mark[j]&& d[j]<min)
                    {
                        min=d[j];
                        min_num = j;
                    }
                }
        }
}