#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int get_length(string);

int main(){
	string filename;
	cout << "Please enter a file name" << endl;
	cin >> filename;
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
	string currentLine;
	input_file >> currentLine;
	cout<<currentLine<<endl;
	cin>> command;
	while(command != "Q"){
		if(command ="L"){
			int length;
			length =  get_length(currentLine);
			cout<<"Length is: "<<length<<endl;
			cout<<currentLine<<endl;
		}
		if(command ="P"){
			cout<<"You entered P"<<endl;
		}
		if(command ="I"){
		
		}
		if(command ="D"){
		}
		if(command ="R"){
		}
		if(command ="N"){
		}
		cin.clear();
		cin>> command;
	}
	return 0;
}


int get_length(string currentline){
	return currentline.length();

}

int get_pos(string str, string currentline){
	return currentline.find(str);

}

string insert(int pos, string str, string currentline){
	return currentline.insert(pos, str);
}

string delete_characters(int pos, int numChar, string currentline){
	return currentline.erase(pos, numChar);

}

string replace(string currentline, string toBeReplaced){
	string replacement;
	cout << "With what? ";
	cin >> replacement;
	int pos = get_pos(toBeReplaced, currentline);
	int length = get_length(toBeReplaced);
	return currentline.replace(pos, length, replacement);
}

string nextline (int currentline, string nextline){
	
	string nextline = getline(filename, currerntline++);
	
}




















