# compiler to use
CC = gcc

# flags to pass compiler
CFLAGS = -ggdb3 -std=c11

# name for executable
EXE = main

# space-separated list of header files
HDRS = llist.h songlib.h

# space-separated list of source files
SRCS = main.c llist.c songlib.c

# automatically generated list of object files
OBJS = $(SRCS:.c=.o)


# default target
$(EXE): $(OBJS) $(HDRS) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# dependencies
$(OBJS): $(HDRS) Makefile

# housekeeping
clean:
	rm -f core $(EXE) *.o
	rm -rf obj

run:
	./$(EXE)



# Not working at this point. Maybe later. http://make.mad-scientist.net/papers/advanced-auto-dependency-generation/
# OBJDIR := obj
#
# DEPDIR := $(OBJDIR)/.deps
# DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d
#
# COMPILE.c = $(CC) $(DEPFLAGS) $(CFLAGS) $(TARGET_ARCH) -c
#
# $(OBJDIR)/%.o : %.c $(DEPDIR)/%.d | $(DEPDIR)
# 	$(COMPILE.c) $(OUTPUT_OPTION) $<
#
# $(DEPDIR): ; @mkdir -p $@
#
# DEPFILES := $(SRCS:%.c=$(DEPDIR)/%.d)
# $(DEPFILES):
# include $(wildcard $(DEPFILES))
