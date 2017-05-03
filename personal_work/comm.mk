# 编译环境需要配置OMEGA_PATH指向工程目录，主干为trunk
# 需要使用ycm配置，配置YCM_CONF的值为1
include $(WORK_TEST_BASE)/makefile.inc

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

PWD = $(shell pwd)

ifndef CC
	CC = gcc
endif

ifndef CXX
	CXX = g++
endif

ifndef SRC_DIR
	SRC_DIR = ./src
endif

FILTER_OUT = $(foreach v,$(2),$(if $(findstring $(1),$(v)),,$(v)))

SUB_SRC_DIR = $(shell if [ -d $(SRC_DIR) ]; then find $(SRC_DIR) -type d; fi)
SUB_SRC_DIR := $(call FILTER_OUT,/bak,$(SUB_SRC_DIR))

ifndef OBJ_DIR
	OBJ_DIR = ./obj
endif

ifndef INC_DIR
	INC_DIR = ./include
endif

ifndef LIB_DIR
	LIB_DIR = ./lib
endif

ifndef GTEST_DIR
	GTEST_DIR = ./gtest
endif

ifndef OBJ_EXT
	OBJ_EXT = .o
endif

ifndef CXXSRC_EXT
	CXXSRC_EXT = .cpp
endif

ifndef CSRC_EXT
	CSRC_EXT = .c
endif

ifndef DEPEND_EXT
	DEPEND_EXT = .d
endif

ifndef LIB_EXT
	LIB_EXT = .a
endif

ifndef PREPROCESS_EXT
	PREPROCESS_EXT = .i
endif

ifndef LIB_PREFIX
	LIB_PREFIX = lib
endif

ifndef LIB_NAME
	LIB_NAME = $(LIB_PREFIX)$(shell basename $(PWD))$(LIB_EXT)
endif

TARGET = $(LIB_DIR)/$(LIB_NAME)
TARGET_SUFFIX = $(suffix $(TARGET))

ifeq ($(TARGET_SUFFIX),.a)
	TARGET_TYPE = a
else
	ifeq ($(TARGET_SUFFIX),.so)
		TARGET_TYPE = so
		LIB_EXT := .so
	else
		TARGET_TYPE = bin
		LIB_EXT := 
	endif
endif


