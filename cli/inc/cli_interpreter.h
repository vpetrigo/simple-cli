/*
 * cli_interpreter.h
 *
 *  Created on: 27.01.2017
 *      Author: vladimir.petrigo
 */

#ifndef CLI_INC_CLI_INTERPRETER_H_
#define CLI_INC_CLI_INTERPRETER_H_

#include "cli_func.h"

#include <stddef.h>
#include <stdint.h>

/**
 * \typedef Parser return values representation
 */
typedef enum { BAD_REQUEST = 0, COMMAND_PARSED = 1 } CLI_Return_t;

/**
 * \brief CLI interpreter that process an input string for occurence of command 
 * and its arguments
 * \param[in] line String with command and with/without its aruments
 * \param[in] size Size of **line**
 * \param[out] cmd Buffer to store command's arguments start/end indexes in a **line**
 * \param[out] cmd_len How much arguments have been got from **line**
 */
uint8_t cli_interpreter(const char *line, size_t size, uint16_t *cmd,
                        size_t *cmd_len);

#endif /* CLI_INC_CLI_INTERPRETER_H_ */
