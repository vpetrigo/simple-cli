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

/**
 * \detail Prints help message with a list of all supported CLI functions
 * that currently stored in the **cli_functions** array
 */
void cli_help(uint8_t argc, const char *buf, const uint16_t *argv_indexes)
{
  cli_utils_print(help_msg);
  // traverse through all available functions and print "command + description"
  for (const CLI_Func_t *ptr = cli_functions; ptr->func_name != NULL; ++ptr) {
    cli_utils_print(" - %s\t-\t%s\n", ptr->func_name, ptr->func_description);
  }
}
