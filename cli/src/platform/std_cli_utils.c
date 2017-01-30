/*
 * cli_utils.c
 *
 *  Created on: 27.01.2017
 *      Author: vladimir.petrigo
 */

#include "cli_utils.h"
#include <stdio.h>

int cli_utils_print(const char *fmt, ...)
{
  va_list args;

  va_start(args, fmt);
  int n = vfprintf(stdout, fmt, args);
  va_end(args);

  return n;
}
