#include "lib.h"
int main(int argv, char **argc){
    int size = size_elements();
    int fd = check(argv, argc);
    head_t head;
    
    head.first = NULL;
    if (fd < 0) 
        return (1);
    if(read_file(head, fd) != 0)
        return (1);
    printf("%d%d\n", size, fd);
    return 0;
}

 /*int i;
    for (i = 0; arr[i].str != "bijour";i++)
         my_putstr("here\n");
        //if (arr[i].str == "bijour")
        //    arr[i].fn();
        printf("%d\n", size);*/