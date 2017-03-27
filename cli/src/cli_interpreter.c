/*
 * cli_interpreter.c
 *
 *  Created on: 27.01.2017
 *      Author: vladimir.petrigo
 */

#include "cli_interpreter.h"
#include "cli_utils.h"

#include <ctype.h>
#include <stdbool.h>
#include <string.h>

static void command_parser(const char *line, size_t size, uint16_t *cmd,
                           size_t *cmd_len);

// check whether @ch is LF or NULL character
static inline bool is_cmd_end(const char ch);
// compare a command name stored in @line with a list of supported
// CLI functions
static inline bool cmp_command_names(const char *line,
                                     const uint16_t *const index,
                                     const char *cmd);

uint8_t cli_interpreter(const char *line, size_t size, uint16_t *cmd,
                        size_t *cmd_len)
{
  // sanity check that input parameters might be processed
  if (line == NULL || size == 0 || cmd == NULL || cmd_len == NULL) {
    return BAD_REQUEST;
  }
  // parse @line string that might store a command with arguments
  command_parser(line, size, cmd, cmd_len);
  // if @line stores reasonable command, process it
  if (*cmd_len > 0) {
    const CLI_Func_t *ptr = cli_functions;
    // traverse through the supported commands table and
    // compare the supported functions' name with one from @line
    while (ptr->cli_handler != NULL) {
      if (cmp_command_names(line, cmd, ptr->func_name)) {
        ptr->cli_handler(*cmd_len, line, cmd);

        break;
      }

      ++ptr;
    }
    // met invalid command
    if (ptr->cli_handler == NULL) {
      cli_utils_print("Command is not supported\n");
      cli_functions->cli_handler(0, NULL, cmd);
    }
  }

  return COMMAND_PARSED;
}

static void command_parser(const char *line, size_t size, uint16_t *cmd,
                           size_t *cmd_len)
{
  uint16_t pos = 0;
  // skip leading whitespace characters
  while (pos < size && isspace(line[pos])) {
    ++pos;
  }

  bool is_first_ch = true;

  while (pos != size && !is_cmd_end(line[pos])) {
    // save position in an input line where
    // command started
    if (is_first_ch) {
      ++(*cmd_len);
      *cmd++ = pos;
      is_first_ch = false;
    }
    // space delimiter between command/arguments
    if (line[pos] == ' ') {
      // save end position of a command/argument in @cmd buffer
      *cmd++ = pos;
      is_first_ch = true;
      // skip intermediate whitespaces
      while (pos < size && line[pos] == ' ') {
        ++pos;
      }
    }
    else {
      // traverse through characters inside a command/argument
      ++pos;
    }
  }
  // reach the end of the @line
  *cmd++ = pos;
}

static inline bool is_cmd_end(const char ch)
{
  if (ch == '\n' || ch == '\0') {
    return true;
  }

  return false;
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
