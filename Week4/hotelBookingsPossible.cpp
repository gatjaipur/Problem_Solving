#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
    
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    
    int ar = 0;
    int de = 0;
    int nos = 0;
    int satisfy = 0;
    
    while(ar < arrive.size() && de < depart.size()) {
        
        if(arrive[ar] < depart[de]) {
            ar++;
            nos++;
            satisfy = max(nos, satisfy);
            
        } else {
            de++;
            nos--;
        }
    }
    
    if(satisfy <= K) {
        return true;
    } 
    
    return false;


}


int main() {
	
	vector<int> arrive;
	arrive.push_back(1); 
		arrive.push_back(3); 
	arrive.push_back(5); 

	vector<int> depart; 	
	depart.push_back(2);
		depart.push_back(6);
	depart.push_back(8);

	int K = 2;
	cout << hotel(arrive, depart, K);
	return 0;
}
