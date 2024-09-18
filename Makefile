NAME		=	libftprintf.a
CC			=	cc -Wall -Wextra -Werror
INC			=	-I./headers -I./Libft/headers
AR			=	ar crs
RM			=	rm -rf
Libft		=	Libft/libft.a
Libft_DIR	=	Libft
OBJDIR		=	obj
SRCDIR		=	src
RED			=	\e[1;31m
GREEN		=	\e[1;32m
YELLOW		=	\e[3;33m
CYAN		=	\e[3;96m
END			=	\e[0m

objs		=	ft_printf.o ft_print.o ft_utils.o ft_flags.o ft_width.o \
				ft_precision.o ft_print_char.o ft_print_hexa.o ft_print_nbr.o \
				ft_print_ptr.o ft_print_str.o

OBJ			=	$(addprefix $(OBJDIR)/, $(objs))
SRC			=	$(addprefix $(SRCDIR)/, $(objs:.o=.c))

all:		$(NAME)

bonus:		all

$(NAME):	$(Libft) $(OBJ)
	@echo "$(GREEN)$(NAME) done$(END)"

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@echo "$(CYAN)Compiling $(notdir $<)...$(END)"
	@$(CC) -c $< $(INC) -o $@
	@echo "$(YELLOW)Inserting $(notdir $@) to $(NAME)...$(END)"
	@$(AR) $(NAME) $@

$(Libft):
	@echo "$(YELLOW)Making $(notdir $(Libft))...$(END)"
	@make -C $(Libft_DIR) all > /dev/null
	@echo "$(GREEN)$(notdir $(Libft)) done$(END)"
	@echo "$(YELLOW)Copying $(notdir $(Libft)) to $(NAME)...$(END)"
	@cp $(Libft) $(NAME)
	@echo "$(GREEN)Done copying$(END)"

clean:
	@echo "$(RED)Cleaning $(OBJDIR)...$(END)"
	@make -C $(Libft_DIR) clean > /dev/null
	@$(RM) $(OBJDIR)
fclean:		clean
	@echo "$(RED)Cleaning $(NAME)...$(END)"
	@make -C $(Libft_DIR) fclean > /dev/null
	@$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean
