#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int rotateByDBits(int n, int d, string dir) {
	if(dir == "left") {

return (n << d) | (n >> (32-d));

	} else if (dir == "right") {
				return (n >> d | n << (32-d));

	}
}

int main() 
{ 
	int n = 16;
	int d = 2;
	string dir = "left";
	
    cout << rotateByDBits(n, d, dir);
	return 0; 
} 
