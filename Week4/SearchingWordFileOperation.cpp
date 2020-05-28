#include<iostream>
#include<fstream>
using namespace std; 


int main() {

fstream file;
string fileNema = "myFile2.txt";
file.open(fileNema.c_str(), ios::out | ios::in | ios::app);

if(!file) {
cout << "file not created" <<endl;

} else {
cout << "file created" <<endl;
}


file.write("This is an apple",16);
file.write("\nThis is a mango",17);
	long posit = file.tellp();
cout << "posit " << posit << endl;
string line;
size_t pos;
	//Currently ptr is at end of file, bring to 0 for reading the input
	file.seekp (0);
	int index;
int len;
while(getline(file,line))
		{
			cout << "line : " << line << endl;
			len = line.length();
 
			//searching for a part of string in file for all the occurences
			 pos = line.find("man");
			 
			cout << "pos : " << pos << endl;
			if(pos!=string::npos) // string::npos is returned if string is not found
        {
            cout <<"Found! at " << (index + pos)  << endl;
            
            //If we want to find only the first occurence then break here
            //break;
        }
        			index+=len;


		}
		

//Marks the end of file, location of ptr is -1
cout << file.eof()<< "eof"<<endl;
	file.close();

return 0;
}
