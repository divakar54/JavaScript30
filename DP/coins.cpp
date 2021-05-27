#include<iostream>
#include<vector>
using namespace std;

vector<int> coins = { 1, 5, 10,20,100};

vector<int> value(1000, 0);

int solve(int x){
	
	value[0]=0;
	
	for(int i=1; i <= x; i++){
		value[i]=INT_MAX;
		for(int c : coins){
			if(i-c >= 0){
				value[i] = min(value[i], value[i-c]+1);
			}
		}
	}
	return value[x];
}

int main(){
	int res=0;
	res=solve(122);
	cout<< res;
	
	return 0;	
}
