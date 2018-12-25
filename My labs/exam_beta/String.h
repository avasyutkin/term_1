#pragma once 
#pragma warning(disable:4996) 
#include <iostream> 

class String
{
public:

	char *str;
	int strlen;
	int length(char*str1);
	char* Add(char* str1);
	char* Cut(int num, int qu);
	char* insert(int num, char* sl);
	void clear();

	String();
	String(const String& lhs);
	String(char * str1);
	~String();

};