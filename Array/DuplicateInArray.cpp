// Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.

// Sample Input:

// [3 4 1 4 1]
// Sample Output:

// 1
// If there are multiple possible answers ( like in the sample case above ), output any one.

// If there is no duplicate, output -1

// Method - 1 Using boolean vector

// int Solution::repeatedNumber(const vector<int> &A) {
    
//     int size=A.size();
// vector<bool> v(size);
// fill(v.begin(),v.end(),true);
// for(int i=0;i<size;i++)
// {
// if(v[A[i]]) v[A[i]]=false; 
// else return A[i];

// }
// }

// ..Method 2 
// Time Complexity: O(N)
// Auxiliary Space: sqrt(N)

// Split the numbers from 1 to n in sqrt(n) ranges so that range i corresponds to [sqrt(n) * i .. sqrt(n) * (i + 1)).

// Do one pass through the stream of numbers and figure out how many numbers fall in each of the ranges.

// At least one of the ranges will contain more than sqrt(n) elements.

// Do another pass and process just those elements in the oversubscribed range.

// Using a hash table to keep frequencies, you’ll find a repeated element.

// This is O(sqrt(n)) memory and 2 sequential passes through the stream.

// C++ program to find one of the repeating
// elements in a read only array
// #include <bits/stdc++.h>
// using namespace std;

// // Function to find one of the repeating
// // elements
// int findRepeatingNumber(const int arr[], int n)
// {
// 	// Size of blocks except the
// 	// last block is sq
// 	int sq = sqrt(n);

// 	// Number of blocks to incorporate 1 to
// 	// n values blocks are numbered from 0
// 	// to range-1 (both included)
// 	int range = (n / sq) + 1;

// 	// Count array maintains the count for
// 	// all blocks
// 	int count[range] = {0};

// 	// Traversing the read only array and
// 	// updating count
// 	for (int i = 0; i <= n; i++)
// 	{
// 		// arr[i] belongs to block number
// 		// (arr[i]-1)/sq i is considered
// 		// to start from 0
// 		count[(arr[i] - 1) / sq]++;
// 	}

// 	// The selected_block is set to last
// 	// block by default. Rest of the blocks
// 	// are checked
// 	int selected_block = range - 1;
// 	for (int i = 0; i < range - 1; i++)
// 	{
// 		if (count[i] > sq)
// 		{
// 			selected_block = i;
// 			break;
// 		}
// 	}

// 	// after finding block with size > sq
// 	// method of hashing is used to find
// 	// the element repeating in this block
// 	unordered_map<int, int> m;
// 	for (int i = 0; i <= n; i++)
// 	{
// 		// checks if the element belongs to the
// 		// selected_block
// 		if ( ((selected_block * sq) < arr[i]) &&
// 				(arr[i] <= ((selected_block + 1) * sq)))
// 		{
// 			m[arr[i]]++;

// 			// repeating element found
// 			if (m[arr[i]] > 1)
// 				return arr[i];
// 		}
// 	}

// 	// return -1 if no repeating element exists
// 	return -1;
// }

// // Driver Program
// int main()
// {
// 	// read only array, not to be modified
// 	const int arr[] = { 1, 1, 2, 3, 5, 4 };

// 	// array of size 6(n + 1) having
// 	// elements between 1 and 5
// 	int n = 5;

// 	cout << "One of the numbers repeated in"
// 		" the array is: "
// 		<< findRepeatingNumber(arr, n) << endl;
// }

//Method 3

// int Solution::repeatedNumber(const vector<int> &nums) {
    
//     int fast = nums[0];
//     int slow = nums[0];
    
//     do{
//         slow = nums[slow];
//         fast = nums[nums[fast]];
//     }while(slow != fast);
    
//     fast = nums[0];
//     while(fast != slow){
//         fast = nums[fast];
//         slow = nums[slow];
//     }
    
//     return fast;
// }

// Method 4

int Solution::repeatedNumber(const vector<int> &A) {
        int n = A.size();
        long long int sum = 0;
        for(int i = 0; i<n; i++){
            sum += A[i];
        }
        long long int m = n-1;
        long long int total = (m * (m+1)) / 2;
        return sum - total;
    }


//Method 5

// int Solution::repeatedNumber(const vector<int> &A) {
    
//     int i,xor1=0,xor2=1;
//     for(i=0;i<A.size();i++)
//     {
//         xor1^=A[i];
//     }
//     int n=A.size();
//     for(i=2;i<=(n-1);i++)
//     {
//         xor2^=i;
//     }
    
//     int repeat;
//     repeat=xor1^xor2;
    
//     return repeat;
// }