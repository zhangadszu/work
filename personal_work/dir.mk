RED 		= \\e[1m\\e[31m
DARKRED 	= \\e[31m
GREEN 		= \\e[1m\\e[32m
DARKGREEN 	= \\e[32m
YELLOW 		= \\e[1m\\e[33m
DARKYELLOW 	= \\e[33m
BLUE 		= \\e[1m\\e[34m
DARKBLUE 	= \\e[34m
MAGENTA 	= \\e[1m\\e[35m
DARKMAGENTA = \\e[35m
CYAN 		= \\e[1m\\e[36m
DARKCYAN 	= \\e[36m
RESET  		= \\e[m

FILTER_OUT+=$(wildcard makefile*) $(wildcard Makefile*) tags

PWD=$(shell pwd)

ifndef ALL_DIRS
	ALL_DIRS=$(filter-out $(FILTER_OUT), $(wildcard *))
endif

.PHONY: all clean $(ALL_DIRS)
all: $(ALL_DIRS)

clean: $(ALL_DIRS)

$(ALL_DIRS): 
	@echo -e "$(BLUE)$(MAKE) -C $(PWD)/$@ $(MAKECMDGOALS)$(RESET)"
	@if [ -f $@/makefile ] || [ -f $@/Makefile ] ; \
	then \
		$(MAKE) -C $@ $(MAKECMDGOALS) ; \
		fi
