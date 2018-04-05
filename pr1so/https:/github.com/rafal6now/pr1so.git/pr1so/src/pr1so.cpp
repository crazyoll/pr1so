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
#include "deamon_dir.hpp"
#include "deamon_file.hpp"

volatile time_t last_synchronization;
volatile time_t next_synchronization;





void copy_file(std::string source, std::string destination, int64_t size){

}

void synchronize_folders(std::string source, std::string destination){
	deamon::directory _dir1(source);
	deamon::directory _dir2(destination);
	_dir1.get_file_list();
	
	

}



void log_message(std::string message){

}

int main(int argc, char **argv) {
	/*
	std::list<std::string> _file_list;
	_file_list = _dir1.get_file_list();
	std::list<std::string>::iterator i;
    for(i = _file_list.begin(); i != _file_list.end(); i++)
    {
     	std::cout<<"XD";
        std::cout << *i << " ";
    }
    */
	synchronize_folders(argv[1], argv[2]);
	return 0;
}


/*
  	std::time_t time_now = time(NULL);
	std::tm * ptm = std::localtime(&time_now);
	char time_text[32];
	std::strftime(time_text, 32, "%Y-%m-%d %H:%M:%S", ptm);
	std::string msg = "Program started at " + std::string(time_text);
	std::cout << msg << std::endl;
<<<<<<< HEAD
 *

=======
	return 0;
}


//aktualnie dzialanie jest nastepujace
//podajesz sciezke wzgedna np. u mnie 
// C:\sasasa\
//i wypluwa zawartosc folderu wraz z data ostaniej modyfikacji

#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
void ShowDate(char name[])
{
     char t[100] ;
     struct stat file;
     if(!stat(name,&file))
     {
         strftime(t,100,"%d/%m/%Y %H:%M:%S",localtime(&file.st_mtime));
         printf("\nData ostatniej modyfikacji = %s\n\n",t);
         
     }
     else
         printf("Error\n");
}
void ShowFolder(const char* directory)
{
    struct dirent* file;
    DIR* dir;
    char pom[100];

    if((dir=opendir(directory)))
    {
        while((file=readdir(dir)))
        {
            printf(file->d_name);
            //bez podania pelnej sciezki nie chcialo dzialac
            //wiec lacze 2 tablice charow
            strcpy(pom,directory);
            strcat(pom,file->d_name);
            ShowDate(pom);
            
        }

        closedir(dir);
    }
    else
        printf("blad otwarcia strumienia dla danej sciezki\n",directory);
}
int main(int argc, char **argv)
{
    printf("podaj sciezke: ");
    char tab[100];
    scanf("%99s",tab);
    ShowFolder(tab);
    return 0;
}
>>>>>>> branch 'master' of https://github.com/rafal6now/pr1so.git*/
