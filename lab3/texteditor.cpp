#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
string currentLine;


int get_length(string currentline){
	return currentline.length();

}

string insert(string str, string currentline){
	int pos;
	cout << "Insert where? ";
	cin >> pos;
	return currentline.insert(pos, str);
}

int get_pos(string str, string x){
	try{
		int i = x.find(str);
		return i;
	}
	catch(int e){
		cout<<"Invalid position"<<endl;
		return -1;
	}

}

string delete_characters(int pos, int numChar, string currentline){
	return currentline.erase(pos, numChar);

}

string replace(string currentline, string toBeReplaced){
	string replacement;
	cout << "With what? ";
	cin >> replacement;
	int pos = get_pos(toBeReplaced, currentline);
	if(pos == -1){
		cout<<"That was a invalid position."<<endl;
		return NULL;
	}
	int length = get_length(toBeReplaced);
	return currentline.replace(pos, length, replacement);
}
bool iexists(const string& filename){
	ifstream ifile(filename.c_str());
	return ifile;
}

int main(){
	string filename;
	cout << "Please enter a file name" << endl;
	cin >> filename;
	if(iexists(filename)){
		ifstream input_file;
		input_file.open(filename.c_str(), ios::in);
		cin.ignore();
		// append .out to input file name to create output file name
		filename.append(".out");
		ofstream output_file (filename.c_str());
		cout << "The Editing commands are:"<< endl;
		cout << "L :Determine the length of the current line"<<endl;
		cout << "P str :Find the position (from 0) of the string str"<<endl;
		cout<<"I str :Insert string str"<<endl;
		cout<<"D p n :Delete n characters beginning at position p"<<endl;
		cout<<"R str :Replace substring str with another string"<<endl;
		cout<<"N :Get the next line of text"<<endl;
		cout<<"Q :quit editing"<<endl;
		cout<<endl<<"Enter an editing command following each prompt >"<<endl;
		cin.clear();
		string command;
		getline(input_file,currentLine);
		cout<<currentLine<<endl;
		getline(cin,command);
		//cout<<command<<endl;
		while(command != "Q"){
			if(command == "L"){
				int length;
				length =  get_length(currentLine);
				cout<<"Length is: "<<length<<endl;
				cout<<currentLine<<endl;
			}
			else if(command[0] == 'P'){
				int space = get_pos(" ", command);
				if(space != -1){
					space++;
					string str = command.substr(space,get_length(command));
					cout<<"Position is: "<<get_pos(str, currentLine)<<endl;
				}
			}
			else if(command[0] == 'I'){
				int space = get_pos(" ", command);
				if(space != -1){
					space++;
					string str = command.substr(space,get_length(command));
					currentLine=insert(str, currentLine);
					cout<<currentLine<<endl;	
				}
			}
			else if(command[0] == 'D'){
				int space = get_pos(" ", command);	
				if(space != -1){
						space++;
						string posString = command.substr(space,get_length(command));
						space = get_pos(" ", posString);	
						space++;
						string startString = posString.substr(0,space-1);
						int pos = atoi(startString.c_str());
						string numCharacters = posString.substr(space,get_length(posString));
						int characters = atoi(numCharacters.c_str());
						currentLine = delete_characters(pos, characters, currentLine);
						cout<<currentLine<<endl;
						}
						}
						else if(command[0] == 'R'){
						int space = get_pos(" ", command);	
						if(space != -1){
						space++;
						string posString = command.substr(space,get_length(command));
						currentLine = replace(currentLine, posString);
						cout<<currentLine<<endl;
						}
						}
			else if(command == "N"){
				output_file<<currentLine<<endl;
				getline(input_file,currentLine);
				cout<<"Next Line: " << currentLine<<endl;
				if(input_file.eof()){
					cout << "*** Editing Complete ***" << endl;
				}
			}		
			cin.clear();
			getline(cin,command);
		}
	}
	else{
		cout<<"Filename you entered does not exist."<<endl;
	}
	return 0;
}
