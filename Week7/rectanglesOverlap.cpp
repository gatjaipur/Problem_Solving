/*
Given two rectangles, find if the given two rectangles overlap or not. 
A rectangle is denoted by providing the x and y co-ordinates of two points: the left top corner and the right bottom corner 
of the rectangle.

Note that two rectangles sharing a side are considered overlapping.

Input:

The first integer T denotes the number of test cases. For every test case, there are 2 lines of input. 
The first line consists of 4 integers: denoting the co-ordinates of the 2 points of the first rectangle. 
The first integer denotes the x co-ordinate and the second integer denotes the y co-ordinate of the left topmost corner 
of the first rectangle. The next two integers are the x and y co-ordinates of right bottom corner. 
Similarly, the second line denotes the cordinates of the two points of the second rectangle.


Output:

For each test case, output (either 1 or 0) denoting whether the 2 rectangles are overlapping. 
1 denotes the rectangles overlap whereas 0 denotes the rectangles do not overlap.


Constraints:

1 <= T <= 10

-10000 <= x,y <= 10000

T denotes the number of test cases. x denotes the x co-ordinate and y denotes the y co-ordinate.


Example:

Input:

2
0 10 10 0
5 5 15 0
0 2 1 1
-2 -3 0 2

Output:

1
0

*/

#include <iostream>
using namespace std;

struct Point
{
    int x,y;
};

void doOverlap(int rec1[], int rec2[])
{
	//Top left and bottom right coordinates of Rec1
    Point p={rec1[0],rec1[1]};
    Point q={rec1[2],rec1[3]};
    
    //Top left and bottom right coordinates of Rec2
    Point r={rec2[0],rec2[1]};
    Point s={rec2[2],rec2[3]};
    
    if( (p.x>s.x) || (r.x>q.x) ) 
    {
        cout<<"0"<<endl;
        return;
    }
    
    if((p.y<s.y) || (r.y<q.y))
    {
          cout<<"0"<<endl;
            return;

    }
    
              cout<<"1"<<endl;

}

int main() {

int T;

cin>>T;

int rec1[4];
int rec2[4];
while(T--)
{
    for(int i=0;i<4;i++)
    {
        cin>>rec1[i];
    }
    
    for(int i=0; i<4; i++)
    {
        cin>>rec2[i];
    }
    
    doOverlap(rec1,rec2);
}

	return 0;
}
