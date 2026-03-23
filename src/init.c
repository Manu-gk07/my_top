/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** init
*/

#include "../include/my.h"

void reset_task(info_t *info)
{
    info->total_tasks = 0;
    info->running = 0;
    info->sleeping = 0;
    info->sleeping = 0;
    info->zombie = 0;
}

static void init_struct(info_t *info)
{
    info->flags->delay = 3000;
    info->flags->flag_d = false;
    info->flags->flag_n = false;
    info->flags->flag_u = false;
    info->flags->nb_frames = 1000000;
    info->total_tasks = 0;
    info->running = 0;
    info->sleeping = 0;
    info->sleeping = 0;
    info->zombie = 0;
    info->unit = 'M';
    info->unit_index = 1;
}

static void init_cpu_struct(info_t *info)
{
    *info->cpu_old = (cpu_stats_t){0, 0, 0, 0, 0, 0, 0, 0, 0};
    *info->cpu_new = (cpu_stats_t){0, 0, 0, 0, 0, 0, 0, 0, 0};
    *info->cpu_total = (cpu_stats_total_t){0, 0, 0, 0, 0, 0, 0, 0, 0};
    *info->mem_info = (mib_mem_t){0, 0, 0, 0};
    *info->mem_swap = (mib_swap_t){0, 0, 0};
}

void init_all(int ac, char **av, info_t *info)
{
    init_struct(info);
    init_cpu_struct(info);
    parse_aguments(ac, av, info);
    initscr();
    noecho();
    curs_set(0);
    timeout(info->flags->delay);
}
