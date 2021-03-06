/*
 * cli_utils.h
 *
 *  Created on: 27.01.2017
 *      Author: vladimir.petrigo
 */

#ifndef CLI_INC_CLI_UTILS_H_
#define CLI_INC_CLI_UTILS_H_

#include <stdarg.h>

/**
 * \brief Helper function that used for output CLI work results
 * \warning Platform dependent
 */
int cli_utils_print(const char *fmt, ...);

#endif /* CLI_INC_CLI_UTILS_H_ */
