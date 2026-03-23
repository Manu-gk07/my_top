/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** parse_flags
*/

#include "../include/my.h"
#include <string.h>

void parse_aguments(int ac, char **av, info_t *info)
{
    for (int i = 1; i < ac && av[i + 1] != NULL; i++) {
        if (strcmp(av[i], "-d") == 0) {
            info->flags->flag_d = true;
            info->flags->delay = atof(av[i + 1]) * 1000;
        }
        if (strcmp(av[i], "-U") == 0) {
            info->flags->flag_u = true;
            info->flags->user = strdup(av[i + 1]);
        }
        if (strcmp(av[i], "-n") == 0) {
            info->flags->flag_n = true;
            info->flags->nb_frames = atoi(av[i + 1]);
        }
    }
}
