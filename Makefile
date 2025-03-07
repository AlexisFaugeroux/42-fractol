# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexis <alexis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 16:50:54 by afaugero          #+#    #+#              #
#    Updated: 2025/03/07 17:29:12 by afaugero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
RESET			= "\033[0m"
BLACK    		= "\033[30m"    # Black
RED      		= "\033[31m"    # Red
GREEN    		= "\033[32m"    # Green
YELLOW   		= "\033[33m"    # Yellow
BLUE     		= "\033[34m"    # Blue
MAGENTA  		= "\033[35m"    # Magenta
CYAN     		= "\033[36m"    # Cyan
WHITE    		= "\033[37m"    # White

# Compiler
NAME			= fractol
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -O2
OS				= $(shell uname)

#Libraries
LIBFT_DIR		= libft
LIBFT				= $(LIBFT_DIR)/libft.a
LINKER			= -L$(LIBFT_DIR) -lft

#Includes
INCLUDES_DIR	= includes
INCLUDES_FLAGS	= -I$(INCLUDES_DIR) -I$(LIBFT_DIR)
INCLUDES		= $(wildcard $(INCLUDES_DIR)/*.h) \
				  $(LIBFT_DIR)/libft.h

#Sources
SRCS_DIR		= srcs/
SRCS_FILES		= fractol.c \
				  compute/compute_c.c \
				  compute/compute_colors.c \
				  compute/compute_next_elem.c \
				  init/init_fractal.c \
				  init/init_hooks.c \
				  render/render.c \
				  render/render_helpers.c \
				  theme/init_theme.c \
				  theme/set_theme_elem.c \
				  theme/set_theme_ide.c \
				  theme/set_theme_others.c \
				  theme/set_theme_rgb.c \
				  handlers/destroy_window.c \
				  handlers/handlers.c \
				  utils/utils.c
SRCS			= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

#Objects
OBJS_DIR		= objs/
OBJS_FILES		= $(SRCS_FILES:.c=.o)
OBJS			= $(addprefix $(OBJS_DIR), $(OBJS_FILES))

ifeq ($(OS), Linux)
	MLX_DIR			= mlx_linux
	MLX				= $(MLX_DIR)/libmlx.a
	LINKER			+= -lmlx -lm -lz -lXext -lX11 -L$(MLX_DIR)
	INCLUDES_FLAGS	+= -I$(MLX_DIR)
else
	MLX_DIR			= mlx_mac
	MLX				= $(MLX_DIR)/libmlx.a
	LINKER			+= -lmlx -lm -framework OpenGl -framework Appkit -L $(MLX_DIR)
	INCLUDES_FLAG	+= -I$(MLX_DIR)
endif

all: $(LIBFT) $(OBJS_DIR) ${NAME}

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c $(INCLUDES) | $(OBJS_DIR)
	@${CC} $(CFLAGS) $(INCLUDES_FLAGS) -c $< -o $@

$(LIBFT): $(wildcard $(LIBFT_DIR)/*.c) $(wildcard $(LIBFT_DIR)/*.h)
	@echo "creating libft.a..."
	@make -sC $(LIBFT_DIR) all
	@echo $(GREEN) "libft.a created" $(RESET)

$(MLX) :
	@echo "Creating mlx..."
	@make -sC $(MLX_DIR)
	@echo $(GREEN) "mlx created" $(RESET)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR) $(addprefix $(OBJS_DIR), $(dir $(SRCS_FILES)))

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@echo "compiling $(NAME)..."
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME} $(LINKER)
	@echo $(GREEN)"$(NAME) compiled" $(RESET)

clean:
	@echo "deleting objects directory..."
	@rm -rf $(OBJS_DIR)
	@echo $(GREEN) "objects deleted" $(RESET)

fclean: clean
	@echo "begining full clean..."
	@echo " deleting $(NAME)..."
	@rm -f $(NAME)
	@echo $(GREEN) " $(NAME) deleted" $(RESET)
	@echo " deleting libmlx.a..."
	@make -sC $(MLX_DIR) clean
	@echo $(GREEN) " libmlx.a deleted" $(RESET)
	@echo " deleting libft.a..."
	@make -sC $(LIBFT_DIR) fclean
	@echo $(GREEN) " libft.a deleted" $(RESET)
	@echo $(GREEN) "full clean done" $(RESET)

re:	fclean all

.PHONY: all clean fclean re libft
