#include<bits/stdc++.h>
using namespace std;
int color[3][3],ans=0,final[3],cur[3];
void cnt(int tmp){
	if(tmp==3){
		int cnt=0;
		for(int i=0;i<3;i++) cnt+=color[i][cur[i]];
		if(cnt>ans){
			ans=cnt;
			for(int i=0;i<3;i++) final[i]=cur[i];
		}
		// printf("%d %d %d %d\n",cur[0],cur[1],cur[2],ans);
		return;
	}
	int flag=0;
	for(int i=0;i<3;i++){
		flag=0;
		for(int j=0;j<tmp;j++){
			if(cur[j]==i)
				flag=1;
		}
		if(flag==0){
			cur[tmp]=i;
			cnt(tmp+1);
		}
	}
	return;
}
int main(void){
	char A[3]={'R','G','B'};
	int n;string str;
	scanf("%d",&n);
	cin>>str;
	for(int i=0;i<3;i++){
		for(int j=i;j<n;j+=3){
			if(str[j]=='R') color[i][0]++;
			else if(str[j]=='G') color[i][1]++;
			else if(str[j]=='B') color[i][2]++;
		}
	}
	cnt(0);
	printf("%d\n",n-ans);
	for(int i=0;i<n;i++)
		printf("%c",A[final[i%3]]);
	printf("\n");
	return 0;
}
