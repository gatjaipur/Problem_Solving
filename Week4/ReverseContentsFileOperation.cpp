#include<fstream> 
#include <iostream> 

// function to perform the task 
// accepts the parameter str as the text to 
// be stored in text file 


#include<iostream>
#include<fstream>
using namespace std; 


void reverse(string str) 
{ 
fstream file;
string fileNema = "myFile3.txt";
file.open(fileNema.c_str(), ios::out | ios::in /* | ios::app It will append the text on every file creation, otherwise overwritten will be done*/);
long posit = file.tellp();
if(!file) {
cout << "file not created" <<endl;



} else {
cout << "file created" <<endl;int len = str.length();
file.write(str.c_str(), len);
posit = file.tellp();
cout << "tellP " << file.tellp()  << endl;
file.seekg(--posit); 
cout << "tellP 2 " << file.tellp() << endl;

}



fstream file2;
file2.open("myFile4.txt", ios::out);
if(!file2) {
cout << "file 4 not created" <<endl;

} else {
cout << "file 4 created" <<endl;
char ch;
	while (posit >= 0) { 
		// reading from the file 1 
		file.get(ch); 

		// writing to the file 2 
		file2.put(ch); 

		/* shifting read pointer position one 
		alphabet backwards in the text file */
		posit--; 

		file.seekg(posit); 
	} 

}




file2.close();

file.close();

//
//	while (pos >= 0) { 
//		// reading from the file 1 
//		ifs.get(ch); 
//
//		// writing to the file 2 
//		ofs1.put(ch); 
//
//		/* shifting read pointer position one 
//		alphabet backwards in the text file */
//		pos--; 
//
//		ifs.seekg(pos); 
//	} 
//
//	ifs.close(); 
//	ofs1.close(); 
//
//	ifstream ifs1; 
//	ifs1.open("Geeks2.txt", ios::in); 
//
//	// file.eof() checks the end of the text file 
//	while (!ifs1.eof()) { 
//		ifs1.get(ch); 
//		cout << ch; 
//	} 
//	ifs1.close(); 
} 

// Driver code 
int main() 
{ 

	// passing first text file's text 
	// through reverse function 
	reverse("Geeks For Geeks"); 

	return 0; 
} 

