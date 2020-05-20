#include<iostream>
using namespace std;

//Square Bottom Left 
void printPattern1() {
	
	for (int i = 1; i <= 5; i++) {
		for(int j = 1; j<=i; j++) {
			cout << "*";
		}
		cout << "\n";
	}	
}

//Square Top Left 
void printPattern2() {
	
	for (int i = 5; i>=1; i--) {
		for(int j = 1; j<=i; j++) {
			cout << "*";
		}
		cout << "\n";
	}	
}

//Square Bottom Right
void printPattern3() {
	int temp = 1;
	for (int i = 5; i>=1; i--) {
		for(int j = 1; j<i; j++) {
			cout << " ";
		}
		
		for(int k = temp; k>0; k--) {
						cout << "*";
		}
		
		temp++;
		cout << "\n";
	}	
}

//Square Top Right
void printPattern4() {
	int temp = 0;
	for (int i = 5; i>=1; i--) {
		for(int k = temp; k>0; k--) {
						cout << " ";
		}
		
		for(int j = 1; j<=i; j++) {
			cout << "*";
		}
		
		temp++;
		cout << "\n";
	}	
}

//Square Matrix 
void printPattern5() {
	
	for (int i = 1; i<=5; i++) {
		for(int j = 1; j<=5; j++) {
			cout << "*";
		}
		cout << "\n";
	}	
}


//Top Triangle
void printPattern6() {
	
	int temp = 0;
	
	for (int i = 1; i<=5; i++) {
		for(int j = temp; j<5; j++) {
			cout << " ";
		}
		
		for(int k = 1; k<=i; k++) {
			cout << " * ";
		}
		
		temp++;
		cout << "\n";
	}	
}


//Left Triangle
void printPattern7() {

		int temp = 1;
	for (int i = 5; i>=1; i--) {
		for(int j = 1; j<i; j++) {
			cout << " ";
		}
		
		for(int k = temp; k>0; k--) {
						cout << "*";
		}
		
		temp++;
		cout << "\n";
	}	
	
	int temp2 = 1;
	for (int i = 4; i>=1; i--) {
		for(int k = temp2; k>0; k--) {
						cout << " ";
		}
		
		for(int j = 1; j<=i; j++) {
			cout << "*";
		}
		
		temp2++;
		cout << "\n";
	}	
}


//Right Triangle
void printPattern8() {

	for (int i = 1; i <= 5; i++) {
		for(int j = 1; j<=i; j++) {
			cout << " * ";
		}
		cout << "\n";
	}		
		for (int i = 4; i>=1; i--) {
		for(int j = 1; j<=i; j++) {
			cout << " * ";
		}
		cout << "\n";
	}	
}


//Bottom Triangle
void printPattern9() {
		
		int temp = 0;
		
		for(int i = 5; i>=1; i--) {
			for(int j = temp; j>0; j--) {
				cout << " ";
			}
			
			for(int k = 1; k<=i; k++) {
				cout << " * ";
			}
			temp++;
			cout << "\n";
			
		}
}

//Pascal Triangle
void printPattern10() {
	
	int temp = 5;
	
	for (int i = 0; i<5; i++) {
		for(int j = temp; j>=1; j--) {
			cout << " ";
		}
		int p = 1;
		int num = i;
		int den = 1;
		
		for(int k = 0; k<=i; k++) {
			cout << " " << p << " ";
		
		p*=num;	

		p/=den;
		num--;	den++;
		}
		temp--;
		cout << "\n";
	}	
}



//Pascal Triangle
void printPattern11() {
for (int i = 1; i <= 5; i++) 
{ 
    int C = 1; // used to represent C(line, i) 
    for (int j = 1; j <= i; j++)  
    { 
          
        // The first value in a line is always 1 
        cout<< C<<" ";  
        C = C * (i - j) / j;  
    } 
    cout<<"\n"; 
}
}

int main() {
	
	printPattern1();
	cout << "\n";
	cout << "\n";

	printPattern2();
	cout << "\n";
	cout << "\n";
	
	printPattern3();
	cout << "\n";
	cout << "\n";
	
	printPattern4();
	cout << "\n";
	cout << "\n";
	
	printPattern5();
	cout << "\n";
	cout << "\n";
	
	printPattern6();
	cout << "\n";
	cout << "\n";
	
	printPattern7();
	cout << "\n";
	cout << "\n";
	
	printPattern8();
	cout << "\n";
	cout << "\n";
	
	printPattern9();
	cout << "\n";
	cout << "\n";
	
	printPattern10();
	cout << "\n";
	cout << "\n";
	
	printPattern11();
	cout << "\n";
	cout << "\n";
	
	return 0;
}
