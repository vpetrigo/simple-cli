/*
 * main.c
 * Author: vladimir.petrigo
 */

#include "cli_func.h"
#include "cli_help.h"
#include "cli_interpreter.h"
#include "cli_utils.h"

#include <inttypes.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  const char line[] = "    led 1\n         2       ";
  const size_t cmd_indexes_size = 8;
  uint16_t cmd_indexes[cmd_indexes_size];
  size_t cmd_len = 0;

  cli_interpreter(line, strlen(line), cmd_indexes, &cmd_len);
  printf("command with args size: %" PRIu64 "\n", cmd_len);

  for (size_t i = 0; i < cmd_len * 2; i += 2) {
    printf("CMD start: %d, end: %d\n", cmd_indexes[i], cmd_indexes[i + 1]);

    for (size_t j = cmd_indexes[i]; j < cmd_indexes[i + 1]; ++j) {
      putchar(line[j]);
    }

    putchar('\n');
  }

  return 0;
}
