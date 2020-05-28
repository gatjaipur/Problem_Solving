#include<iostream>
#include<fstream>
using namespace std; 


int main() {

fstream file;
string fileNema = "myFile.txt";
file.open(fileNema.c_str(), ios::out | ios::in | ios::app);

if(!file) {
cout << "file not created" <<endl;

} else {
cout << "file created" <<endl;
}


file.write("This is an apple",16);
file.write("\nThis is a mango",17);

//It will give ptr to the end of file
long pos = file.tellp();
cout << "pos " << pos << endl;

//It will decrease ptr to 6 units
file.seekp (pos-6);

//It will overwrite text at ptr location
file.write(" tan",4);

if(file.is_open()) {
cout << "File is Open" << endl;

//To start appending from beginning of text in file
file.seekp (0);

string word;
// extracting words from the file 
while (file >> word) 
{ 
// displaying content 
cout << word << endl; 
} 

//	Here pos is -1
long posi = file.tellp();
cout << "posi " << posi << endl;

//			append the text in the same file here, we can mention another file stream here too anotherFile << file.rdbuf()
        file << file.rdbuf(); //For appending the text

} else{
cout << " error in file opening" << endl;
}

file.close();

return 0;
}
