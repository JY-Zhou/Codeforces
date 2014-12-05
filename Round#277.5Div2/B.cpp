#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 105;
int useif[maxn];   //记录y中节点是否使用 0表示没有访问过，1为访问过
int link[maxn];   //记录当前与y节点相连的x的节点
int mat[maxn][maxn]; //记录连接x和y的边，如果i和j之间有边则为1，否则为0
int x[maxn], y[maxn];
int gn,gm;    //二分图中x和y中点的数目

int can(int t)
{
    int i;
    for(i=1;i<=gm;i++)
    {
       if(useif[i]==0 && mat[t][i])
       {
           useif[i]=1;
           if(link[i]==-1 || can(link[i]))
           {
              link[i]=t;
              return 1;
           }
       }
    }
    return 0;
}

int MaxMatch()
{
    int i,num;
    num=0;
    memset(link,0xff,sizeof(link));
    for(i=1;i<=gn;i++)
    {
      memset(useif,0,sizeof(useif));
       if(can(i)) num++;
    }
    return num;
}

int main() {
    cin >> gn;
    for(int i = 1 ; i <= gn ; i++) {
	cin >> x[i];
    }
    cin >> gm;
    for(int i = 1 ; i <= gm ; i++) {
	cin >> y[i];
    }
    for(int i = 1 ; i <= gn ; i++) {
	for(int j = 1 ; j <= gm ; j++) {
	    mat[i][j] = (abs(x[i] - y[j]) <= 1);
	}
    }
    cout << MaxMatch() << endl;
    return 0;
}
