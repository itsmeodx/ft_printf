NAME	=	libftprintf.a
CC		=	cc -Wall -Wextra -Werror
INC		=	-I./headers -I./Libft/headers
AR		=	ar crs
RM		=	rm -rf
Libft	=	Libft/libft.a
OBJDIR	=	obj
SRCDIR	=	src
RED		=	\e[1;31m
GREEN	=	\e[1;32m
YELLOW	=	\e[3;33m
CYAN	=	\e[3;96m
END		=	\e[0m

objs	=	ft_printf.o ft_print.o ft_utils.o ft_flags.o ft_width.o \
			ft_precision.o ft_print_char.o ft_print_hexa.o ft_print_nbr.o \
			ft_print_ptr.o ft_print_str.o

OBJ		=	$(addprefix $(OBJDIR)/, $(objs))
SRC		=	$(addprefix $(SRCDIR)/, $(objs:.o=.c))

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
	@echo "$(YELLOW)Making $(Libft)...$(END)"
	@make -C ./Libft libft.a > /dev/null
	@echo "$(GREEN)$(Libft) done$(END)"
	@echo "$(YELLOW)Copying $(Libft) to $(NAME)...$(END)"
	@cp Libft/libft.a $(NAME)
	@echo "$(GREEN)Done copying$(END)"

clean:
	@echo "$(RED)Cleaning $(OBJDIR)...$(END)"
	@make -C ./Libft clean > /dev/null
	@$(RM) $(OBJDIR)
fclean:		clean
	@echo "$(RED)Cleaning $(NAME)...$(END)"
	@make -C ./Libft fclean > /dev/null
	@$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean
