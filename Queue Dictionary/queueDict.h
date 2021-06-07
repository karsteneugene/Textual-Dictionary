#include <iostream>
#include <string>
#include <string.h>

using namespace std;

//Node contains the word and its definition including a pointer to the following Node
struct Node 
{
	string word;
	string def;
	Node *next;
};

//Making the methods and the variables a dict object should have
class dict 
{
	
	//Due to queue having the requirement of enqueing elements from the rear and dequeing from the front private Node pointers are declared
	private:
		struct Node *front;
		struct Node *rear;
	public:
		dict();
		void insert(string word, string def);
		void remove();
		void update(string word);
		void search(string word);
		void display();
		bool empty();
};
