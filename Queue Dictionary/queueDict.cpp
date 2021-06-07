#include <iostream>
#include <string>
#include <string.h>
#include <unistd.h>
#include "queueDict.h"

using namespace std;

dict::dict() {
	front = NULL;
	rear = NULL;
}

void dict::insert(string word, string def)
{
	bool input = true;
	
	Node *temp = new Node();
	Node *checker = rear;
	(*temp).word = word; 
	
	(*temp).def = def; 	
	
	(*temp).next = NULL;
	
	if(front==NULL && rear== NULL) 		
	{ 
		front = rear = temp;
	}
	else
	{
		while (checker != NULL)	
		{
				
			if ((*checker).word == word)
			{
				cout << "The word already exists in the queue" << endl;
				input = false;
				sleep(2);
				break;
			}
			else
			{
				checker = (*checker).next;
			}
			
		}
		if (input)
		{
			(*temp).next = rear; 
			rear = temp;
		}
		else
		{
			return;
		}
			
	}
}

void dict::remove()	
{
	Node* temp = rear;
	
	if (front==NULL)
	{
		cout << "Queue is empty" << endl;
		sleep(2);
	}
	else if (front==rear)
	{
		front = NULL;
		rear = NULL;
	}
	else
	{
		while(temp->next != front)
		{
			temp = temp->next;
		}
		delete front;
		temp->next = NULL;
		front = temp;
	}
}

void dict::update(string word)
{
	Node* temp = rear;
	string curword = (*temp).word;
	string curdef;

	while(curword != word)
	{
		temp = (*temp).next;
		if (temp == NULL)
		{
			cout << "Word does not exist, within the dictionary" << endl;
			sleep(2);
			return;
		}
		else
		{
			curword = (*temp).word;
		}
	}
	cout<<"Enter the definition for "<<curword<<": ";
	getline(cin, curdef);
	(*temp).def = curdef;
	return;
}

void dict::search(string word)
{
	Node* searchingNode = rear;
	string curword = (*searchingNode).word;
	
	while(curword != word)
	{
		if((*searchingNode).next == NULL)
		{
			cout<<"\nWord does not exist, within the dictionary"<<endl;
			return;
		}
		else
		{
			searchingNode = (*searchingNode).next;
			curword = (*searchingNode).word;
		}
	}
	cout<<"Definition of word searched: "<<endl;
	cout<<(*searchingNode).word<<": "<<(*searchingNode).def<<endl;
	return;
}

void dict::display()
{
	Node* dis = new Node();
	dis = rear;
	
	while(dis != NULL)
	{
		cout<<(*dis).word<<": "<<(*dis).def<<endl;
		dis = (*dis).next;
	}
}

bool dict::empty()
{
	if (front==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

