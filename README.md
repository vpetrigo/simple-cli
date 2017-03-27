# simple-cli
Simple command line interface implementation that requires only one array for storing start/end indexes
of command/arguments and one variable to store arguments number.

### Example

```c
// cli_func.c
#include "cli_func.h"
#include "cli_help.h"
#include "cli_print.h"

const CLI_Func_t cli_functions[] = {{"help", cli_help, "print help message"},
                                    {"print", cli_print, "print arguments that were passed"}
                                    {NULL, NULL, NULL}};
                                    
// main.c

int main() 
{
  const char line[] = " print 1 2 3";
  // maximum number of indexes that might be stored
  const size_t cmd_indexes_size = 8;
  // buffer for storing start/end indexes of a command/arguments
  uint16_t cmd_indexes[cmd_indexes_size];
  // number of arguments
  size_t cmd_len = 0;
  // run CLI interpreter on @line string
  // it also execute cli_print() function with arguments "1", "2", "3"
  cli_interpreter(line, strlen(line), cmd_indexes, &cmd_len);
  // show how much arguments were parsed. Expected: 4 ("print" + "1" + "2" + "3")
  printf("command with args size: %" PRIu64 "\n", cmd_len);
  
  // debug output that shows parsed tokens
  for (size_t i = 0; i < cmd_len * 2; i += 2) {
    printf("CMD start: %d, end: %d\n", cmd_indexes[i], cmd_indexes[i + 1]);

    for (size_t j = cmd_indexes[i]; j < cmd_indexes[i + 1]; ++j) {
      putchar(line[j]);
    }

    putchar('\n');
  }

  return 0;
}
```
