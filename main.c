/*
** EPITECH PROJECT, 2020
** bshunter
** File description:
** bshunter
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <graphics.h>
#include <game.h>

int main(int argc, char **argv)
{
    sfTime time;
    sfClock *clock = sfClock_create();
    float secs;

    if (argc >= 2)
        return (print_h(argc, argv[1]));
    time = sfClock_getElapsedTime(clock);
    secs = time.microseconds;
    srand(secs);
    start_menu();
    return (0);
}