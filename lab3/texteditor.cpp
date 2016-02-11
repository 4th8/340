#include <iostream>
#include <fstream>
#include <string>


int main(){
	using namespace std;
	string filename;
	cin.ignore();
	cout << "Please enter a file name" << endl;
	cin >> filename;
	ifstream input_file (filename);
	cin.ignore();
	// append .out to input file name to create output file name
	filename.append(".out");
	ofstream output_file (filename);
	cout << "The Editing commands are:"<< endl;
	cout << "L :Determine the length of the current line"<<endl;
	cout << "P str :Find the position (from 0) of the string str"<<endl;
	cout<<"I str :Insert string str"<<endl;
	cout<<"D p n :Delete n characters beginning at position p"<<endl;
	cout<<"R str :Replace substring str with another string"<<endl;
	cout<<"N :Get the next line of text"<<endl;
	cout<<"Q :quit editing"<<endl;
	cout<<endl<<"Enter an editing command following each prompt >"<<endl;

	return 0;
	// testing comment
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
	int pos = getPos(toBeReplaced, currentline);
	int length =strlen(replacement);
	currentline.replace(pos, lenth, replacement);
}
