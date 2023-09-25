/*
 * Cipher.cpp, This files deals with setting up stuff with Cipher Key and encodeding/decoding strings with the keys.
*/
#include <iostream>
#include "Cipher.h"
#include "Queue.h"
#include <string>

using namespace std;

/*
 *Default Constructor, Intizilizes the defalut Cipher key to 1,2,3,4.
*/
Cipher::Cipher(){
	int myArray[4] = {1,2,3,4};
	setCipher(4,myArray);//Will set the defalut repeting key to 1,2,3,4.
}

/*
 *setCipher, takes in an array size and arrayand sets a Key of Numbers (In an array and queue).
*/
void Cipher::setCipher(int num,int array[]){
	access.clear();
	
	arraySize = num;
	//Check to see if queue has already reached the size limit of 100 values for the key.(Sadly haven't got it to work)
	if(access.isFull()){
	cout << "Queue is Full.";
	}
	
	//Sets the Key from passed in array to the queue(also saves values to key array).
	//Maybe change into While Loop, ex. while (i < num || !access.isFull)
	for (int i = 0; i < num; ++i){
		key[i] = array[i];
		access.enqueue(key[i]);//Uses enqueue to add value into queue.
		
	 }

}

/*
 *getCipher, Returns the Cipher key stored in the array key (by pointer).
*/
int* Cipher::getCipher(){
return key;
}

/*
 *encodeMessage, Takes in a string and uses cipher key to mix up the  \string.
*/
string Cipher::encodeMessage(string in){
 int num;
 int *iptr = &num;
 int dequeuedVal;
 int asciiCount = 1;//adds one each time it goes through the while loop, until it reaches its key value.
 int j = 0;//used to iterate through the while loop.

     int sizeString = in.size();//Establish to prevent warnings.

   for(int i = 0; i < sizeString; ++i){
	   //Checks if a space is present, if so, won't dequeue and values.
	   if(in[i] >= 'A' && in[i] <= 'z'){
	     access.dequeue(*iptr); //Takes value out of queue.
             dequeuedVal = access.saveValue;//Saves value taken out of stack.
	     //cout << dequeuedVal << endl; //Checks the value being dequed each time.
             access.enqueue(dequeuedVal);//This will add dequeued value that what taken from the queue and added it back in.
	   }

		
	   while( j < access.saveValue){
		if (in[i] < 'A' || in[i] > 'z'){
			j = access.saveValue;//This is here because I don't want to read in any other values(thats not in range).
		}

		else{

			in[i] += asciiCount;

		//Thes if statments keep letters in range of 'A' to 'Z' and 'a' and 'z'.	
			if(in[i] > 'z'){
			 in[i] = 'a';
			}
		//If it goes past Uppercase Z, will be rest to the begining of the upper case alphabet.
			else if(in[i] == '['){
			 in[i] = 'A';
			}


		++j;
		}
	   }//End of While Loop.

	   j = 0;//Resets the value after finished with while loop.

	 }//End of For Loop

  
return in;
}

/*
 *decodeMessage, Takes in string and decodes the string using a cipher key.
*/
string Cipher::decodeMessage(string in){
	//cout << "\nIn dencodeMessage (" << in << ")"; 
 int value;
 int *iptr = &value;
 int dequeuedVal;
 int asciiCount = 1;//adds one each time it goes through the while loop, until it reaches its key value.
 int j = 0;//used to iterate through the while loop.

     setCipher(arraySize,key);//sets queue back to the way it was first encoded.
    int sizeString = in.size();//sets the int to the size of the string, helps avoid warning.

 	for (int i = 0; i < sizeString; i++){	
	  //cout << "\nin[" << i << "] = " << in[i] << " ";
	  
	   if(in[i] >= 'A' && in[i] <= 'z'){
	     access.dequeue(*iptr); //Takes value out of queue.
             dequeuedVal = access.saveValue;//Saves value taken out of stack.

	    // cout << "Dequeued value: " <<  dequeuedVal << endl; //Checks the value being dequed each time.
	    
             access.enqueue(dequeuedVal);//This will add dequeued value that what taken from the queue and added it back in.

	    // cout << "access = " << access.saveValue << " "; 
	   }

	   while (j < access.saveValue){
	     if(in[i] < 'A' || in[i] > 'z'){
		     j = access.saveValue;
	     }
	     else{
		  //Subtracts value one by one in while loop until the key value is reached.
		  in[i] -= asciiCount;

		  //cout << in[i] << "  ";Checks what character is after subtracting one.
			
		  //if in[i] subtracts enoguh and equals this value, will be rest to char 'z'.
		  if(in[i] == '`'){
			in[i] = 'z';
		  }
		  
		  //if in[i] subtract enough out of the range 'A' and 'Z', becomes captial 'Z' again.
		  if(in[i] == '@'){
			in[i] = 'Z';
		  }
		
		  //cout << in[i] << ", "; Checks to see if what string at became after going through loop.
		  ++j;
	     }

	  }//End of While.
	  j=0;

	}//End of for loop

return in;
}
