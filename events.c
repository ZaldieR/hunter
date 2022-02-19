/*
** EPITECH PROJECT, 2020
** events
** File description:
** events
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <ducks.h>
#include <game.h>

void verif_restart(duck_t *ducks, int mouse_x, int mouse_y, util_t *util)
{
    if (mouse_x >= 290 && mouse_x <= 490 && mouse_y >= 270 && mouse_y <= 347) {
        for (int i = 0; i < NB_DUCKS; i++)
            init_duck(i, util->textures, ducks);
        make_util(1, util);
    }
}

void verif_game_mode(util_t *util, duck_t *ducks, int mouse_x, int mouse_y)
{
    if (util->game_mode == 1)
        verif_ducks(ducks, mouse_x, mouse_y, util);
    else if (util->game_mode == 2)
        verif_restart(ducks, mouse_x, mouse_y, util);
}

int analyse_events(sfRenderWindow **window, sfEvent event,
util_t *util, duck_t *ducks)
{
    int mouse_x = 0;
    int mouse_y = 0;

    while (sfRenderWindow_pollEvent(*window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(*window);
            return (84);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            sfSound_play(util->sounds[1]);
            mouse_x = event.mouseButton.x;
            mouse_y = event.mouseButton.y;
            verif_game_mode(util, ducks, mouse_x, mouse_y);
        }
    }
    return (0);
}