#include <iostream>
#include <string>
#include <string.h>
#include <unistd.h>
#include "queueDict.h"

using namespace std;

int main(void)
{
	dict d;
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
			
			d.insert(w, definition);
			cout<<endl;
			system("CLS");
		}
		
		else if (choice == "2")
		{
			if (d.empty())
			{
				cout << "Queue is empty" << endl;
				sleep(2);
			}
			else
			{
				d.remove();
			}
			system("CLS");
		}
		
		else if (choice == "3") 
		{
			string cont;
			
			if (d.empty())
			{
				cout << "Queue is empty" << endl;
				sleep(2);
			}
			else
			{	
				while(cont!="c")
				{
					d.display();
					cout<<"Would you like to continue(c): ";
					getline(cin, cont);	
				}
			}
			system("CLS");
		}
		
		else if (choice == "4")
		{
			if (d.empty())
			{
				cout << "Queue is empty" << endl;
				sleep(2);
			}
			else
			{
				cout<<"Word: ";
				getline(cin, w);
				d.update(w);
				cout<<endl;
			}
			system("CLS");
		}
		
		else if (choice == "5") 
		{
			string cont;
			
			if (d.empty())
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
					d.search(w);
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
