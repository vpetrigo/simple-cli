/*
 * cli_func.c
 *
 *  Created on: 27.01.2017
 *      Author: vladimir.petrigo
 */

#include "cli_func.h"
#include "cli_help.h"

const CLI_Func_t cli_functions[] = {{"help", cli_help, "print help message"},
                                    {NULL, NULL, NULL}};
