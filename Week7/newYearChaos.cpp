//T(n) = O(n)
/*
It's New Year's Day and everyone's in line for the Wonderland rollercoaster ride! 
There are a number of people queued up, and each person wears a sticker indicating their initial position in the queue.
 Initial positions increment by  from  at the front of the line to  at the back.

Any person in the queue can bribe the person directly in front of them to swap positions.
 If two people swap positions, they still wear the same sticker denoting their original places in line. One person can bribe 
 at most two others. For example, if  n = 8 and person 5 bribes person 4 , the queue will look like this: 1 2 3 5 4 6 7 8

Fascinated by this chaotic queue, you decide you must know the minimum number of bribes that took place to 
get the queue into its current state!
Print an integer denoting the minimum number of bribes needed to get the queue into its final state.
Print Too chaotic if the state is invalid, i.e. it requires a person to have bribed more than  people.

Sample Input

2
5
2 1 5 3 4
5
2 5 1 3 4

Sample Output

3
Too chaotic

*/

#include <bits/stdc++.h>

using namespace std;

//vector<string> split_string(string);

void minimumBribes(vector<int> A) 
{
    int n = A.size();
    int cnt = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        if(A[i] != (i + 1))
        {
            if(((i - 1) >= 0) && A[i - 1] == (i + 1))
            {
                cnt++;
                swap(A[i], A[i-1]);
            }
            else if(((i - 2) >= 0) && A[i - 2] == (i + 1))
            {
                cnt += 2;
                                swap(A[i - 2], A[i-1]);
                swap(A[i - 1], A[i]);

            }
            else
            {
                printf("Too chaotic\n");
                return;
            }
        }      
    }
    printf("%d\n",cnt);
    return;
}


int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

      //  string q_temp_temp;
      //  getline(cin, q_temp_temp);

       // vector<string> q_temp = split_string(q_temp_temp);

        vector<int> q(n);

//        for (int i = 0; i < n; i++) {
//            int q_item = stoi(q_temp[i]);
//
//            q[i] = q_item;
//        }


		for(int i =0; i< n; i++)
		{
			cin >> q[i];
		}
        minimumBribes(q);
    }

    return 0;
}

//Works in C++11
//
//vector<string> split_string(string input_string) {
//    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
//        return x == y and x == ' ';
//    });
//
//    input_string.erase(new_end, input_string.end());
//
//    while (input_string[input_string.length() - 1] == ' ') {
//        input_string.pop_back();
//    }
//
//    vector<string> splits;
//    char delimiter = ' ';
//
//    size_t i = 0;
//    size_t pos = input_string.find(delimiter);
//
//    while (pos != string::npos) {
//        splits.push_back(input_string.substr(i, pos - i));
//
//        i = pos + 1;
//        pos = input_string.find(delimiter, i);
//    }
//
//    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));
//
//    return splits;
//}
