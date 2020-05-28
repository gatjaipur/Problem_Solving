#include<iostream>
using namespace std;
    void printSmallerNext(int arr[], int n)
    {
        for(int i =0; i < n; i++)
        {
            if(arr[i +1] < arr[i] && (i+1 < n))
            {
                cout << arr[i+1] << " ";
            }
            else
            {
               cout << "-1 "; 
            }
        }
    }

int main() {
	//code
	int T;
	cin >> T;
	int n;
	while(T--)
	{
	    cin >> n;
	    int arr[n];
	    
	    for(int i =0 ; i < n; i++)
	    {
	    cin >> arr[i];
	    }
	    
	    printSmallerNext(arr, n);
	    cout << "\n";
	}
	
	return 0;
}
