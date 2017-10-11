#include<stdio.h>
int m,n;int arr[1005][1005];int step[1005][1005];
int yd[2000000],xd[2000000];//deque
int ans;int c1,c2;
int farstep;
int p[4]={1,-1,0,0},q[4]={0,0,1,-1};
void bfs(int x,int y){
	int i,j,k;
	yd[0]=y;xd[0]=x;
	step[x][y]=0;
	c1=0;c2=0;
	for(;step[x][y]<=farstep&&c1<=c2;x=xd[c1],y=yd[c1],c1++){
		ans+=arr[x][y];arr[x][y]=-3;
//		printf("x=%d,y=%d,c1=%d,ans=%d\n",x,y,c1,ans);
		for(i=0;i<4;i++){
			if(arr[x+p[i]][y+q[i]]==-1)
				farstep=step[x][y]+1;
			if(arr[x+p[i]][y+q[i]]>-1&&x+p[i]>-1&&
									   x+p[i]<m &&
									   y+q[i]>-1&&
									   y+q[i]<n &&
									   step[x+p[i]][y+q[i]]==0){
				xd[c2]=x+p[i];yd[c2++]=y+q[i];
				step[x+p[i]][y+q[i]]=step[x][y]+1;
			}
		}
	}
}
int main(void){
	ans=0;
	char input[1050];int fx,fy;int i,j,k;
	farstep=100000000;ans=0;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
			step[i][j]=0;
	}
	for(i=0;i<m;i++){
		scanf("%s",input);
		for(j=0;j<n;j++){
			if(input[j]=='S'){
				arr[i][j]=-1;
			}
			else if(input[j]=='E'){
				arr[i][j]=-2;
				fx=i;fy=j;
			}
			else if(input[j]=='T'){
				arr[i][j]=-3;
			}
			else{
				arr[i][j]=(int)input[j]-48;
			}
		}
	}
//	printf("%d %d\n",fx,fy);
	bfs(fx,fy);
	printf("%d\n",ans+2);
	return 0;
}

