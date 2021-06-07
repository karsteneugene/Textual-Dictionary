#include <iostream>
#include <map>
#include <unistd.h>

using namespace std;


int main() 
{
	map<string, string> d;
	map<string, string>::iterator it ;
	string w, definition, choice;
	
	while(true) 
	{
		cout<<"Choose: \n 1. Insert \n 2. Delete \n 3. Display \n 4. Update \n 5. Search \n 6. Exit \n\nOption: ";
		getline(cin, choice);
		cout<<endl;
		
		if(choice == "1") 
		{
			cout<<"Word: ";
			getline(cin, w);
	
			cout<<"Definition: ";
			getline(cin, definition);
			
			if (d.find(w) == d.end()) {
				d.insert(pair<string, string>(w, definition));
				cout<<endl;
			}
			else {
				cout << "Word already exists within the hashtable" << endl;
				sleep(2); 
			}
			system("CLS");
			
		}
		else if(choice == "2") 
		{			
			if(d.empty()) {
				cout<<"Dictionary is empty"<<endl;
				sleep(2);
			}
			else {
				cout<<"Word: ";
				getline(cin, w);
				it = d.find(w);
				if(it == d.end()) {
	        		cout << "Key-value pair not present in map" ;
	        		sleep(2);
				}
				else {
					d.erase(w);
				}
			}
			system("CLS");
			
		}
		else if (choice == "3") 
		{
			string cont;
			if (d.empty())
			{
				cout << "Dictionary is empty" << endl;
				sleep(2);
			}
			else
			{
		    	for (auto i = d.begin(); i != d.end(); i++) 
				{
		        	cout << (*i).first<< " : "<< (*i).second;
					cout<<endl;
	    		}
	    		while(cont!="c")
				{
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
				cout << "Dictionary is empty" << endl;
				sleep(2);
			}
			else
			{
				cout<<"Word: ";
				getline(cin, w);
				it = d.find(w);
			
				for (auto i = d.begin(); i != d.end(); i++) 
				{
					if((*i).first == w) {
						cout<<"Enter the new definition for "<<w<<": ";
						getline(cin, definition);
						d[w] = definition;
					}			
	    		}
				if(it == d.end()) {
				  	cout << "Key-value pair not present in map" << endl;
				  	sleep(2);
				}	
			}
			system("CLS");
		}
		else if (choice == "5") 
		{
			string cont;
			if (d.empty())
			{
				cout << "Dictionary is empty" << endl;
				sleep(2);
			}
			else
			{
			
				cout<<"Word: ";
				getline(cin, w);
				it = d.find(w);
			
				if (it == d.end())
				{
		        	cout << "Key-value pair not present in map" << endl;
		        	sleep(2);
		    	}
		    	else
		    	{
		        	cout<< (*it).first << " : " << (*it).second << endl;
		        	while(cont != "c")
					{
						cout<<"Would you like to continue(c): ";
						getline(cin, cont);
						cout<<endl;
					}
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

