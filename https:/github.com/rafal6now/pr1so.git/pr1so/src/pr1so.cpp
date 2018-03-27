//============================================================================
//C++ version: 17
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include <cstdint>
#include <dirent.h>
#include <ctime>
#include <chrono>

volatile time_t last_synchronization;
volatile time_t next_synchronization;





void copy_file(std::string source, std::string destination, int64_t size){

}

void synchronize_folders(std::string source, std::string destination){

}



void log_message(std::string message){

}

int main(int argc, char **argv) {



	return 0;
}


/*
 * 	std::time_t time_now = time(NULL);
	std::tm * ptm = std::localtime(&time_now);
	char time_text[32];
	std::strftime(time_text, 32, "%Y-%m-%d %H:%M:%S", ptm);
	std::string msg = "Program started at " + std::string(time_text);
	std::cout << msg << std::endl;
 *
 */
