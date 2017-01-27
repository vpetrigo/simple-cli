/*
 * cli_interpreter.c
 *
 *  Created on: 27.01.2017
 *      Author: vladimir.petrigo
 */

#include "cli_interpreter.h"

#include <ctype.h>
#include <stdbool.h>
#include <string.h>

static void command_parser(const char *line, size_t size, uint16_t *cmd,
                           size_t *cmd_len);

static inline uint8_t is_cmd_end(const char ch);

uint8_t cli_interpreter(const char *line, size_t size, uint16_t *cmd,
                        size_t *cmd_len)
{
  if (line == NULL || size == 0 || cmd == NULL || cmd_len == NULL) {
    return BAD_REQUEST;
  }

  command_parser(line, size, cmd, cmd_len);

  return COMMAND_PARSED;
}

static void command_parser(const char *line, size_t size, uint16_t *cmd,
                           size_t *cmd_len)
{
  uint16_t pos = 0;

  while (pos < size && isspace(line[pos])) {
    ++pos;
  }

  bool is_first_ch = true;

  while (pos != size && !is_cmd_end(line[pos])) {
    // save position in a input line where
    // command started
    if (is_first_ch) {
      ++(*cmd_len);
      *cmd++ = pos;
      is_first_ch = false;
    }

    if (line[pos] == ' ') {
      *cmd++ = pos;
      is_first_ch = true;

      while (pos < size && line[pos] == ' ') {
        ++pos;
      }
    }
    else {
      ++pos;
    }
  }

  *cmd++ = pos;
}

static inline uint8_t is_cmd_end(const char ch)
{
  if (ch == '\n' || ch == '\0') {
    return 1;
  }

  return 0;
}
