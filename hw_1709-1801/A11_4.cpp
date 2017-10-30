#include<bits/stdc++.h>
using namespace std;
const int INF=1023456789;
int n,m;
int arr[205][205];
void print_arr(void){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(arr[i][j]!=INF&&arr[i][j]!=-1)
				printf("%3d ",arr[i][j]);
			else
				printf("  x ");
		}
		printf("\n\n");
	}
 }
void waterfloyd(void){
	int i,j,k;
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if((arr[i][k]!=INF&&arr[k][j]!=INF)&&(arr[i][j]>arr[i][k]+arr[k][j])){
					arr[i][j]=arr[i][k]+arr[k][j];
				}
			}
		}
	}
 }
void count_answer(void){
	int i,j,k;
	int c1=0,c2=0,c3=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(arr[i][j]>=INF)
				c1++;
			else if(arr[i][j]<=-INF)
				c2++;
			else
				c3++;
		}
	}
	printf("%d %d %d\n",c1,c2,c3);
 }
int main(void){
	int T,a,b,w;
	int i,j,k;
	scanf("%d",&T);
	while(T-->0){
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)
				arr[i][j]=INF;
		}
		for(i=0;i<n;i++)
			arr[i][i]=0;
		while(m-->0){
			scanf("%d%d%d",&a,&b,&w);
			a--;b--;
			if(w<arr[a][b])
				arr[a][b]=w;
		}
		waterfloyd();
		for(i=0;i<n;i++){
			if(arr[i][i]<0){
				for(j=0;j<n;j++){
					arr[j][i]=(arr[j][i]<INF)?-INF:INF;
					arr[i][j]=(arr[i][j]<INF)?-INF:INF;
				}
			}
		}
		waterfloyd();
		count_answer();
	}
	return 0;
} 

