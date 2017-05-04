INC += 

LIB += -lz -lm -lrt -lpthread

C_FLAGS = -fno-strict-aliasing -Wno-strict-aliasing -g -Wall -Wunused-variable -Wno-literal-suffix -O2 -std=c++11 
.PHONY: all clean

BINARY = $(patsubst %.cpp,%,$(wildcard *.cpp))

all:$(BINARY)

RED = \\e[1m\\e[31m
RESET = \\e[m
GREEN = \\e[1m\\e[32m

clean:
	@rm -rf ${BINARY}
	@echo "make clean done."

%:%.cpp
	@echo -e "Make $(GREEN)$@$(RESET) begin......\c"
	$(CXX) $(INC) $< -o $@ $(C_FLAGS) ${LIB} 
	@echo -e $(RED)"ok."$(RESET)
