#include<iostream>
#include<string>
using namespace std;
int main(void){
	int n,k,count[26]={0};
	string str;
	cin>>n>>k;
	cin>>str;
	for(int i=0;i<n;i++){
		count[str[i]-97]++;
	}
	int flag=0;
	for(int i=0;i<26;i++){
		if(count[i]>k)
			flag=1;
	}
	if(flag)
		cout<<"NO";
	else
		cout<<"YES";
	return 0;
}
