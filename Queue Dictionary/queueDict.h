#include <iostream>
#include <string>
#include <string.h>

using namespace std;

struct Node 
{
	string word;
	string def;
	Node *next;
};

class dict 
{
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
