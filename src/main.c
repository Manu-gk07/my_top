/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** main
*/

#include "../include/my.h"
#include <ncurses.h>


static void flag_h()
{
    printf("My_Top is a project that consists of recreating the Unix top");
    printf("command.It displays real-time system information such as CPU");
    printf("usage, memory usage, and running processes, using C ");
    printf("programming and system process management.\n");
}

static info_t *init_info(void)
{
    info_t *info;

    info = malloc(sizeof(info_t));
    info->flags = malloc(sizeof(flags_t));
    info->cpu_old = malloc(sizeof(cpu_stats_t));
    info->cpu_new = malloc(sizeof(cpu_stats_t));
    info->cpu_total = malloc(sizeof(cpu_stats_total_t));
    info->mem_info = malloc(sizeof(mib_mem_t));
    info->mem_swap = malloc(sizeof(mib_swap_t));
    info->count_unit = 0;
    return info;
}

static void handle_input(info_t *info, char ch)
{
    if (ch == 'q')
        endwin();
    if (ch == 'h') {
        endwin();
        flag_h();
    }
    if (ch == 'E') {
        info->count_unit++;
        get_unit(info);
    }
}

static void loop_body(info_t *info)
{
    clear();
    reset_task(info);
    get_uptime(info);
    get_loadavg(info);
    get_tasks(info);
    get_mem(info);
    calcul_mem(info);
    *info->cpu_old = *info->cpu_new;
    fill_cpu_struct_one(info->cpu_new);
    get_total_cpu(info);
    display_everyhing(info);
    refresh();
}

int main(int ac, char **av)
{
    info_t *info;
    int count;
    char ch;

    info = init_info();
    init_all(ac, av, info);
    fill_cpu_struct_one(info->cpu_old);
    count = 0;
    while (count < info->flags->nb_frames) {
        loop_body(info);
        ch = getch();
        handle_input(info, ch);
        if (ch == 'q')
            break;
        if (ch == 'h')
            break;
        count++;
    }
    endwin();
    return 0;
}
