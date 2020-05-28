#include<iostream>
#include<math.h>
using namespace std;

int findMinDistance(int Xarr[], int Yarr[], int n) {
	

	if(n<2) {
		return 0;
	}
	int total = 0;
	for(int i = 0; i< n-1; i++) {
		
		int diff1 = abs(Xarr[i+1] - Xarr[i]);
		int diff2 = abs(Yarr[i+1] - Yarr[i]);
		total += max(diff1, diff2);
		
		
		//		total += max(diff1, diff2); gives total moves including diagonal and horizontal/vertical
//		total += min(diff1, diff2); gives total diagonal moves

	}
	return total;
}

int main() {
	int Xarr[] = {0, 1, 1};
	int Yarr[] = {0, 1, 2};
		int n = sizeof(Xarr)/sizeof(Xarr[0]);
	cout << findMinDistance(Xarr, Yarr, n);
	
	return 0;
}


/*

Same Method Different Structure

//Minimum steps needed to cover a sequence of points on an infinite grid
//T(n) = O(N)
// C++ program to cover a sequence of points 
// in minimum steps in a given order. 
#include <bits/stdc++.h> 
using namespace std; 

// cell structure denoted as point 
struct point { 
	int x, y; 
}; 

// function to give minimum steps to 
// move from point p1 to p2 
int shortestPath(point p1, point p2) 
{ 
	// dx is total horizontal 
	// distance to be covered 
	int dx = abs(p1.x - p2.x); 

	// dy is total vertical 
	// distance to be covered 
	int dy = abs(p1.y - p2.y); 

	// required answer is 
	// maximum of these two 
	return max(dx, dy); 
} 

// Function to return the minimum steps 
int coverPoints(point sequence[], int size) 
{ 
	int stepCount = 0; 

	// finding steps for each 
	// consecutive point in the sequence 
	for (int i = 0; i < size - 1; i++) { 
		stepCount += shortestPath(sequence[i], 
								sequence[i + 1]); 
	} 

	return stepCount; 
} 

// Driver code 
int main() 
{ 
	// arr stores sequence of points 
	// that are to be visited 
	point arr[] = { { 4, 6 }, { 1, 2 }, { 4, 5 }, { 10, 12 } }; 

	int n = sizeof(arr) / sizeof(arr[0]); 
		
	cout << coverPoints(arr, n) ; 
} 
*/
