/*
Example 3: Given two sorted integer arrays arr1 and arr2, 
return a new array that combines both of them and is also sorted.

//Approach 1: Combine both array and then sort. T = O(nlogn)

//Approach 2: Two pointer approach as sorted array. T = O(n), S = O(1)

*/

vector<int> combine(vector<int>& arr1, vector<int>& arr2) {
    // ans is the answer
    vector<int> ans;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            ans.push_back(arr1[i]);
            i++;
        } else {
            ans.push_back(arr2[j]);
            j++;
        }
    }
    
    while (i < arr1.size()) {
        ans.push_back(arr1[i]);
        i++;
    }
    
    while (j < arr2.size()) {
        ans.push_back(arr2[j]);
        j++;
    }
    
    return ans;
}