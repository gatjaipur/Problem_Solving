
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

    void countingSort(string arr[],int index,char lower,char upper, int n)
	{
    int countArray[(upper-lower)+2] ={0};
    string tempArray[n];
    
    //increase count for char at index
    for(int i=0;i<n;i++){
      int charIndex = (arr[i].length()-1 < index) ? 0 : ((arr[i][(index)]- lower)+1);
      countArray[charIndex]++;
    }
    
    //sum up countArray;countArray will hold last index for the char at each strings index
    int nCountArray = sizeof(countArray)/sizeof(countArray[0]);
    
    for(int i=1;i<nCountArray;i++){
      countArray[i] += countArray[i-1];
    }
    
    for(int i=n-1;i>=0;i--){
      int charIndex = (arr[i].length()-1 < index) ? 0 : (arr[i][(index)] - lower)+1;
      tempArray[countArray[charIndex]-1] = arr[i];
      countArray[charIndex]--;
    }
        int nTempArray = sizeof(tempArray)/sizeof(tempArray[0]);

    for(int i=0;i<nTempArray;i++){
      arr[i] = tempArray[i];   
    }
  }
  
  //find the maximum string length in the array, here 9-1 =8
   void radixSort(string arr[],char lower,char upper, int n){
    int maxIndex = 0;
    for(int i=0;i<n ;i++){
      if(arr[i].length()-1 > maxIndex){
        maxIndex = arr[i].length()-1;
      }
    }
    
    for(int i=maxIndex;i>=0;i--){
      countingSort(arr,i,lower,upper, n);
    }
  }
  
    int main () {
    string arr[] = {"apple", "australia", "algorithm","sell", "olympic","jack","sleep"};
        int length = sizeof(arr)/sizeof(arr[0]);

    radixSort(arr,'a','z', length);
    
    for(int i=0;i< length;i++){
      cout << (arr[i]) << " ";
    }
    return 0;
  }

