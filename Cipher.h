/*
 *Establishes all functions and variables used in Cipher.cpp
*/
#ifndef CIPHER_H
#define CIPHER_H
#include<string>
#include"Queue.h"

using namespace std;

class Cipher{
	public:
     		Cipher();
		void setCipher(int,int[]);
		int* getCipher();
		string encodeMessage(string in);
		string decodeMessage(string in);
		
	private:
		int key[100];
		int arraySize;
		Queue access;//Allows me to access functions in the Queue Class.
};
#endif
