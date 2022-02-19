/*
** EPITECH PROJECT, 2020
** strlen
** File description:
** strlen
*/

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i]; i++);
    return (i);
}