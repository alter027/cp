#include<iostream>
#include<cstdio>
using namespace std;
int main(void){
	int n;
	cin>>n;
	int total=0,f1=0,i=0,j,k;
	for(i=0;i<n;i++){
		scanf("%d",&k);
		total+=k;
		if(total&1)
			f1=1;
	}
	if(f1)
		cout<<"First";
	else
		cout<<"Second";
	return 0;
}
