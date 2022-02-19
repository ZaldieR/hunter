/*
** EPITECH PROJECT, 2020
** move_ducks
** File description:
** move_ducks
*/

#include <SFML/Graphics.h>
#include <ducks.h>
#include <game.h>

void move_ducks(duck_t *ducks, util_t *util)
{
    sfVector2f place = sfSprite_getPosition(ducks[0].sprite);

    for (int i = 0; i < NB_DUCKS; i++) {
        move_rect(&ducks[i].rect, 110, 330);
        sfSprite_move(ducks[i].sprite, ducks[i].movement);
        sfSprite_setTextureRect(ducks[i].sprite, ducks[i].rect);
        place = sfSprite_getPosition(ducks[i].sprite);
        if (place.x >= 830) {
            init_duck(i, util->textures, ducks);
            sfSound_play(util->sounds[0]);
            util->nb_lives = util->nb_lives + 1;
            if (util->nb_lives > 3)
                util->game_mode = 2;
            else if (util->nb_lives > 0) {
                sfSprite_setTexture(util->lives[util->nb_lives - 1],
                util->textures[3], sfTrue);
            }
        }
    }
}

void move_background(sfSprite **const_sprites)
{
    sfVector2f move = set_vector(-1, 0);

    if (sfSprite_getPosition(const_sprites[1]).x <= -1001)
        sfSprite_setPosition(const_sprites[1], move);
    sfSprite_move(const_sprites[1], move);
}

void death_anim(duck_t *ducks, util_t *util, int i)
{
    sfClock *clock = sfClock_create();
    sfTime time;
    float secs;

    while (1) {
        time = sfClock_getElapsedTime(clock);
        secs = time.microseconds / 1000000.0;
        if (secs >= 0.1) {
            init_duck(i, util->textures, ducks);
            return;
        }
    }
}

void verif_ducks(duck_t *ducks, int mouse_x, int mouse_y,
util_t *util)
{
    sfVector2f duck;
    sfTexture *dead = sfTexture_createFromFile("assets/Die.png", NULL);

    for (int i = 0; i < NB_DUCKS; i++) {
        duck = sfSprite_getPosition(ducks[i].sprite);
        if (mouse_x >= duck.x && mouse_x <= duck.x + 55 &&
            mouse_y >= duck.y && mouse_y <= duck.y + 55) {
            util->score = util->score + ducks[i].points;
            sfSprite_setTexture(ducks[i].sprite, dead, sfTrue);
            draw_scene(util, ducks);
            sfSound_play(util->sounds[2]);
            death_anim(ducks, util, i);
        }
    }
}