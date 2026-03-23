/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <string.h>
    #include <unistd.h>
    #include <termios.h>
    #include <ncurses.h>
    #include <time.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <dirent.h>

static const char unit_char[] = {'K', 'M', 'G', 'T', 'P', 'E'};
static const double unit_div[] = {1024.0, 1024.0 * 1024.0, 1024.0 * 1024.0 *
    1024.0, 1024.0 * 1024.0 * 1024.0 * 1024.0, 1024.0 * 1024.0 * 1024.0 *
    1024.0 * 1024.0, 1024.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0};

typedef struct mib_swap_s {
    double swap_total;
    double swap_free;
    double swap_used;
} mib_swap_t;

typedef struct mib_mem_s {
    double mem_total;
    double free;
    double used;
    double buff;
    double cache;
    double sreclaim;
    double buff_cache;
} mib_mem_t;

typedef struct cpu_stats_s {
    unsigned long user;
    unsigned long nice;
    unsigned long system;
    unsigned long idle;
    unsigned long iowait;
    unsigned long irq;
    unsigned long softirq;
    unsigned long steal;
    unsigned long total;
} cpu_stats_t;

typedef struct cpu_stats_total_s {
    float user;
    float nice;
    float system;
    float idle;
    float iowait;
    float irq;
    float softirq;
    float steal;
    float total;
} cpu_stats_total_t;

typedef struct flags_s {
    bool flag_u;
    bool flag_n;
    bool flag_d;
    double delay;
    int nb_frames;
    char *user;
} flags_t;

typedef struct info_s {
    long uptime;
    double load[3];
    flags_t *flags;
    int total_tasks;
    int sleeping;
    int zombie;
    int stopped;
    int running;
    cpu_stats_t *cpu_old;
    cpu_stats_t *cpu_new;
    cpu_stats_total_t *cpu_total;
    mib_mem_t *mem_info;
    mib_swap_t *mem_swap;
    char unit;
    int count_unit;
    int unit_index;
} info_t;

void get_uptime(info_t *info);
void get_loadavg(info_t *info);
void parse_aguments(int ac, char **av, info_t *info);
void get_tasks(info_t *info);


void fill_cpu_struct_one(cpu_stats_t *cpu_struct);
void display_everyhing(info_t *info);
void init_all(int ac, char **av, info_t *info);
void reset_task(info_t *info);
void get_mem(info_t *info);
void get_total_cpu(info_t *info);
void calcul_mem(info_t *info);
void get_unit(info_t *info);

#endif
