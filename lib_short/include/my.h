/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h
*/

#ifndef __MY_H__
#define __MY_H__

void my_putchar(char c);
void my_putstr(char *str);
int my_strlen(char *str);
void my_put_nbr(int nb);
int my_atoi(char *str);
char *my_unatoi(int nb);
int my_strcmp(char *str1, char *str2);
char *my_strdup(char *str);
char *my_memset(char *str, char c, int size);
void my_printf(char *str, ...);
void *my_malloc(int size);
char *load_file(char *filepath);
char *my_add_to_str(char *str, char *add, int nb);

#endif