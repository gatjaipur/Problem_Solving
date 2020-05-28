#include <iostream>
using namespace std;

void minOneIndex(int arrValues[],const int &m,const int &n)
{
    
    int minOne=n;
    int row=0;
    int minRow=0;
    for(int i=n-1; i<(m*n) ; i+=n)
    {
        
        int count=0;
        for(int j=0; j<n;j++)
        {
            
            if(arrValues[i-j]!=1){break;}
            else
            {
                count++;
            }
            
        }
        if(count<minOne && count!=0)
        {
            minOne=count;
            minRow=row;
            
        }
        row++;
        
    }
    
    cout<<minRow<<endl;
}

int main()
{

int T,m,n;
int nm[2];


cin>>T;

while(T--)
{
    for(int i=0; i<2;i++)
    {
        cin>> nm[i];
    }
    //nm[0]- no of row
    //nm[1]- no of column
    m=nm[0];
    n=nm[1];
    
    int values[m*n];
    int zeroCount=0;
    int onesCount=0;
    
    
    for(int i=0; i<m*n  ; i++)
    {
        cin>> values[i];
        
        if(values[i]==0){zeroCount++;}
        if(values[i]==1){onesCount++;}
    }
   
   
   if(zeroCount==(m*n))
   {
       cout<< "-1"<<endl;
   }
   else{ if(onesCount==(m*n))
            {
               cout<< "0" <<endl; 
            }
            else{
             minOneIndex(values,m,n);
                }
        }
}

	return 0;
}
