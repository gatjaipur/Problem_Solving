#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void seggregateNumbers(int *p, int left, int right)
{
   int mid = left;
   
   while(mid <= right)
   {
       switch(p[mid])
       {
           case 0: swap(&p[left++], &p[mid++]);
           break;
           case 1: mid++;
           break;
           case 2: swap(&p[mid++], &p[right--]);
           break;
       }
   }
}

void print(int *p, int N)
{
    for(int i = 0; i< N; i++)
    {
        cout << p[i] <<" " ;
        
    }
    cout <<"\n";
}


int main() {
	//code
	
	int iTestCase;
	cin >> iTestCase;
	
	while (iTestCase--)
	{
	    int N;
	    cin >> N;
	    
	    int *p = new int[N];
	    
	    if(!p)
	    {
	        cout << " p is null " << endl;
	        
	    }
	    else
	    {
	        for(int i = 0; i< N ; i++)
	        {
	            cin >> p[i];
	        }
	    }
	    
	    seggregateNumbers(p,0, N-1);
	    print(p, N);
	    delete[] p;
	}
	return 0;
}
