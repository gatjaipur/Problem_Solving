
//METHOD 1 USING COUNT ARRAY

/*
#include<iostream>
#include<stdlib.h>
using namespace std;
#define NO_OF_CHARS 256

void fillCharCounts(char* str, int* count)
{
	for(int i = 0; *(str + i); i++)
	{
		count[*(str + i)]++;
	}	
}

void printDuplicates(char* str)
{
	int *count = (int*)calloc(NO_OF_CHARS, sizeof(int));
		
	fillCharCounts(str, count);
	
	for(int i = 0; i < NO_OF_CHARS; i++)
	{
		if(count[i] > 1)
		{
			cout << "count [ " << i << "] = " << count[i] << endl;
		}
	}
	
	free(count);
}

*/

//METHOD 2 SORT STRING
/*
#include<iostream>
#include <algorithm>
#include<string.h>
#define MAX_CHAR_NO 1024
using namespace std;

void dupCheck(const string& str)
{
	int count = 1;
	char temp[MAX_CHAR_NO] = {0};
	strncpy(temp, str.c_str(), sizeof(temp));
	
	for(int i = 0; temp[i]; ++i)
	{
		for(int j = i + 1; temp[j] == temp[i]; ++j)
		{
			if(temp[j] == temp[i])
			{
				count++;
				i=j;
			}
		}
			if(count>=2)
			{
				cout << "dup char = " << temp[i] << " with count as " << count << endl;
				count =1;
			}
		
	}
}

int main()
{
	string str = "  I am Gaurav    ";
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	sort(str.begin(), str.end());
	cout << str << endl;
	if(!str.empty())
	{
		dupCheck(str);
	}
	
	return 0;
}

*/

//METHOD 3 USING SET IGNORING SPACE AND NON DUPLICATE CHAR


#include <iostream> 
#include <set>

using namespace std;

void printDups(const string& s)
{
	set<char> dup;
	set<char> chars;
	//USE MAP if you want count of duplicates too
	
	for(string::size_type i = 0; i < s.size(); i++)
	{
		char c = s[i];
		
		if(!isspace(static_cast<int>(c)))
		{
			if(chars.count(c) == 0)
			{
				chars.insert(c);
			}
			else
			{
				dup.insert(c);
			}
		}
	}
	
	cout << " Duplicates : ";
	
	for(std::set<char>::const_iterator it = dup.begin(); it != dup.end(); ++it)
	{
		cout << *it <<" ";
	}
}

int main()
{
	string s("I am Gaurav");
	printDups(s);
	return 0;
}


//METHOD 4 USING BAG CONTAINER

/*
#include<iostream>
#include<map>
#include <algorithm>

using namespace std;

template<typename container, typename predicate>
void erase_if(container& items, const predicate& pred)
{
	for(auto it = items.begin(); it != items.end();)
	{
		//error here 
		if(pred(*it))
		{
			it = items.erase(it);	
		}	
		else
		{
			++it;
		}
	}	
}


template<typename T>
using bag = map<T,int>;

bag<char> get_dupes(const string& s)
{
	bag<char> values;
	
	for(auto c: s)
	{
		++values[c];
	}
	
	//remove spaces and non duplicate characters
	erase_if(values, [](const auto& e){
		return (e.first == ' ' || e.second < 2);
	});
	
	return values;
}

ostream& print_dupes(ostream& os, const bag<char>& dupes)
{
	const char *sep = "";
	for(const auto& e: dupes)
	{
		os << sep << e.first << ":" << e.second;
		sep = ", ";
	}
	return os << endl;
}

int main()
{
	for(auto s: {"I am Gaurav", "foobar"})
	{
		print_dupes(cout << s << " has these duplicates " , get_dupes(s));
	}
	return 0;
}

*/
