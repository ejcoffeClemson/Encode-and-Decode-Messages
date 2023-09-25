#include <iostream>
#include "Cipher.h"
#include "Queue.h"

using namespace std;
void test(){
Queue test1;
Cipher test2;

cout << test2.encodeMessage("dog") << endl;
cout << test2.decodeMessage("eqj") << endl;

int array[] = {1,0,2};
test2.setCipher(3,array);

cout << test2.encodeMessage("TurtlE") << endl;
cout << test2.decodeMessage("UutulG") << endl;

cout << test2.encodeMessage("Zebras, have, stripes") << endl;
cout << test2.decodeMessage("Aedsau iaxf svsirfs.") << endl;



/*for(int i = 0; i<101;i++){
	int value;
	test1.dequeue(value);
	cout << value << " ";
    }*/

test1.enqueue(1);
test1.enqueue(15);
test1.enqueue(23);
test1.enqueue(4);

for(int i = 0; i<4;i++){
	int value;
	test1.dequeue(value);
	cout << value << " ";
    }

}


int main(){

test();
cout << "Project3.cpp" << endl;
}
