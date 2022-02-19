/*
** EPITECH PROJECT, 2020
** make_util
** File description:
** make_util
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <graphics.h>
#include <game.h>
#include <ducks.h>
#include <my.h>

void make_util_const(util_t *util)
{
    util->clock = sfClock_create();
    util->score = 0;
    util->str = NULL;
    util->text = make_text("Score:", &util->score);
    util->fd = 0;
    util->filepath = "high_score.txt";
    util->high = my_atoi(load_file(util->filepath));
    util->high_score = make_text("High Score:", &util->high);
    util->nb_lives = 0;
    util->lives_pos = set_vector(600, 550);
    for (int i = 0; i < 3; i++) {
        util->lives[i] = sfSprite_create();
        sfSprite_setTexture(util->lives[i], util->textures[2], sfTrue);
        sfSprite_setPosition(util->lives[i], util->lives_pos);
    }
    util->game_mode = 1;
}

void make_util(int i, util_t *util)
{
    if (i == 0) {
        util->window = create_window(800, 600, "MyHunter", 32);
        set_textures(util->textures);
        set_const_sprites(util->const_sprites, util->textures);
        set_sound_buffer(util->sound_buffer);
        set_sounds(util->sound_buffer, util->sounds);
    }
    make_util_const(util);
}