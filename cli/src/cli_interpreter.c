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
static inline bool cmp_command_names(const char *line,
                                     const uint16_t *const index,
                                     const char *cmd);

uint8_t cli_interpreter(const char *line, size_t size, uint16_t *cmd,
                        size_t *cmd_len)
{
  if (line == NULL || size == 0 || cmd == NULL || cmd_len == NULL) {
    return BAD_REQUEST;
  }

  command_parser(line, size, cmd, cmd_len);

  if (*cmd_len > 0) {
    const CLI_Func_t *ptr = cli_functions;

    while (ptr->cli_handler != NULL) {
      if (cmp_command_names(line, cmd, ptr->func_name)) {
        ptr->cli_handler(0, NULL);

        break;
      }

      ++ptr;
    }

    if (ptr->cli_handler == NULL) {
      // TODO: print message that command is not appropriate
      cli_functions->cli_handler(0, NULL);
    }
  }

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

static inline bool cmp_command_names(const char *line,
                                     const uint16_t *const index,
                                     const char *cmd)
{
  const char *cmd_line_start = line + *index;
  const char *cmd_line_end = line + *(index + 1);

  while (cmd_line_start != cmd_line_end && *cmd &&
         *cmd_line_start++ == *cmd++) {
  }

  if (cmd_line_start == cmd_line_end && *cmd == '\0') {
    return true;
  }

  return false;
}
