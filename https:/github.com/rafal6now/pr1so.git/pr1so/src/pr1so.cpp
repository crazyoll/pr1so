//============================================================================
// Name        : pr1so.cpp
// Author      : 1
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
*/
#include <iostream>

int main() {
	std::cout << "!!!Hello World!!! xD xD xD" << std::endl; // prints !!!Hello World!!!
	std::cout << "xD" << std::endl;
	return 0;
}
*/

//aktualnie dzialanie jest nastepujace
//podajesz sciezke wzgedna np. u mnie 
// C:\sasasa\
//i wypluwa zawartosc folderu wraz z data ostaniej modyfikacji

#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
//mysle zeby dane przechowywac w liscie struktur
/*typedef struct Lista
{
        struct tm *czas;
        char nazwa[];
};
Lista l1;*/
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
/*gowno z wiki
void dodaj_do_listy (Lista *lista, unsigned long liczba)
 {
   el_listy *wsk, *nowy;
   wsk = lista;
   while (wsk->next != NULL)
     { 
     wsk = wsk->next;
     }
   nowy = malloc (sizeof(el_listy));
   nowy->val = liczba;
   nowy->next = NULL;
   wsk->next = nowy;
 }*/
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
