NAME:=libmatrix.a
CC:=gcc
CFLAGS:=-Wall -Wextra -Wall -pedantic -ggdb3

BUILD_DIR:=build

SRCS:= $(wildcard *.c)
OBJS:=$(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $^

$(BUILD_DIR):
	mkdir $@

$(BUILD_DIR)/%.o:%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE)