#include<bits/stdc++.h>
struct edge{
	int a,b,c;
	char ten;
	bool operator<(const edge&tri) const{
		return b > tri.b 
	}
};
int main(void){
//map
	std::map<int,int>trimap;
	std::map<int,int>::iterator iter;
	trimap[5]=0,trimap[66]=3;
	printf("%d\n",trimap[66]);
	iter=trimap.find(87);
	if(iter==trimap.end())
		printf("Oops...Not find the value...\n");
	iter=trimap.find(5);
	trimap.erase(iter);
	iter=trimap.find(5);
	if(iter==trimap.end())
		printf("Oops...Not find the value...\n");
//priority queue
	std::priority_queue<int>tripri;
	for(int i=0;i<10;i++){
		tripri.push(i*((i%2==0)?1:-1));
	}
	while(!tripri.empty()){
		printf("%d ",tripri.top());
		tripri.pop();
	}
	printf("\n");
	
//priority queue
	std::queue<int>trique;
	for(int i=0;i<10;i++){
		trique.push(i*((i%2==0)?1:-1));
	}
	while(!trique.empty()){
		printf("%d ",trique.front());
		trique.pop();
	}
	printf("\n");
	
	return 0;
}
