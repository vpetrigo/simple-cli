/*
 * cli_interpreter.h
 *
 *  Created on: 27.01.2017
 *      Author: vladimir.petrigo
 */

#ifndef CLI_INC_CLI_INTERPRETER_H_
#define CLI_INC_CLI_INTERPRETER_H_

#include <stddef.h>
#include <stdint.h>

typedef enum { BAD_REQUEST = 0, COMMAND_PARSED = 1 } CLI_Return_t;

uint8_t cli_interpreter(const char *line, size_t size, uint16_t *cmd,
                        size_t *cmd_len);

#endif /* CLI_INC_CLI_INTERPRETER_H_ */
