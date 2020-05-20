
#include <bits/stdc++.h>

using namespace std;

int main()
{
	    int N;
        bool bFlag = false;
		size_t iTrimIndex;
		string str ;

	 do
        {
            bFlag = false;
            
            // Taking string as input
			std::cout << " \n Please enter sequence of 10 sorted numbers \n";
            
            getline(cin, str);
            
            //Trimming the string
             	iTrimIndex = str.find_first_not_of(" \t");
             	str.erase(0, iTrimIndex);
            
            iTrimIndex = str.find_last_not_of(" \t");
            if(string::npos != iTrimIndex)
            {
            	str.erase(iTrimIndex +1);
			}
			
			N = str.length();

			
//			//Converting string to char array to split
//			char a_strTemp[N + 1];
//			strcpy(a_strTemp, str.c_str());
//			
//			for(int j = 0 ; j < strlen(a_strTemp) ; j++)
//			{
//				printf("char array %d is %c , ", j, a_strTemp[j] );
//			}
//            
//			
//            // Tokenizing the char array with delimitter as space
//              char *token = strtok(a_strTemp, " \t");
//              char a_str[N+1];
//              int i = 0;
//            while(token != NULL)
//            {
//            	a_str[i] = *token;
//            	token = strtok(NULL, " \t ");
//				i++;
//			  }
			
			// Splitting the string into vector with delimitter as space
			vector <string> v_strTokens;
			stringstream strStream(str);
			string strIntermediate;
			while(getline(strStream, strIntermediate, ' '))
    		{
       		 v_strTokens.push_back(strIntermediate);
   			}
     
//    // Printing the token vector
//    for(int i = 0; i < v_strTokens.size(); i++)
//        cout << v_strTokens[i] << '\n';

//			cout << "strlen :: "<< strlen(a_str) << "\n";
//			int j = 0;
//			while(j != strlen(a_str))
//			{
//				printf("char array %d is %c , ", j, a_str[j] );
//				j++;
//			}
			
			//To check for the condition for array length not equal to 10
            if(v_strTokens.size() != 10) 
			{
				bFlag = true;        
            	printf( " \n Please enter sequence of 10 numbers. Current size is  %d \n" , v_strTokens.size());
			}
			
			//converting string vector to int vector
			
			vector<int> v_iConvertToIntVector;
			for(int i =0 ; i < v_strTokens.size() ; i++)
			{	
				int num = atoi(v_strTokens.at(i).c_str());
     			v_iConvertToIntVector.push_back(num);
			}
			
			//converting to int array
			int a_iArr[v_iConvertToIntVector.size()];
			copy(v_iConvertToIntVector.begin(), v_iConvertToIntVector.end(), a_iArr);

//for(int i =0 ; i < v_iConvertToIntVector.size() ; i++)
//{
//	cout << v_iConvertToIntVector.at(i) << "\n";
//}
            // Checking for sorted sequence
            for(int i = 0; i < v_iConvertToIntVector.size(); i++)
            {
//            	a_iArr[i] = atoi(a_str[i].c_str());
//                printf("int array %d is %c , ", i, a_iArr[i] +1 );
                        
            if( i>0 && a_iArr[i-1] >  a_iArr[i] )
            {
                bFlag = true;
                break;
            }
            
            }            
        } while(bFlag);

		cout << "You have entered sorted sequence of size 10 as "  << str;

	return 0;
}

