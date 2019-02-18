#include<bits/stdc++.h>
using namespace std;
int main(void){
	int ans=0,ptr;
	char A[100005]={0};
	string str;
	cin>>str;
	A[0]=str[0],ptr=0;
	for(int i=1;i<str.size();i++){
		if(str[i]==A[ptr])
			ptr--,ans++;
		else
			A[++ptr]=str[i];
	}
	// printf("ans = %d\n",ans);
	if(ans%2)
		printf("Yes\n");
	else
		printf("No\n"); 
	return 0;
}
