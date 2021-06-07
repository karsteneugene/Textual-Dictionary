#include <iostream>
#include <string>
#include <string.h>
#include <unistd.h>
#include "queueDict.h"

using namespace std;

int main(void)
{
	dict dictionary;
	string w, definition, choice;
	
	while(true) 
	{
		cout<<"Choose: \n 1. Insert \n 2. Remove \n 3. Display \n 4. Update \n 5. Search \n 6. Exit \n\nOption: ";
		getline(cin, choice);
		cout<<endl;
		
		if(choice == "1") 
		{
			cout<<"Word: ";
			getline(cin, w);

			cout<<"Definition: ";
			getline(cin, definition);
			
			dictionary.insert(w, definition);
			cout<<endl;
			system("CLS");
		}
		
		else if (choice == "2")
		{
			if (dictionary.empty())
			{
				cout << "Queue is empty" << endl;
				sleep(2);
			}
			else
			{
				dictionary.remove();
			}
			system("CLS");
		}
		
		else if (choice == "3") 
		{
			string cont;
			
			if (dictionary.empty())
			{
				cout << "Queue is empty" << endl;
				sleep(2);
			}
			else
			{	
				while(cont!="c")
				{
					dictionary.display();
					cout<<"Would you like to continue(c): ";
					getline(cin, cont);	
				}
			}
			system("CLS");
		}
		
		else if (choice == "4")
		{
			if (dictionary.empty())
			{
				cout << "Queue is empty" << endl;
				sleep(2);
			}
			else
			{
				cout<<"Word: ";
				getline(cin, w);
				dictionary.update(w);
				cout<<endl;
			}
			system("CLS");
		}
		
		else if (choice == "5") 
		{
			string cont;
			
			if (dictionary.empty())
			{
				cout << "Queue is empty" << endl;
				sleep(2);
			}
			else
			{
			
				cout<<"Word: ";
				getline(cin, w);
				
				while(cont != "c")
				{
					dictionary.search(w);
					cout<<"Would you like to continue(c): ";
					getline(cin, cont);
					cout<<endl;
					
				}
			}
			system("CLS");
		}
		else if (choice == "6")
		{
			return false;
		}
		
	}
}
