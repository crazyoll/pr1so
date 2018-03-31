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
			std::list<std::string> file_list();

			struct dirent* file;
			DIR* dir;
			char pom[100];

			while((file=readdir(dir)))
			{
				printf(file->d_name);
			    strcpy(pom, _dirname.c_str());
			    strcat(pom,file->d_name);
			    ////ShowDate(pom);
			}
			return file_list;
		}




		directory(std::string dirname){
			_dirname = dirname;
			if(!(dir_handle = opendir(_dirname.c_str()))){
				throw(1);
			}
		}

		~directory(){
			closedir(dir_handle);
		}
	};
}




#endif /* DEAMON_DIR_HPP_ */

////////
