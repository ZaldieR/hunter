/*
** EPITECH PROJECT, 2020
** game
** File description:
** game
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <graphics.h>
#include <game.h>
#include <ducks.h>
#include <my.h>

void init_duck(int i, sfTexture **textures, duck_t *ducks)
{
    int r_x = rand() % 1000 - 1100;
    int r_y = rand() % 400;
    int s_x = rand() % 10 + 12;
    int s_y = rand() % 5 - 3;
    double scale = rand() % 4 + 8;
    sfVector2f scale_r;

    scale_r.x = scale / 10 - 0.5;
    scale_r.y = scale / 10 - 0.5;
    if (r_x <= 100)
        s_y = rand() % 2;
    else if (r_x >= 400)
        s_y = rand() % 3 - 5;
    ducks[i].sprite = make_sprite(textures[rand() % 7 + 5]);
    ducks[i].init_position = set_vector(r_x, r_y);
    ducks[i].movement = set_vector(s_x, s_y);
    ducks[i].rect = def_rect(0, (rand() % 3 + 1) * 110, 110, 110);
    ducks[i].points = rand() % 100;
    sfSprite_setScale(ducks[i].sprite, scale_r);
    sfSprite_setTextureRect(ducks[i].sprite, ducks[i].rect);
    sfSprite_setPosition(ducks[i].sprite, ducks[i].init_position);
}

void deal_time(float secs, util_t *util, duck_t *ducks)
{
    util->str = my_unatoi(util->score);
    sfText_setString(util->text, my_add_to_str("Score: ", util->str,
    my_strlen(util->str)));
    util->time = sfClock_getElapsedTime(util->clock);
    secs = util->time.microseconds / 1000000.0;
    if (secs >= 0.1) {
        move_background(util->const_sprites);
        if (util->game_mode == 1)
            move_ducks(ducks, util);
        sfClock_restart(util->clock);
    }
    draw_scene(util, ducks);
}

void game_start(util_t *util)
{
    duck_t ducks[NB_DUCKS];

    for (int i = 0; i < NB_DUCKS; i++)
        init_duck(i, util->textures, ducks);
    draw_scene(util, ducks);
    sfRenderWindow_setFramerateLimit(util->window, 60);
    while (sfRenderWindow_isOpen(util->window)) {
        if (analyse_events(&util->window, util->event, util, ducks) == 84)
            return;
        deal_time(0, util, ducks);
    }
    sfRenderWindow_destroy(util->window);
}