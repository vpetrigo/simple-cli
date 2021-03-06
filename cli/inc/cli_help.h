/*
 * cli_help.h
 *
 *  Created on: 27.01.2017
 *      Author: vladimir.petrigo
 */

#ifndef CLI_INC_CLI_HELP_H_
#define CLI_INC_CLI_HELP_H_

#include <stdint.h>

/**
 * \brief Help command handler
 * \sa cli_handler_ptr
 */
void cli_help(uint8_t argc, const char *buf, const uint16_t *argv_index);

#endif /* CLI_INC_CLI_HELP_H_ */
