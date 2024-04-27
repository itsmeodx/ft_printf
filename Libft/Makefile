NAME		=	libft.a
CCC			=	cc -c -Wall -Wextra -Werror
INCLUDES	=	headers
OBJDIR		=	obj
SRCDIR		=	src
AR			=	ar csr
RED			=	\e[1;31m
GREEN		=	\e[1;32m
YELLOW		=	\e[3;33m
CYAN		=	\e[3;96m
END			=	\e[0m
RM			=	rm -rf

objs	=	ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o \
			ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o ft_memchr.o \
			ft_memcmp.o ft_memcpy.o ft_memmove.o ft_memset.o ft_putchar_fd.o \
			ft_putendl_fd.o ft_putnbr_fd.o ft_putstr_fd.o ft_split.o \
			ft_strchr.o ft_strdup.o ft_striteri.o ft_strjoin.o ft_strlcat.o \
			ft_strlcpy.o ft_strlen.o ft_strmapi.o ft_strncmp.o ft_strnstr.o \
			ft_strrchr.o ft_strtrim.o ft_substr.o ft_tolower.o ft_toupper.o

b_objs	=	ft_lstadd_back_bonus.o ft_lstadd_front_bonus.o ft_lstclear_bonus.o \
				ft_lstdelone_bonus.o ft_lstiter_bonus.o ft_lstlast_bonus.o \
				ft_lstmap_bonus.o ft_lstnew_bonus.o ft_lstsize_bonus.o

OBJ			=	$(addprefix $(OBJDIR)/, $(objs))
b_OBJ		=	$(addprefix $(OBJDIR)/, $(b_objs))
SRC			=	$(OBJ:$(OBJDIR)%.o=$(SRCDIR)%.c)
b_SRC		=	$(b_OBJ:$(OBJDIR)%.o=$(SRCDIR)%.c)

$(NAME):	$(OBJ)
	@echo "$(GREEN)Mandatory part is done!$(END)"

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@echo "$(CYAN)Compiling $(notdir $<)...$(END)"
	@${CCC} $< -I$(INCLUDES) -o $@ > /dev/null
	@echo "$(YELLOW)Inserting $(notdir $@) to $(NAME)...$(END)"
	@${AR} $(NAME) $@ > /dev/null

all : $(NAME) bonus

bonus : ${b_OBJ}
	@echo "$(GREEN)Bonus part is done!$(END)"

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@echo "$(CYAN)Compiling $(notdir $<)...$(END)"
	@${CCC} $< -I$(INCLUDES) -o $@
	@echo "$(YELLOW)Inserting $(notdir $@) to $(NAME)...$(END)"
	@${AR} $(NAME) $@

clean :
	@echo "$(RED)Cleaning $(OBJDIR)...$(END)"
	@${RM} $(OBJDIR)

fclean : clean
	@echo "$(RED)Cleaning $(NAME)...$(END)"
	@${RM} $(NAME)

re : fclean all

.PHONY : all clean
