/*
 * deamon_dir.hpp
 *
 *  Created on: Mar 27, 2018
 *      Author: so
 */

#ifndef DEAMON_DIR_HPP_
#define DEAMON_DIR_HPP_

#include <string>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <list>
#include <iostream>

namespace deamon{

	class directory_exception : public std::exception{
	private:
		std::string _dirname;
		int _err_no;

	public:
		std::string get_dirname(){
			return _dirname;
		}

		directory_exception(std::string dirname, int err_no){
			_dirname = dirname;
			_err_no = err_no;
		}
	};

	class directory_not_found_exception : public directory_exception{ };



	class directory{
	private:
		std::string _dirname;
		DIR* dir_handle;

	public:
		std::list<std::string> get_file_list(){
			std::list<std::string> __file_list;
			
			struct dirent* __file;
			DIR* __dir;
			char __temp[100];
			if(__dir=opendir(_dirname.c_str()))
    		{
				while(__file=readdir(__dir))
				{
					//printf(file->d_name);
			    	strcpy(__temp, _dirname.c_str());
			    	strcat(__temp, __file->d_name);
			    	////ShowDate(pom);
				}
			}
   		 	else
        		throw(1);
			return __file_list;
		}




		directory(std::string dirname){
			_dirname = dirname;
			dir_handle = opendir(_dirname.c_str());
			/*if(!(dir_handle = opendir(_dirname.c_str()))){
				throw(1);
			}*/
		}

		~directory(){
			closedir(dir_handle);
		}
	};
}




#endif /* DEAMON_DIR_HPP_ */

////////
