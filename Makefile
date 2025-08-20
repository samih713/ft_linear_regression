NAME:= ft_linear_regression

LIBS_DIR:= libs
LIBS:= -lraylib -lm
INCLUDES:= includes

SRCS:= main.c $(wildcard srcs/*/*.c)
OBJS:= $(SRCS:.c=.o)

CC:= cc
CFLAGS:= -Wall -Werror -Wextra -I$(INCLUDES)
LDFLAGS:= -L$(LIBS_DIR) $(LIBS)

# ---------------- Colors & Styling ----------------
# Allow disabling color by invoking: make NO_COLOR=1
ifeq ($(NO_COLOR),1)
RESET:=
BOLD:=
DIM:=
RED:=
GREEN:=
YELLOW:=
BLUE:=
MAGENTA:=
CYAN:=
else
# Use a real ESC character via printf so shells interpret it reliably
ESC:=$(shell printf '\033')
RESET:=$(ESC)[0m
BOLD:=$(ESC)[1m
DIM:=$(ESC)[2m
RED:=$(ESC)[31m
GREEN:=$(ESC)[32m
YELLOW:=$(ESC)[33m
BLUE:=$(ESC)[34m
MAGENTA:=$(ESC)[35m
CYAN:=$(ESC)[36m
endif

# Quiet command prefix (override with make V=1 to show full commands)
ifdef V
Q:=
else
Q:=@
endif

.PHONY: all run clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(Q)printf "$(BOLD)Building $(NAME)...$(RESET)\n"
	$(Q)printf "$(BOLD)$(GREEN)[LD]$(RESET) Linking $@\n"
	$(Q)$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@
	$(Q)printf "$(BOLD)$(GREEN)✔ Built $@$(RESET)\n"

%.o: %.c
	$(Q)printf "$(BOLD)$(CYAN)[CC]$(RESET) %s -> %s\n" "$(notdir $<)" "$(notdir $@)"
	$(Q)$(CC) $(CFLAGS) -c $< -o $@

run: all
	$(Q)printf "$(BOLD)$(BLUE)[RUN]$(RESET) ./$(NAME)\n"
	$(Q)./$(NAME)

clean:
	$(Q)printf "$(BOLD)$(YELLOW)[CLEAN]$(RESET) object files\n"
	$(Q)rm -f $(OBJS)

fclean: clean
	$(Q)printf "$(BOLD)$(YELLOW)[CLEAN]$(RESET) binary $(NAME)\n"
	$(Q)rm -f $(NAME)

re:
	$(Q)$(MAKE) -s fclean
	$(Q)$(MAKE) -s

help:
	@echo "$(BOLD)Available targets:$(RESET)"
	@echo "  make (all)   - Build $(NAME)"
	@echo "  make run     - Run executable"
	@echo "  make clean   - Remove object files"
	@echo "  make fclean  - Remove objects and binary"
	@echo "  make re      - Rebuild from scratch"
	@echo "  make help    - Show this help"
	@echo "  NO_COLOR=1   - Disable colored output (e.g., make NO_COLOR=1)"
	@echo "  V=1          - Verbose build (show commands)"