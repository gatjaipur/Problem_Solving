/* Method 1 (Two Arrays at a time)
T(N) = O(m+n+o)
space complexity to O(m+n) */
/*
// C++ program to merge three sorted arrays 
// by merging two at a time. 
#include <iostream> 
#include <vector> 
using namespace std; 

using Vector = vector<int>; 

void printVector(const Vector& a) 
{ 
	cout << "["; 
	for (auto e : a) 
		cout << e << " "; 
	cout << "]" << endl; 
} 

Vector mergeTwo(Vector& A, Vector& B) 
{ 
	// Get sizes of vectors 
	int m = A.size(); 
	int n = B.size(); 

	// Vector for storing Result 
	Vector D; 
	D.reserve(m + n); 

	int i = 0, j = 0; 
	while (i < m && j < n) { 

		if (A[i] <= B[j]) 
			D.push_back(A[i++]); 
		else
			D.push_back(B[j++]); 
	} 

	// B has exhausted 
	while (i < m) 
		D.push_back(A[i++]); 

	// A has exhausted 
	while (j < n) 
		D.push_back(B[j++]); 

	return D; 
} 

int main() 
{ 
	Vector A = { 1, 2, 3, 5 }; 
	Vector B = { 6, 7, 8, 9 }; 
	Vector C = { 10, 11, 12 }; 

	// First Merge A and B 
	Vector T = mergeTwo(A, B); 

	// Print Result after merging T with C 
	printVector(mergeTwo(T, C)); 
	return 0; 
} 
*/

// Method 2 (Three arrays at a time)
// the space complexity is O(1).
// The Time Complexity is O(m+n+o)

// C++ program to merger three sorted arrays 
// by merging three simultaneously. 
#include <iostream> 
#include <vector> 
using namespace std; 

using Vector = vector<int>; 

void printVector(const Vector& a) 
{ 
	cout << "["; 
	for (auto e : a) { 
		cout << e << " "; 
	} 
	cout << "]" << endl; 
} 

Vector mergeThree(Vector& A, Vector& B, 
				Vector& C) 
{ 
	int m, n, o, i, j, k; 
	// Get Sizes of three vectors 
	m = A.size(); 
	n = B.size(); 
	o = C.size(); 

	// Vector for storing output 
	Vector D; 
	D.reserve(m + n + o); 

	i = j = k = 0; 

	while (i < m && j < n && k < o) { 

		// Get minimum of a, b, c 
		int m = min(min(A[i], B[j]), C[k]); 

		// Put m in D 
		D.push_back(m); 

		// Increment i, j, k 
		if (m == A[i]) 
			i++; 
		else if (m == B[j]) 
			j++; 
		else
			k++; 
	} 

	// C has exhausted 
	while (i < m && j < n) { 
		if (A[i] <= B[j]) { 
			D.push_back(A[i]); 
			i++; 
		} 
		else { 
			D.push_back(B[j]); 
			j++; 
		} 
	} 

	// B has exhausted 
	while (i < m && k < o) { 
		if (A[i] <= C[k]) { 
			D.push_back(A[i]); 
			i++; 
		} 
		else { 
			D.push_back(C[k]); 
			k++; 
		} 
	} 

	// A has exhausted 
	while (j < n && k < o) { 
		if (B[j] <= C[k]) { 
			D.push_back(B[j]); 
			j++; 
		} 
		else { 
			D.push_back(C[k]); 
			k++; 
		} 
	} 

	// A and B have exhausted 
	while (k < o) 
		D.push_back(C[k++]); 

	// B and C have exhausted 
	while (i < m) 
		D.push_back(A[i++]); 

	// A and C have exhausted 
	while (j < n) 
		D.push_back(B[j++]); 

	return D; 
} 

int main() 
{ 
	Vector A = { 1, 2, 41, 52, 84 }; 
	Vector B = { 1, 2, 41, 52, 67 }; 
	Vector C = { 1, 2, 41, 52, 67, 85 }; 

	// Print Result 
	printVector(mergeThree(A, B, C)); 
	return 0; 
} 


