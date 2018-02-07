#include<bits/stdc++.h>
using namespace std;

int ans;
char s[100];
void solve(){
	cin.getline(s,75);
	int n=strlen(s);
	printf("+");
	for(int i=0;i<n+2;i++)
		printf("-");
	printf("+\n");
	printf("| ");
	cout<<s;
	printf(" |\n");
	printf("+");
	for(int i=0;i<n+2;i++)
		printf("-");
	printf("+\n");
 }
int main(void){
	int T,Case=1;
	int a,b;
	scanf("%d",&T);
	cin.getline(s,75);
	while(T-->0){
		printf("Case #%d: \n",Case++);
		solve();
	}
	return 0;
}