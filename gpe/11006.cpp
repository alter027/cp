#include<bits/stdc++.h>
char a[20][20];
int che[20][20],n,m;
int xi[4]={0,1,0,-1},yi[4]={1,0,-1,0};
int find(int x,int y,char ten){
//	printf("| %d %d ",x,y);
	if(x>=n||y>=m||x<0||y<0)
		return 0;
	che[x][y]=1;
	int i;
	for(i=0;i<4;i++){
		int xp=x+xi[i],yp=y+yi[i];
		if(xp>=n||yp>=m||xp<0||yp<0)
			continue;
		if(a[xp][yp]==ten&&che[xp][yp]==0)
			find(xp,yp,ten);
	}
	return 0;
}
int main(void){
	int T;
	int i,j,k,cnt=1,flag,ans;
	char ten;
	scanf("%d",&T);
	while(T-->0){
		int alp[26]={0};
		ans=0;
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++){
			scanf("%s",a[i]);
			for(j=0;j<m;j++)
				che[i][j]=0;
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(che[i][j]==0){
//					printf("i=%d, j=%d\n",i,j);
					ten=a[i][j];
					alp[int(ten-'a')]++;
					find(i,j,ten);
//					printf("|\n");
				}
			}
		}
		printf("World #%d\n",cnt++);
		for(i=0;i<26;i++){
			flag=0;
			for(j=0;j<26;j++){
				if(alp[j]>alp[flag])
					flag=j;
			}
			if(alp[flag]!=0){
				printf("%c: %d\n",char('a'+flag),alp[flag]);
				alp[flag]=0;
			}
			else
				break;
		}
	}
	return 0;
}
