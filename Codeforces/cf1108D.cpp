#include<bits/stdc++.h>
using namespace std;
int main(void){
	char A[3]={'R','G','B'};
	int n,cnt=0,j,tmp;string str;
	scanf("%d",&n);
	cin>>str;
	for(int i=0;i<n;){
		j=i+1;tmp=1;
		if(j<n&&str[j]==str[i]) j++,tmp++;
		cnt+=tmp/2;
		i=j;
	}
	for(int i=0;i<n;i++){
		if(i+1<n&&str[i+1]==str[i]){
			for(j=0;j<3;j++){
				if(str[i]==A[j]);
				else if(i+2<n&&str[i+2]==A[j]);
				else break;
			}
			str[i+1]=A[j];
		}
	}
	printf("%d\n",cnt);
	cout<<str;
	return 0;
}
