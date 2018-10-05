#include<bits/stdc++.h>
using namespace std;

int ans;

int solve(){
	string str;
	cin >> str;
	int i,j,len=str.size(),flag=0,rec;
	for(i=1,j=1;i<len;i++,j++){
		if(str[j]==str[0]){
			rec=j;
			for(j=0;i<len;i++,j++){
				if(str[i]!=str[j])
					flag=1;
				if(j>=rec)
					j-=rec;
			}
		}
		if(flag==1)
			break;
	}
	if(flag==1){
		for(i=0;i<rec;i++)
			printf("%c",str[i]);
		cout<<str<<endl;
	}
	return flag;
 }
int main(void){
	int T,Case=1;
	int a,b;
	scanf("%d",&T);
	while(T-->0){
		printf("Case #%d: ",Case++);
		if(solve()==0)
			printf("Impossible\n");
	}
	return 0;
 }