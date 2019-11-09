#include "lib.h"
int push(head_t head, int fd){
    data_t *data = malloc(sizeof(*data));
    char buf[1] = "";
    char *value = malloc(sizeof(char) * 10);
    int ouvrante = 0;

    while (1) {
        if(read(fd, buf, 1) == 0 || buf[0] == 10)
            return (1);
        else if (ouvrante != 0)
            my_strcat(value, buf);
        else if (buf[0] == '(')
            ouvrante = 1;
        else if(buf[0] == ')')
            break;
    }
    data->data = (void*)(size_t)my_getnbr(value);
    data->type = "int";
    if (head.first == NULL) {
        data->next = NULL;
    } else {
        data->next = head.first;
    }
    head.first = data;
    my_putnbr((int)2);
    return 0;
}

int pop(head_t head, int fd)
{
    char buf[1] = "";
    data_t *tmp = malloc(sizeof(*tmp));

    if (head.first == NULL) {
        free(tmp);
        return (1);
    }
    else if (head.first->next == NULL) {
        free(head.first);
        free(tmp);
        return (0);
    }
    tmp = head.first->next;
    free(head.first);
    head.first = tmp;
    while(buf[0] != 10)
        if(read(fd, buf, 1) == 0)
            return (1);
    return (0);
}

int assert(head_t head, int fd)
{
    char buf[1] = "";

    if (head.first == NULL)
        return (1);
    else if (head.first->data)
        return (1);
    while(buf[0] != 10)
        if(read(fd, buf, 1) == 0)
            return (1);
    return (0);
}

int print(head_t head, int fd)
{
    char buf[1] = "";

    if (head.first == NULL)
        return (1);
    else if (my_strcmp(head.first->type,"int8"))
        return (1);
    my_putchar((char)head.first->data);
    my_putchar(10);
    while(buf[0] != 10)
        if(read(fd, buf, 1) == 0)
            return (1);
    return (0);
}

int dump(head_t head, int fd)
{
    data_t *data = head.first;
    char buf[1] = "";

    while(data->next != NULL) {
        my_putnbr((int)data->data);
        my_putchar(10);
        data = data->next;
    }
    my_putnbr((int)data->data);
    my_putchar(10);
    while(buf[0] != 10)
        if(read(fd, buf, 1) == 0)
            return (1);
    return (0);
}