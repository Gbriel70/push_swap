#****************************************************************************************#
#		             	    		  COLORS			 								 #
#****************************************************************************************#

RED                             := \033[0;31m
GREEN                           := \033[0;32m
YELLOW                          := \033[0;33m
PURPLE                          := \033[0;35m
CYAN                            := \033[0;36m
RESET                           := \033[0m

#***************************************************************************************#
#		           					PATHS        		  								#
#***************************************************************************************#

SRCS_FT_CTYPES_DIR				:= srcs/ft_ctype/
SRCS_FT_LIST_FUNCTIONS_DIR		:= srcs/ft_list_functions/
SRCS_FT_STDLIB_DIR				:= srcs/ft_stdlib/
SRCS_FT_STRING_FUNCTIONS_DIR	:= srcs/ft_string_functions/
SRC_NOT_IN_STANDARD_DIR			:= srcs/not_in_standard/
SRC_GET_NEXT_LINE_DIR			:= $(SRC_NOT_IN_STANDARD_DIR)/get_next_line/
SRC_PRINTF_DIR					:= $(SRC_NOT_IN_STANDARD_DIR)/ft_printf_42/
INCLUDES_DIR					:= includes/
BUILD_DIR						:= build/

#*************************************************************************************#
#		           					COMANDS        		  							  #
#*************************************************************************************#

RM 				:= rm -rf
MKDIR 			:= mkdir -p
MAKEFLAGS 		+= --no-print-directory
SLEEP			:= sleep 0.1

#************************************************************************************#
#		           					FILES        		  							 #
#************************************************************************************#

NAME			:= libft.a

SRCS_FILES += $(addprefix $(SRCS_FT_CTYPES_DIR), \
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_tolower.c\
				ft_toupper.c)

SRCS_FILES += $(addprefix $(SRCS_FT_LIST_FUNCTIONS_DIR), \
				ft_lstadd_back.c\
				ft_lstadd_front.c\
				ft_lstclear.c\
				ft_lstdelone.c\
				ft_lstiter.c\
				ft_lstlast.c\
				ft_lstmap.c\
				ft_lstnew.c\
				ft_lstsize.c)

SRCS_FILES += $(addprefix $(SRCS_FT_STDLIB_DIR), \
				ft_atoi.c\
				ft_calloc.c)

SRCS_FILES += $(addprefix $(SRCS_FT_STRING_FUNCTIONS_DIR), \
				ft_bzero.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_memset.c\
				ft_strchr.c\
				ft_strdup.c\
				ft_strlcat.c\
				ft_strlcpy.c\
				ft_strlen.c\
				ft_strncmp.c\
				ft_strnstr.c\
				ft_strrchr.c)

SRCS_FILES += $(addprefix $(SRC_NOT_IN_STANDARD_DIR), \
				ft_itoa.c\
				ft_putchar_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_putstr_fd.c\
				ft_split.c\
				ft_striteri.c\
				ft_strjoin.c\
				ft_strmapi.c\
				ft_strtrim.c\
				ft_substr.c)

SRCS_FILES += $(addprefix $(SRC_GET_NEXT_LINE_DIR), \
				get_next_line.c\
				get_next_line_utils.c)

SRCS_FILES += $(addprefix $(SRC_PRINTF_DIR), \
				ft_printf_bonus.c\
				ft_printchar_and_str_bonus.c\
				ft_print_number_ptr_bonus.c\
				ft_putplus_space_and_sharp_bonus.c)

OBJECTS		:= $(SRCS_FILES:%.c=$(BUILD_DIR)%.o)

DEPEDENCIES		:= $(OBJECTS:.o=.d)

#**************************************************************************************************#
#		           						OUTPUTS MESSAGES        		  		                   #
#**************************************************************************************************#

COUNT                          = 0
CLEAN_MESSAGE                  := Library Libft objects deleted
FCLEAN_MESSAGE                 := Library Libft deleted
LIB_MESSAGE                    = $(RESET)[100%%] $(GREEN)Linking C static library $(NAME)
COMP_MESSAGE                   = Building C object

#************************************************************************************************#
#		           	     				COMPILATION        		  			                     #
#************************************************************************************************#

CC                             := cc
CFLAGS                         = -Wall -Wextra -Werror -Ofast -pedantic
CPPFLAGS                       := $(addprefix -I,$(INCLUDES_DIR)) -MMD -MP -DDEBUG
DFLAGS                         := -g3
LFLAGS                         := -march=native
FSANITIZE                      := -O1 -fno-omit-frame-pointer -g3
LDFLAGS                        := -fsanitize=address
AR                             := ar -rcs
COMPILE_OBJS                   = $(CC) $(CFLAGS) $(LFLAGS) $(CPPFLAGS) -c $< -o $@
COMPILE_LIB                    = $(AR) $(NAME) $(OBJECTS)

#**********************************************************************************************#
#		           	     					DEFINE        		  					           #
#**********************************************************************************************#

ifdef WITH_DEBUG
	CFLAGS += $(DFLAGS)
endif

ifdef WITH_FSANITIZE
	COMPILE_OBJS = $(CC) $(CFLAGS) $(LFLAGS) $(FSANITIZE) $(CPPFLAGS) -c $< -o $@ $(LDFLAGS)
endif

#********************************************************************************************#
#		           	     					FUNCTION        		  						 #
#********************************************************************************************#

define create_dir
	$(MKDIR) $(dir $@)
endef

define comp_objs
	$(eval COUNT=$(shell expr $(COUNT) + 1))
	$(COMPILE_OBJS)
	printf "[%3d%%] $(YELLOW)$(COMP_MESSAGE) $@ \r$(RESET)\n" $$(echo $$(($(COUNT) * 100 / $(words $(OBJECTS)))))
endef

define comp_lib
	$(COMPILE_LIB)
	printf "$(LIB_MESSAGE)$(RESET)\n"
endef

define clean
	$(RM) $(BUILD_DIR)
	$(SLEEP)
	printf "$(RED)$(CLEAN_MESSAGE)$(RESET)\n"
endef

define fclean
	$(RM) $(NAME)
	$(SLEEP)
	printf "$(RED)$(FCLEAN_MESSAGE)$(RESET)\n"
endef

define fsanitize
	$(call clean)
	$(call fclean)
	$(MAKE) WITH_FSANITIZE=TRUE
endef

define debug
	$(call clean)
	$(call fclean)
	$(MAKE) WITH_DEBUG=TRUE
endef

#***********************************************************************************************************#
#		           	     						TARGETS        		  										#
#***********************************************************************************************************#

all: $(NAME)

$(BUILD_DIR)%.o: %.c
	$(call create_dir)
	$(call comp_objs)

$(NAME): $(OBJECTS)
	$(call comp_lib)

clean:
	$(call clean)

fclean: clean
	$(call fclean)

re: fclean all

fsanitize:
	$(call fsanitize)

debug:
	$(call debug)

.PHONY: all clean fclean re fsanitize debug
.DEFAULT_GOAL := all
.SILENT:

-include $(DEPS)