#include<bits/stdc++.h>
using namespace std;
const int Max=150;
int fat[Max],vis[Max];
int edg[Max][Max];
int n,m,ans,fir,las,pic;
char str[50][50];
int f[4][2]={0,1,0,-1,1,0,-1,0};
void check(int i,int j,int cur,char a){
	int fi,fj,u;
	for(u=0;u<4;u++){
		fi=i+f[u][0];
		fj=j+f[u][1];
		if(fi>=0&&fi<n&&fj>=0&&fj<m){
			if(str[fi][fj]==a){
				pic=fi*m+fj+1;
				edg[cur][pic]=1;
			}
		}
	}
	return;
 }
void ford_fulderson(void){
	queue<int>q;
	int cur,i;
	while(1){
		memset(vis,0,sizeof(vis));
		memset(fat,0,sizeof(fat));
		while(!q.empty()){
			q.pop();
		}
		q.push(0);
		vis[0]=1;
		while(!q.empty()){//every time find a way to las
			cur=q.front();q.pop();
			if(cur==las)
				break;
			for(i=0;i<las+1;i++){
				if(edg[cur][i]&&vis[i]==0){
					fat[i]=cur;
					q.push(i);
					vis[i]=1;
				}
			}
 //			printf("cur=%d\n",cur);
		}
		int u,min=1;
		if(!vis[las])
			return;
        for(u=las;u;u=fat[u]){
            if(edg[fat[u]][u]<min)
                min = edg[fat[u]][u];  
        }
		for(u=las;u>0;u=fat[u]){
 //			printf("u=%d\n",u);
			edg[fat[u]][u]-=min;
			edg[u][fat[u]]+=min;
		}
		if(min==0)
			break;
 //		printf("ans=%d\n",ans);
		ans+=min;
	}
 }
void input_and_init(void){
	int i,j,cur,pic;
	scanf("%d%d",&n,&m);
	fir=0;las=n*m+1;
	for(i=0;i<n;i++)
		scanf("%s",str[i]);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cur=i*m+j+1;
			if(str[i][j]=='H'){
				edg[0][cur]=1;
				check(i,j,cur,'B');
			}
			else if(str[i][j]=='B'){
				check(i,j,cur,'T');
			}
			else{
				edg[cur][las]=1;
			}
		}
	}
 }
int main(void){
	int T;
	scanf("%d",&T);
	while(T-->0){
		ans=0;
		memset(edg,0,sizeof(edg));
		input_and_init();
		ford_fulderson();
		printf("%d\n",ans);
	}
	return 0;
 }