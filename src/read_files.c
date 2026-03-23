/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** read_files
*/

#include "../include/my.h"
#include <stddef.h>

void get_uptime(info_t *info) {
  FILE *file = fopen("/proc/uptime", "r");
  double uptime;

  if (!file)
    return;
  fscanf(file, "%lf", &uptime);
  info->uptime = (long)uptime;
  fclose(file);
}

void get_loadavg(info_t *info) {
  FILE *file = fopen("/proc/loadavg", "r");

  if (!file)
    return;
  fscanf(file, "%lf %lf %lf", &info->load[0], &info->load[1], &info->load[2]);
  fclose(file);
}

static void get_status(char *path, info_t *info) {
  FILE *file = fopen(path, "r");
  char state;

  if (!file)
    return;
  fscanf(file, "%*d %*s %c", &state);
  if (state == 'R')
    info->running++;
  if (state == 'S' || state == 'D')
    info->sleeping++;
  if (state == 'T')
    info->stopped++;
  if (state == 'Z')
    info->zombie++;
  fclose(file);
}

void get_tasks(info_t *info) {
  DIR *dir = opendir("/proc");
  struct dirent *entry;
  char path[512];

  if (dir == NULL)
    return;
  entry = readdir(dir);
  while (entry != NULL) {
    if (atoi(entry->d_name) > 0) {
      info->total_tasks++;
      snprintf(path, sizeof(path), "/proc/%s/stat", entry->d_name);
      get_status(path, info);
    }
    entry = readdir(dir);
  }
  closedir(dir);
}

void fill_cpu_struct_one(cpu_stats_t *cpu_struct) {
  FILE *file = fopen("/proc/stat", "r");
  char line[256];

  if (file == NULL)
    return;
  if (fgets(line, sizeof(line), file)) {
    sscanf(line, "cpu  %lu %lu %lu %lu %lu %lu %lu %lu", &cpu_struct->user,
           &cpu_struct->nice, &cpu_struct->system, &cpu_struct->idle,
           &cpu_struct->iowait, &cpu_struct->irq, &cpu_struct->softirq,
           &cpu_struct->steal);
  }
  cpu_struct->total = cpu_struct->user + cpu_struct->nice + cpu_struct->system +
                      cpu_struct->idle + cpu_struct->iowait + cpu_struct->irq +
                      cpu_struct->softirq + cpu_struct->steal;
  fclose(file);
}

static void parse_mem_line(info_t *info, char *line) {
  if (!strncmp(line, "MemTotal:", 9))
    sscanf(line, "MemTotal: %lf", &info->mem_info->mem_total);
  if (!strncmp(line, "MemFree:", 8))
    sscanf(line, "MemFree: %lf", &info->mem_info->free);
  if (!strncmp(line, "Buffers:", 8))
    sscanf(line, "Buffers: %lf", &info->mem_info->buff);
  if (!strncmp(line, "Cached:", 7))
    sscanf(line, "Cached: %lf", &info->mem_info->cache);
  if (!strncmp(line, "SReclaimable:", 13))
    sscanf(line, "SReclaimable: %lf", &info->mem_info->sreclaim);
  if (!strncmp(line, "SwapTotal:", 10))
    sscanf(line, "SwapTotal: %lf", &info->mem_swap->swap_total);
  if (!strncmp(line, "SwapFree:", 9))
    sscanf(line, "SwapFree: %lf", &info->mem_swap->swap_free);
}

void get_mem(info_t *info) {
  FILE *file;
  char *line;
  size_t len;

  file = fopen("/proc/meminfo", "r");
  if (!file)
    return;
  line = NULL;
  len = 0;
  while (getline(&line, &len, file) != -1)
    parse_mem_line(info, line);
  free(line);
  fclose(file);
}
