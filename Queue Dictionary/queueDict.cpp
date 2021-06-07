#include <iostream>
#include <string>
#include <string.h>
#include <unistd.h>
#include "queueDict.h"

using namespace std;


//Creating the constructor for the dict class
dict::dict() {
	//Making the private Node pointers NULL
	front = NULL;
	rear = NULL;
}


//Method to enqueue a new word and its definition to the queue 
void dict::insert(string word, string def)
{
	//Checks if word is qualified to be enqued within the dictionary 
	bool input = true;
	
	
	//Creating a temporary pointer to a new Node
	Node *temp = new Node();
	
	//Making a checker to iterate through the queue to see if the word already exists 
	Node *checker = rear;
	
	//Puting the arguments passed into the method into the temporary Node 
	(*temp).word = word; 
	
	(*temp).def = def; 	
	
	//Set the temps's next variable to NULL
	(*temp).next = NULL;
	
	
	
	//If the queue is empty make the front and rear get temp
	if(front==NULL && rear== NULL) 		
	{ 
		front = rear = temp;
	}
	else
	{
		//Checks if the word already exists within the queue
		while (checker != NULL)	
		{
				
			if ((*checker).word == word)
			{
				//If the word exists within the queue set the input to false 
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
		
		
		//If input is true, temp's next points to the current rear and rear will get temp
		if (input)
		{
			(*temp).next = rear; 
			rear = temp;
		}
	}
}

//Dequeue's the current front 
void dict::remove()	
{
	//Instantiate a temp that gains rear
	Node* temp = rear;
	
	
	//Checks if front is empty 
	if (front==NULL)
	{
		cout << "Queue is empty" << endl;
		sleep(2);
	}
	//Checks if the dictionary has only a single word 
	else if (front==rear)
	{
		front = NULL;
		rear = NULL;
	}
	else
	{
		//Iterates through the temp until it's next Node points to the front Node
		while(temp->next != front)
		{
			temp = temp->next;
		}
		//Delete the current front
		delete front;
		
		//Set the temp's next Node pointer to NULL and repalce the front with temp
		temp->next = NULL;
		front = temp;
	}
}

//Updates a definition of a specified word 
void dict::update(string word)
{
	//Instantiate a temp that gains rear
	Node* temp = rear;
	
	//Gets the current word that the temp Node is currently on, and declare the curdef variable
	string curword = (*temp).word;
	string curdef;


	//Checks through the queue until the word is found or does not exist within the dictionary
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
	//If the word is found ask for its new definition and return to the main display
	cout<<"Enter the definition for "<<curword<<": ";
	getline(cin, curdef);
	(*temp).def = curdef;
	return;
}


//Searches for a word and its corresponding definition
void dict::search(string word)
{
	//Instantiate a searchingNode that gains rear and take the word contained in rear
	Node* searchingNode = rear;
	string curword = (*searchingNode).word;
	
	//Iterates through the queue until the word is either found or not within the queue
	while(curword != word)
	{
		//If the queue is reaches its end
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
	//If the word is found get its word and definition
	cout<<"Definition of word searched: "<<endl;
	cout<<(*searchingNode).word<<": "<<(*searchingNode).def<<endl;
	return;
}

//Shows all the words within the dictionary
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

//Checks if the queue is empty
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

