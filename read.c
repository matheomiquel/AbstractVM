#include "lib.h"
#include <string.h>

my_pile_t function[] = {
    {"push", push},
    {"pop", pop},
    {"add", add},
    {"sub", sub},
    {"mul", mul},
    {"div", division},
    {"mod", mod},
    {"assert", assert},
    {"dump", dump},
    {"print", print},
    {"\0", NULL},
};

int read_file(head_t head, int fd)
{
    int semicolone = 0;
    char buf[1];
    char func[7] = "";
    int index = 0;
    int retour = 0;
    int i = 0;

    while(read(fd, buf, 1)) {
        if (semicolone == 0) 
            if (before_semicolone(&semicolone ,buf, func, index, retour, i,  head, fd) != 0)
                return 1;
    }
    my_putstr("Il manque un exit à la fin du fichier");
    return (1);
}

int size_elements()
{
    int i = 0;

    while(my_strcmp(function[i].str, "\0"))
        i++;
    return (i);
}

void read_until_enter(int fd)
{
    char buf[1] = "";

    while(buf[0] != 10)
        if(read(fd, buf, 1))
            break;
}

int before_semicolone(int *semicolone , char buf[1], char func[7], int index, int retour,int i, head_t head, int fd)
{
    if (index == 6)
        return (1);
    semicolone = buf[0] == ';' ? 0 : semicolone; 
    if (buf[0] != 32 || buf[0] != 10) 
        my_strcat(func, buf);  
    else {
        if(my_strcmp(func, "exit") == 0)
        return (0);
        for(i = 0;my_strcmp(function[i].str, "\0") != 0 ;i++) 
            if(my_strcmp(function[i].str, func) == 0)
                retour = function[i].fn(head, fd);
        if (retour != 0 || i >= size_elements())
            return 1;
        for(i = 0; i < my_strlen(func); i++)
            func[i] = 0;
        semicolone = 0;
        index = 0;
    }
    index++;
    return (0);
}