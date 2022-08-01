#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int my_stoi(string s){
	stringstream s_cp;
	s_cp << s;
	int val;
	s_cp >> val;
	return val;
}
// stoi: input a string and out a integer
int main(int argc, char * argv[]){
	string a(argv[1]);
//	printf("here is the arg: %s\n",a); 
	cout << "here is the arg: " << a << endl;
	return 0;
}
