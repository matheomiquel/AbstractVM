#include "lib.h"

int add(head_t head , int fd)
{
    char buf[1] = "";
    data_t *data = malloc(sizeof(*data));

    if(check_pile(head) != 0)
        return (1);
    data->data = (void*)(size_t)((int)head.first->data + (int)head.first->next->data);
    data->type = head.first->type;
    data->next = head.first->next->next;
    free(head.first->next);
    free(head.first);
    head.first = data;
    while(buf[0] != 10)
        if(read(fd, buf, 1) == 0)
            return (1);
    return (0);
}

int sub(head_t head, int fd)
{
    char buf[1] = "";
    data_t *data = malloc(sizeof(*data));

    if(check_pile(head) != 0)
        return (1);
    data->data = (void*)(size_t)((int)head.first->data - (int)head.first->next->data);
    data->type = head.first->type;
    data->next = head.first->next->next;
    free(head.first->next);
    free(head.first);
    head.first = data;
    while(buf[0] != 10)
        if(read(fd, buf, 1) == 0)
            return (1);
    return (0);
}

int mul(head_t head, int fd)
{
    char buf[1] = "";
    data_t *data = malloc(sizeof(*data));

    if(check_pile(head) != 0)
        return (1);
    data->data = (void*)(size_t)((int)head.first->data * (int)head.first->next->data);
    data->type = head.first->type;
    data->next = head.first->next->next;
    free(head.first->next);
    free(head.first);
    head.first = data;
    while(buf[0] != 10)
        if(read(fd, buf, 1) == 0)
            return (1);
    return (0);
}

int division(head_t head, int fd)
{
    char buf[1] = "";
    data_t *data = malloc(sizeof(*data));

    if(check_pile(head) != 0)
        return (1);
    data->data = (void*)(size_t)((int)head.first->data * (int)head.first->next->data);
    data->type = head.first->type;
    data->next = head.first->next->next;
    free(head.first->next);
    free(head.first);
    head.first = data;
    while(buf[0] != 10)
        if(read(fd, buf, 1) == 0)
            return (1);
    return (0);
}

int mod(head_t head, int fd)
{
    char buf[1] = "";
    data_t *data = malloc(sizeof(*data));

    if(check_pile(head) != 0)
        return (1);
    if (head.first->next->data == 0)
        return (1);
    data->data = (void*)(size_t)((int)head.first->data * (int)head.first->next->data);
    data->type = head.first->type;
    data->next = head.first->next->next;
    free(head.first->next);
    free(head.first);
    head.first = data;
    while(buf[0] != 10)
        if(read(fd, buf, 1) == 0)
            return (1);
    return (0);
}