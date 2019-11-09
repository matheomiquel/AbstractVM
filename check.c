#include "lib.h"

int check(int argv, char **argc){
    int fd;
    
    if (argv < 2) {
        my_putstr("vous devez mettre le chemin du fichier !!!\n");
        return -1;
    }
    if ((fd = open(argc[1], O_RDONLY)) < 0) {
        my_putstr("Le fichier n'a pas été trouver\n");
        return -1;
    }
    return fd;
}

int check_pile(head_t head){
    if (head.first == NULL)
        return (1);
    else if (head.first->next == NULL)
        return (1);
    else if (!my_strcmp(head.first->type, head.first->next->type))
        return (1);
    return (0);
}