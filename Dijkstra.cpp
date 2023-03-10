#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
using namespace std;
const int N =100 ;
const int INF=100000;
int p[N][N] , d[N],path[N];
//节点 ， 距离 ， 路径
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
                    if(!mark[j]&& d[j]<min)   //初始节点到子节点的距离最小值
                    {
                        min=d[j];
                        min_num = j;
                    }
                }
            mark[min_num] = 1;

            for(j=1;j<=n;j++)
                {
                    if(d[j]>min+p[min_num][j])
                        {
                            path[j]=min_num;
                            d[j] = min +p[min_num][j];
                        }
                }
        }
}

void print(int bgn,int n)
{
   int i, j;
    stack<int> q;               //由于记录的中途节点是倒序的，所以使用栈（先进后出），获得正序
    for (i = 2; i <=n; i++)            //打印从出发节点到各节点的最短距离和经过的路径
    {
        j = i;
        while (path[j] != -1)      //如果j有中途节点
        {
            q.push(j);          //将j压入堆
            j = path[j];     //将j的前个中途节点赋给j        
        }
        q.push(j);
        cout << bgn << "=>" << i <<" length:"<< d[i]<<" path  " << bgn;
        while (!q.empty())       //先进后出,获得正序
        {
            cout << q.top();
            //printf("%d ", q.top());//打印堆的头节点
            q.pop();            //将堆的头节点弹出
        }
        printf("\n");
    }
}
int main()
{
    memset(path, -1, sizeof(path));//将path数组初始化为-1
    int i, j, n = 6;  //n为顶点个数，方便测试将数据写死
    //任意两点间距离初始化为INF，自身为0
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <=n; j++)
        {
            p[i][j] = (i == j ? 0 : INF);
        }
    }
    //为方便测试将数据写死，下面注释内为如何输入数据
    p[1][2] = 1; p[1][3] = 12; p[2][3] = 9; p[2][4] = 3; p[4][5] = 13; p[3][5] = 5; p[4][6] = 15; p[5][6] = 4;p[4][3]=4;//p[i][j]表示节点i到节点j的距离 

    dijkstra(1, n);               //求从节点0出发到各节点的最短距离
    print(1, n);                  //打印从节点0出发到各节点的最短距离和路径
    return 0;
}