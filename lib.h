/*
** ETNA PROJECT, 10/05/2019 by miquel_m
** octocat
** File description:
**      lib
*/
#ifndef MY_LIST_H_
#define MY_LIST_H_

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>


typedef struct data_s {
    void* data;
    char *type;
    struct data_s *next;
} data_t;

typedef struct head_s {
    data_t *first;
} head_t;

typedef struct my_pile_s{
    char *str;
    int (*fn)(head_t, int fd);
} my_pile_t;

typedef struct my_type_s{
    char *str;
    void (*fn)(double n);
} my_type_t;


void my_putchar(char c);
void my_putstr(char *str);
void my_putnbr(int n);
int my_strcmp(char *s1, char *s2);
int check(int argv, char **argc);
void my_putchar_a(void);
void my_putchar_b(int a);
int size_elements();
int push(head_t head, int fd);
int pop(head_t head, int fd);
int check_pile(head_t head);
int sub(head_t head, int fd);
int mul(head_t head, int fd);
int division(head_t head, int fd);
int mod(head_t head, int fd);
int add(head_t head, int fd);
int dump(head_t head, int fd);
int print(head_t head, int fd);
int assert(head_t head, int fd);
int read_file(head_t head, int fd);
char *my_strcat(char *dest,const char *src);
int my_strlen(const char *str);
int test(head_t head);
short char_to_short(char n);
int short_to_int(short n);
float int_to_float(int n);
double float_to_double(float n);
int my_getnbr(char *str);
int before_semicolone(int *semicolone , char buf[1], char func[7], int index, int retour,int i, head_t head, int fd);

#endif