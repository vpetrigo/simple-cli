/*
 * cli_func.h
 * Author: vladimir.petrigo
 */

#ifndef CLI_INC_CLI_FUNC_H_
#define CLI_INC_CLI_FUNC_H_

#include <stdint.h>

typedef void (*cli_handler_ptr)(uint8_t argc, const char *buf,
                                const uint16_t *argv_index);

typedef struct {
  const char *func_name;
  const cli_handler_ptr cli_handler;
  const char *func_description;
} CLI_Func_t;

extern const CLI_Func_t cli_functions[];

#endif /* CLI_INC_CLI_FUNC_H_ */
