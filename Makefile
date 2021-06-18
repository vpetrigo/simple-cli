.PHONY: all clean
TARGET = simple_command
BDIR = build
CCFLAGS = -Icli/inc
all: $(BDIR) $(BDIR)/$(TARGET)
clean:
	rm $(BDIR)/*.o $(BDIR)/$(TARGET)
$(BDIR):
	mkdir $(BDIR)
SDIR = cli/src cli/src/platform
VPATH = $(SDIR)
$(BDIR)/$(TARGET): $(BDIR)/cli_interpreter.o
$(BDIR)/$(TARGET): $(BDIR)/cli_help.o
$(BDIR)/$(TARGET): $(BDIR)/cli_func.o
$(BDIR)/$(TARGET): $(BDIR)/std_cli_utils.o
$(BDIR)/$(TARGET):
	$(CC) $(CCFLAGS) cli/examples/simple_command.c $(wildcard $(BDIR)/*.o) -o $(BDIR)/$(TARGET)
$(BDIR)/%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $(@)
