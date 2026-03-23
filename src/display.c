/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** display
*/

#include "../include/my.h"

static void print_swap(info_t *info)
{
    double div = unit_div[info->unit_index];

    printw("%ciB Swap:   %.01f total,    %.01f free,    %0.1f used,    "
        "%.01f avail Mem\n",
        info->unit, info->mem_swap->swap_total / div,
        info->mem_swap->swap_free / div, info->mem_swap->swap_used / div,
        info->mem_swap->swap_free / div);
}

static void print_mem(info_t *info)
{
    double div = unit_div[info->unit_index];

    printw("%ciB Mem :  %.01f total,   %.01f free,   %.01f used,"
        "%.01f buff/cache\n", info->unit, info->mem_info->mem_total /
        div, info->mem_info->free / div, info->mem_info->used / div,
        info->mem_info->buff_cache / div);
}

static void print_uptime(int d, int h, int min)
{
    if (d > 0)
        printw("%d day%s,", d, (d > 1) ? "s" : "");
    if (h > 0)
        printw("%d:%02d", h, min);
    else
        printw("%d min", min);
}

static void print_user(info_t *info)
{
    printw(", 0 user,");
}

static void print_loadavg(info_t *info)
{
    printw(" load average: %.2lf, %.2lf, %.2lf\n", info->load[0],
        info->load[1], info->load[2]);
}

void print_tasks(info_t *info)
{
    printw("Tasks: %d total,   %d runnig, %d sleeping,   %d stopped,%d"
        "zombie\n", info->total_tasks, info->running, info->sleeping,
        info->stopped, info->zombie);
}

void print_cpu(info_t *info)
{
    printw("%%Cpu(s):  %3.1f us,  %3.1f sy,  %3.1f ni,  %3.1f"
        "id,  %3.1f wa,  %3.1f hi,  %3.1f si,  %3.1f st\n",
        info->cpu_total->user, info->cpu_total->system, info->cpu_total->nice,
        info->cpu_total->idle, info->cpu_total->iowait, info->cpu_total->irq,
        info->cpu_total->softirq, info->cpu_total->steal);
}

void display_everyhing(info_t *info)
{
    time_t now = time(NULL);
    struct tm *time = localtime(&now);
    int d = info->uptime / 86400;
    int h = (info->uptime % 86400) / 3600;
    int min = (info->uptime % 3600) / 60;

    mvprintw(0, 0, "top - %02d:%02d:%02d up ", time->tm_hour,
        time->tm_min, time->tm_sec);
    print_uptime(d, h, min);
    print_user(info);
    print_loadavg(info);
    print_tasks(info);
    print_cpu(info);
    print_mem(info);
    print_swap(info);
}