ifndef CXX_SOURCES
	CXX_SOURCES = $(wildcard $(addsuffix /*$(CXXSRC_EXT), $(SUB_SRC_DIR)))
endif

CXX_OBJS =$(patsubst $(SRC_DIR)/%$(CXXSRC_EXT),$(OBJ_DIR)/%$(OBJ_EXT),$(CXX_SOURCES))

PREPROCESS_OBJS =$(patsubst $(SRC_DIR)/%$(CXXSRC_EXT),$(OBJ_DIR)/%$(PREPROCESS_EXT),$(CXX_SOURCES))

CXX_DEPENDS =$(patsubst $(SRC_DIR)/%$(CXXSRC_EXT),$(OBJ_DIR)/%$(DEPEND_EXT),$(CXX_SOURCES))

ifndef C_SOURCES
	C_SOURCES = $(wildcard $(SRC_DIR)/*$(CSRC_EXT))
endif

ifndef GTEST_NAME
	GTEST_NAME = $(shell basename $(PWD))_test
endif

GTEST_TARGET = $(LIB_DIR)/$(GTEST_NAME)

ifndef GTEST_SOURCES
	GTEST_SOURCES = $(wildcard $(GTEST_DIR)/*$(CXXSRC_EXT))
endif

GTEST_OBJS = $(patsubst $(GTEST_DIR)/%$(CXXSRC_EXT),$(OBJ_DIR)/%$(OBJ_EXT),$(GTEST_SOURCES))
GTEST_DEPENDS = $(patsubst $(GTEST_DIR)/%$(CXXSRC_EXT),$(OBJ_DIR)/%$(DEPEND_EXT),$(GTEST_SOURCES))

C_OBJS = $(patsubst $(SRC_DIR)/%$(CSRC_EXT),$(OBJ_DIR)/%$(OBJ_EXT),$(C_SOURCES))

C_DEPENDS = $(patsubst $(SRC_DIR)/%$(CSRC_EXT),$(OBJ_DIR)/%$(DEPEND_EXT),$(C_SOURCES))
SO_SEARCH_PATH=-Wl,-rpath,$(PATH_PLIB_OUTERLIB)/spp/lib -Wl,-rpath,/usr/local/services/spp_omega_ugc-2.3/bin/lib -Wl,-rpath,/usr/local/services/omega_tools/lib

ifeq ($(ARCH),32)
	CFLAGS += -m32 -march=pentium4
	LIB_DIR = ./lib32
endif

GTEST_FLAGS +=-g -Wall -Wunused-variable -Wno-literal-suffix -O2 -std=c++11 -msse -msse2 -msse3 -msse4.1 -pipe -fno-ident -D_GNU_SOURCE -D_REENTRANT  -Wno-conversion-null 

CFLAGS  += -g -Wall -Wunused-variable -Wno-literal-suffix -O2 -std=c++11 -msse -msse2 -msse3 -msse4.1 -pipe -fno-ident -D_GNU_SOURCE -D_REENTRANT  -Wno-conversion-null -fPIC -shared -fno-strict-aliasing -Wno-strict-aliasing -static-libgcc 

RUNABLE_FLAGS = -g -Wall -Wunused-variable -Wno-literal-suffix -O2 -std=c++11 -msse -msse2 -msse3 -msse4.1 -pipe -fno-ident -D_GNU_SOURCE -D_REENTRANT -Wno-conversion-null $(SO_SEARCH_PATH) -static-libgcc -static-libstdc++

CXXFLAGS+=$(CFLAGS) -fno-strict-aliasing -Wno-strict-aliasing -static-libstdc++ -Werror

INC += -I$(INC_DIR)

ALL += $(TARGET)
CLEAN += cleanobj

INC_GTEST_FLAG += $(INC_GTEST)
INC_GTEST_FLAG += $(INC_SPP)
LIB_GTEST_FLAG += $(LIB_GTEST)
LIB_GTEST_FLAG += $(LIB_SPP)

ifeq "$(YCM_CONF)" "1"
ALL+=.ycm_extra_conf.py
endif

# $1->compiler
# $2->INC
# $2->flags
define preprocess_obj
	@echo -e "$(YELLOW)Preprocess $< ==> $@$(RESET)"
	$(1) $(2) $(3) -E $< > $@
endef

# $1->compiler
# $2->INC
# $2->flags
define compile_obj
	@echo -e "$(YELLOW)Compiling $< ==> $@$(RESET)"
	$(1) $(2) $(3) -c $< -o $@
	@echo ""
endef

# $1->compiler
# $2->INC
# $2->flags
define compile_depend
	@echo -e "$(DARKYELLOW)Generating dependency $< ==> $@$(RESET)"
	@-mkdir -p $(@D); \
		$(1) $(2) $(3) -MM -MMD $< -o $@; \
		sed -i 's,\($*\$(OBJ_EXT)\)[ :]*,$(@D)/\1 $@ : ,g' $@
endef

# $1->compiler
# $2->flags
# $3->LIB
define compile_bin
	@echo -e "$(GREEN)Building $^ ==> $@$(RESET)"
	@echo -e "$(1) -o $@ $^ $(2) $(3)"
	@$(1) -o $@ $^ $(2) $(3); \
		$(PATH_PROJ_ROOT)/tools/check_symbol.sh $@
endef


.PHONY: all all32 cleanobj clean test gtest
all: $(ALL)

clean: $(CLEAN)

test:
	@echo $(CXX_OBJS)
	@echo $(TARGET)

all32:
	make all -e ARCH=32

gtest: $(GTEST_TARGET)

ifeq ($(TARGET_TYPE),a)
$(TARGET): $(CXX_OBJS) $(C_OBJS) | $(LIB_DIR)
	@echo -e "$(GREEN)"
	$(AR) rc $@ $(CXX_OBJS) $(C_OBJS)
	@echo -e "$(RESET)"
else
ifeq ($(TARGET_TYPE),so)
$(TARGET): $(CXX_OBJS) $(C_OBJS) | $(LIB_DIR)
	$(call compile_bin,$(CXX),$(CXXFLAGS),$(LIB))
else
$(TARGET): $(CXX_OBJS) $(C_OBJS) | $(LIB_DIR)
	$(call compile_bin,$(CXX),$(RUNABLE_FLAGS),$(LIB))
endif
endif

$(PREPROCESS_OBJS): $(OBJ_DIR)/%$(PREPROCESS_EXT): $(SRC_DIR)/%$(CXXSRC_EXT) | $(OBJ_DIR)
	$(call preprocess_obj,$(CXX),$(INC),$(CXXFLAGS))

$(CXX_OBJS): $(OBJ_DIR)/%$(OBJ_EXT): $(SRC_DIR)/%$(CXXSRC_EXT) $(OBJ_DIR)/%$(DEPEND_EXT) | $(OBJ_DIR)
	$(call compile_obj,$(CXX),$(INC),$(CXXFLAGS))

$(CXX_DEPENDS): $(OBJ_DIR)/%$(DEPEND_EXT): $(SRC_DIR)/%$(CXXSRC_EXT) | $(OBJ_DIR)
	$(call compile_depend,$(CXX),$(INC),$(CXXFLAGS))

$(C_OBJS): $(OBJ_DIR)/%$(OBJ_EXT): $(SRC_DIR)/%$(CSRC_EXT) $(OBJ_DIR)/%$(DEPEND_EXT) | $(OBJ_DIR)
	$(call compile_obj,$(CC),$(INC),$(CFLAGS))

$(C_DEPENDS): $(OBJ_DIR)/%$(DEPEND_EXT): $(SRC_DIR)/%$(CSRC_EXT) | $(OBJ_DIR)
	$(call compile_depend,$(CC),$(INC),$(CXXFLAGS))


ifeq ($(MAKECMDGOALS),gtest)
	CXX_OBJS:=$(filter-out ./obj/server.o obj/server.o,$(CXX_OBJS))
endif


$(GTEST_TARGET): $(GTEST_OBJS) $(CXX_OBJS) $(C_OBJS) | $(LIB_DIR)
	$(call compile_bin,$(CXX),$(GTEST_FLAGS) $(SO_SEARCH_PATH),$(LIB) $(LIB_GTEST_FLAG) -lpthread)

$(GTEST_OBJS): $(OBJ_DIR)/%$(OBJ_EXT): $(GTEST_DIR)/%$(CXXSRC_EXT) $(OBJ_DIR)/%$(DEPEND_EXT) | $(OBJ_DIR)
	$(call compile_obj,$(CXX),$(INC) $(INC_GTEST_FLAG),$(CXXFLAGS))

$(GTEST_DEPENDS): $(OBJ_DIR)/%$(DEPEND_EXT): $(GTEST_DIR)/%$(CXXSRC_EXT) | $(OBJ_DIR)
	$(call compile_depend,$(CXX),$(INC) $(INC_GTEST_FLAG),$(CXXFLAGS))


$(OBJ_DIR):
	@-mkdir -p $@

ifneq ($(OBJ_DIR),$(LIB_DIR))
$(LIB_DIR):
	@-mkdir -p $@
endif

.ycm_extra_conf.py: Makefile $(PATH_PROJ_ROOT)/tools/generate_ycm.sh $(CXX_DEPENDS) $(C_DEPENDS)
	@echo -e "\033[1;33m\ngenerate .ycm_extra_conf \033[0m..."
	$(PATH_PROJ_ROOT)/tools/generate_ycm.sh "$(INC)"
	@echo ""

cleanobj:
	@$(RM) -rf $(CXX_OBJS) $(C_OBJS) $(CXX_DEPENDS) $(C_DEPENDS) $(TARGET) $(GTEST_OBJS) $(GTEST_DEPENDS) .ycm_extra_conf.py*

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(MAKECMDGOALS),test)
sinclude $(CXX_DEPENDS)
sinclude $(C_DEPENDS)
endif
endif


