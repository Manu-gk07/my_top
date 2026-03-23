/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** calculs
*/

#include "../include/my.h"

static void fill_cpu_part1(info_t *info, long diff)
{
    info->cpu_total->user =
        (float)(info->cpu_new->user - info->cpu_old->user) * 100.0 / diff;
    info->cpu_total->nice =
        (float)(info->cpu_new->nice - info->cpu_old->nice) * 100.0 / diff;
    info->cpu_total->system =
        (float)(info->cpu_new->system - info->cpu_old->system) * 100.0 / diff;
    info->cpu_total->idle =
        (float)(info->cpu_new->idle - info->cpu_old->idle) * 100.0 / diff;
}

static void fill_cpu_part2(info_t *info, long diff)
{
    info->cpu_total->iowait =
        (float)(info->cpu_new->iowait - info->cpu_old->iowait) * 100.0 / diff;
    info->cpu_total->irq =
        (float)(info->cpu_new->irq - info->cpu_old->irq) * 100.0 / diff;
    info->cpu_total->softirq =
        (float)(info->cpu_new->softirq -
        info->cpu_old->softirq) * 100.0 / diff;
    info->cpu_total->steal =
        (float)(info->cpu_new->steal - info->cpu_old->steal) * 100.0 / diff;
}

void get_total_cpu(info_t *info)
{
    long diff_total;

    diff_total = info->cpu_new->total - info->cpu_old->total;
    if (diff_total <= 0)
        return;
    fill_cpu_part1(info, diff_total);
    fill_cpu_part2(info, diff_total);
    if (info->cpu_total->idle < 0)
        info->cpu_total->idle = 0;
}

void calcul_mem(info_t *info)
{
    info->mem_info->used = info->mem_info->mem_total - info->mem_info->free
        - info->mem_info->buff - info->mem_info->cache
        - info->mem_info->sreclaim;
    info->mem_info->buff_cache = info->mem_info->buff
        + info->mem_info->cache + info->mem_info->sreclaim;
    info->mem_swap->swap_used = info->mem_swap->swap_total
        - info->mem_swap->swap_free;
}

void get_unit(info_t *info)
{
    info->unit_index = info->count_unit % 6;
    info->unit = unit_char[info->unit_index];
}
