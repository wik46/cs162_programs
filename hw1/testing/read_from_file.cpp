// This file is only used to test reading from a file based on
// 	the number of whitespaces.

#include <iostream>
#include <fstream>

int main(int argc, char* argv[]){
	
	std::ifstream file("spellbooks.txt");
	if(!file){
		std::cout << "Error" << std::endl;
	}

	std::string data_ar[100];	
	while(file){
		int i = 0;
		std::string data = "";
		getline(file, data);
		data_ar[i] = data;
		std::cout << data << " [end of line]"<< std::endl;
		i++;
	}
	
	std::cout << std::endl << std::endl;

	std::cout << data_ar[0] << std::endl;	
	
	return 0;
}
