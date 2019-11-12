#include "lib.h"
int main(int argv, char **argc){
    int fd = check(argv, argc);
    head_t head;
    
    head.first = NULL;
    if (fd < 0) 
        return (1);
    if(read_file(head, fd) != 0)
        return (1);
    return 0;
}