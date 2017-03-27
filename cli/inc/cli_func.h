/*
 * cli_func.h
 * Author: vladimir.petrigo
 */

#ifndef CLI_INC_CLI_FUNC_H_
#define CLI_INC_CLI_FUNC_H_

#include <stdint.h>

/**
 * \typedef cli_handler_ptr
 * \brief Declaration of CLI handler function prototype
 * \param[in] argc Number of parameters
 * \param[in] buf Null-terminated strings that keeps command with parameters
 * \param[in] argv_index Array of start/end parameter indexes
 *
 * \code
 *   // indexes             |0 ...     |11..16| ...  |25..32|
 *   //                     v          v             v      v 
 *   const char *command = "useful_cmd param1 param2 parammm3";
 *   // after parsing @command
 *   const uint16_t command_index[] = [11, 17, 18, 24, 25, 33];
 *   // call appropriate handler
 *   command_handler(3, command, command_index);
 * \endcode
 */
typedef void (*cli_handler_ptr)(uint8_t argc, const char *buf,
                                const uint16_t *argv_index);

/**
 * \typedef CLI_Func_t
 * \brief CLI support data structure for storing command handler, command name and description
 */
typedef struct {
  /// command name. ex. "help"
  const char *func_name;
  /// command handler
  const cli_handler_ptr cli_handler;
  /// command description
  const char *func_description;
} CLI_Func_t;

/**
 * Table with a list of supported CLI
 */
extern const CLI_Func_t cli_functions[];

#endif /* CLI_INC_CLI_FUNC_H_ */
