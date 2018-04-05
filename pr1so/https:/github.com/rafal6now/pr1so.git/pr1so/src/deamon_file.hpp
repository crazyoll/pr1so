/*
 * deamon_file.hpp
 *
 *  Created on: Mar 26, 2018
 *      Author: so
 */

#ifndef DEAMON_FILE_HPP_
#define DEAMON_FILE_HPP_

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <errno.h>

#include <string>

namespace deamon{

	class file_exception : public std::exception{
	private:
		std::string _filename;

	public:
		file_exception(std::string filename){
			_filename = filename;
		}

		std::string get_filename(){
			return _filename;
		}
	};

	class file_not_found_exception : public file_exception{

	};

	class file{
	private:
		int file_handle = -1;
		unsigned char _mode;
		std::string _filename;

		void copy_under_4kB_to(std::string dirname){
			int __size = 4*1024*sizeof(char);
			char __bufor[__size];
			/*
    		int __file_source = open(_filename.c_str(), O_RDONLY);
			if(__file_source == -1)
				//throw(file_not_found_exception(_filename));
    		int __file_destination = open(dirname.c_str(), O_WRONLY);
			if(__file_destination == -1)
				//throw(file_not_found_exception(_filename));

    		while (read(__file_source, __bufor, __size)) {
        		write(__file_destination, __bufor, __size);
    		}

    		close(__file_source);
    		close(__file_destination);*/
		}

		void copy_over_4kB_to(std::string dirname){

		}

	public:
		file(std::string name, unsigned char mode){
			_filename = name;
			_mode = mode;
			file_handle = open(_filename.c_str(), mode);
			if(file_handle == -1);
				//throw(file_not_found_exception(_filename));
		}

		~file(){
			close(file_handle);
		}

		//int get_handle(){
		//	return file_handle;
		//}

		void copy_file(std::string dirname){

		}

		static int get_modification_date(std::string filename){
			struct stat __file;
			if(!stat(filename.c_str(), &__file))
			return
				__file.st_mtime;
		    else;
		    	//throw(file_not_found_exception(filename));
		}
	};




}

#endif /* DEAMON_FILE_HPP_ */
