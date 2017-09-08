#include<iostream>
using namespace std;
int main(void){
	long long n,k;
	cin>>n>>k;
	if(k==0){
		cout<<"0 0";
		return 0;
	}
	if(n==k)
		cout<<"0 ";
	else
		cout<<"1 ";
	if(n>=k*3)
		cout<<k*2;
	else
		cout<<n-k;
	return 0;
}
