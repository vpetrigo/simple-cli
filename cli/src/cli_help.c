/*
 * cli_help.c
 *
 *  Created on: 27.01.2017
 *      Author: vladimir.petrigo
 */

#include "cli_help.h"
#include "cli_func.h"
#include "cli_utils.h"

#include <stddef.h>

static const char help_msg[] = {
    "CLI v0.0\n"
    "Commands:\n"};

void cli_help(uint8_t argc, const char *buf, const uint16_t *argv_indexes)
{
  cli_utils_print(help_msg);

  for (const CLI_Func_t *ptr = cli_functions; ptr->func_name != NULL; ++ptr) {
    cli_utils_print(" - %s\t-\t%s\n", ptr->func_name, ptr->func_description);
  }
}
