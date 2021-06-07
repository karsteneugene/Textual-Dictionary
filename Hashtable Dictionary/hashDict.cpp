#include <iostream>
#include <map>
#include <unistd.h>

using namespace std;


int main() 
{
	//Declares the variables for dictionary and it
	map<string, string> dictionary;
	map<string, string>::iterator it ;
	
	//Declares the variables of w for word, definition and choice as a string type
	string w, definition, choice;
	
	
	
	//Main loop for displaying the options and dictionary 
	while(true) 
	{
		cout<<"Choose: \n 1. Insert \n 2. Delete \n 3. Display \n 4. Update \n 5. Search \n 6. Exit \n\nOption: ";
		getline(cin, choice);
		cout<<endl;
		
		//Inputing word and its corresponding defintion into the dictionary 
		if(choice == "1") 
		{
			
			// Gets the word from the command line
			cout<<"Word: ";
			getline(cin, w);
	
			// Gets the definition from the command line
			cout<<"Definition: ";
			getline(cin, definition);
			
			
			//Checks if the word exists within the dictionary if not insert the word
			if (dictionary.find(w) == dictionary.end()) {
				dictionary.insert(pair<string, string>(w, definition));
				cout<<endl;
			}
			else {
				cout << "Word already exists within the hashtable" << endl;
				sleep(2); 
			}
			system("CLS");
			
		}
		
		//Allows the deletion of a specified word and its definition within the dictionary
		else if(choice == "2") 
		{			
		
			//Checks if the dictionary is empty so deletion process is exited 
			if(dictionary.empty()) {
				cout<<"Dictionary is empty"<<endl;
				sleep(2);
			}
			else 
			//Deletes a specified word within the dictionary 
			{
				// Gets the word from the command line
				cout<<"Word: ";
				getline(cin, w);
				
				//Finds the word in the dictionary
				it = dictionary.find(w);
				
				//If the word is not found the following message is given
				if(it == dictionary.end()) {
	        		cout << "Key-value pair not present in map" ;
	        		sleep(2);
				}
				else 
				//Erases the word from the dictionary
				{
					dictionary.erase(w);
				}
			}
			system("CLS");
			
		}
		
		//Displays the words and definitions within the dictionary 
		else if (choice == "3") 
		{
			//Declares the cont variable with  
			string cont;
			
			//Checks if the dictionary is empty 
			if (dictionary.empty())
			{
				cout << "Dictionary is empty" << endl;
				sleep(2);
			}
			else
			{
		    	for (auto i = dictionary.begin(); i != dictionary.end(); i++) 
				{
					//(*i).first dereferences the word within the dictionary
		        	cout << (*i).first<< " : "<< (*i).second;
					cout<<endl;
	    		}
	    		//Returns to the main display screen
	    		while(cont!="c")
				{
					cout<<"Would you like to continue(c): ";
					getline(cin, cont);	
				}
    		}
    		system("CLS");
		}
		
		//Changes the definition of a word within the dictionary
		else if (choice == "4") 
		{
			//Checks if the dictionary is empty 	
			if (dictionary.empty())
			{
				cout << "Dictionary is empty" << endl;
				sleep(2);
			}
			else
			{
				//Requests for the word that need to be updated
				cout<<"Word: ";
				getline(cin, w);
				
				
				//Iterates through the dictionary 
				for (auto i = dictionary.begin(); i != dictionary.end(); i++) 
				{
					//(*i).first dereferences the word within the dictionary
					if((*i).first == w)
					//If the word is found request for the new definition
					 {
						cout<<"Enter the new definition for "<<w<<": ";
						getline(cin, definition);
						
						//Changes the definition of the word
						dictionary[w] = definition;
					}			
	    		}
	    		
	    		//Checks if the word doesn;t exist
				if(it == dictionary.end()) {
				  	cout << "Key-value pair not present in map" << endl;
				  	sleep(2);
				}	
			}
			system("CLS");
		}
		
		//Searches for a specific word within the dictionary
		else if (choice == "5") 
		{
			//Declares the cont variable with  
			string cont;
			
			//Checks if the dictionary is empty 	
			if (dictionary.empty())
			{
				cout << "Dictionary is empty" << endl;
				sleep(2);
			}
			else
			{
				//Requests for the word that need to be searched
				cout<<"Word: ";
				getline(cin, w);
				it = dictionary.find(w);
			
				if (it == dictionary.end())
				{
		        	cout << "Key-value pair not present in map" << endl;
		        	sleep(2);
		    	}
		    	else
		    	{
		    		//(*it).first dereferences the word within the dictionary
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

