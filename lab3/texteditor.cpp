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
	return 0;
	// testing comment
}
