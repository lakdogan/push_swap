# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 00:23:28 by lakdogan          #+#    #+#              #
#    Updated: 2025/05/04 12:44:08 by lakdogan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 					:= 	cc 
CFLAGS				:=	-Wall -Wextra -Werror $(INCLUDES)

LIBFT_URL			:=	https://github.com/lakdogan/libft.git
LIBFT_DIR			:=	libft
	
INCLUDES			:=	-I./inc -I./$(LIBFT_DIR)
BONUS_INCLUDES		:=	-I./bonus -I./$(LIBFT_DIR)
	
NAME				:=	push_swap
BONUS_NAME			:=	checker

LIBFT				:=	$(LIBFT_DIR)/libft_ftpf_gnl.a
	
OBJECTS_DIR			:=	./objs/
SRCS_DIR			:=	./srcs/
INIT_DIR			:=	$(SRCS_DIR)init/
MEM_DIR				:=	$(SRCS_DIR)mem/
ALLOCATE_DIR		:=	$(MEM_DIR)allocate/
ERROR_DIR			:=	$(MEM_DIR)error/
FREE_DIR			:=	$(MEM_DIR)free/
OPERATIONS_DIR		:=	$(SRCS_DIR)operations/
PUSH_DIR			:=	$(OPERATIONS_DIR)push/
REVERSE_DIR			:=	$(OPERATIONS_DIR)reverse/
ROTATE_DIR			:=	$(OPERATIONS_DIR)rotate/
SWAP_DIR			:=	$(OPERATIONS_DIR)swap/
PARSE_DIR			:=	$(SRCS_DIR)parse/
STATISTICS_DIR		:=	$(SRCS_DIR)statistics/
UTILS_DIR			:=	$(SRCS_DIR)utils/
VALIDATE_DIR		:=	$(SRCS_DIR)validate/
SORT_ALGORYTHM_DIR	:=	$(SRCS_DIR)sort_algorythm/
CHECKER_DIR			:=	$(SRCS_DIR)checker/
BONUS_DIR			:=	./bonus/
BONUS_OP_DIR		:=	$(BONUS_DIR)bonus_operations/
BONUS_PUSH_DIR		:=	$(BONUS_OP_DIR)push/
BONUS_REVERSE_DIR	:=	$(BONUS_OP_DIR)reverse/
BONUS_ROTATE_DIR	:=	$(BONUS_OP_DIR)rotate/
BONUS_SWAP_DIR		:=	$(BONUS_OP_DIR)swap/
BONUS_UTILS_DIR		:=	$(BONUS_DIR)bonus_utils/

PUSH_SWAP_MANDATORY_FILES := \
				$(SRCS_DIR)main.c \
				$(INIT_DIR)init_data_structs.c \
				$(ALLOCATE_DIR)allocate_arr.c \
				$(ALLOCATE_DIR)ft_alloc_int_array.c \
				$(ALLOCATE_DIR)ft_set_int_value.c \
				$(ERROR_DIR)error.c \
				$(FREE_DIR)free_arrays.c \
				$(FREE_DIR)ft_del_int_value.c \
				$(FREE_DIR)ft_free_int_array.c \
				$(FREE_DIR)ft_free_string.c \
				$(FREE_DIR)free_int.c \
				$(PARSE_DIR)split_numbers.c \
				$(VALIDATE_DIR)validate_input.c \
				$(VALIDATE_DIR)validate_unique_nums.c \
				$(UTILS_DIR)ft_isspace.c \
				$(UTILS_DIR)ft_strtoll.c \
				$(UTILS_DIR)error_handler.c \
				$(UTILS_DIR)ft_count_current_numcount.c \
				$(UTILS_DIR)check_flag_print_op.c \
				$(UTILS_DIR)ft_sqrt.c \
				$(SWAP_DIR)swap_a.c \
				$(SWAP_DIR)swap_b.c \
				$(SWAP_DIR)swap_both.c \
				$(PUSH_DIR)push_b.c \
				$(PUSH_DIR)push_a.c \
				$(ROTATE_DIR)rotate_a.c \
				$(ROTATE_DIR)rotate_b.c \
				$(ROTATE_DIR)rotate_both.c \
				$(REVERSE_DIR)reverse_rotate_a.c \
				$(REVERSE_DIR)reverse_rotate_b.c \
				$(REVERSE_DIR)reverse_rotate_both.c \
				$(CHECKER_DIR)check_for_sorted.c \
				$(CHECKER_DIR)check_for_reverse_sorted.c \
				$(SORT_ALGORYTHM_DIR)sort_descending_sorted_nums.c \
				$(SORT_ALGORYTHM_DIR)sort_two_three.c \
				$(SORT_ALGORYTHM_DIR)mini_sort.c \
				$(SORT_ALGORYTHM_DIR)sort_chunks.c \
				$(STATISTICS_DIR)statistics.c \
				$(STATISTICS_DIR)rank_transformation.c \

PUSH_SWAP_BONUS_FILES := \
				$(BONUS_DIR)checker_bonus.c \
				$(INIT_DIR)init_data_structs.c \
				$(ALLOCATE_DIR)allocate_arr.c \
				$(ALLOCATE_DIR)ft_alloc_int_array.c \
				$(ALLOCATE_DIR)ft_set_int_value.c \
				$(ERROR_DIR)error.c \
				$(FREE_DIR)free_arrays.c \
				$(FREE_DIR)ft_del_int_value.c \
				$(FREE_DIR)ft_free_int_array.c \
				$(FREE_DIR)ft_free_string.c \
				$(FREE_DIR)free_int.c \
				$(PARSE_DIR)split_numbers.c \
				$(VALIDATE_DIR)validate_input.c \
				$(VALIDATE_DIR)validate_unique_nums.c \
				$(UTILS_DIR)ft_isspace.c \
				$(UTILS_DIR)ft_strtoll.c \
				$(UTILS_DIR)error_handler.c \
				$(UTILS_DIR)ft_count_current_numcount.c \
				$(UTILS_DIR)check_flag_print_op.c \
				$(UTILS_DIR)ft_sqrt.c \
				$(BONUS_SWAP_DIR)swap_a.c \
				$(BONUS_SWAP_DIR)swap_b.c \
				$(BONUS_SWAP_DIR)swap_both.c \
				$(BONUS_PUSH_DIR)push_b.c \
				$(BONUS_PUSH_DIR)push_a.c \
				$(BONUS_ROTATE_DIR)rotate_a.c \
				$(BONUS_ROTATE_DIR)rotate_b.c \
				$(BONUS_ROTATE_DIR)rotate_both.c \
				$(BONUS_REVERSE_DIR)reverse_rotate_a.c \
				$(BONUS_REVERSE_DIR)reverse_rotate_b.c \
				$(BONUS_REVERSE_DIR)reverse_rotate_both.c \
				$(BONUS_UTILS_DIR)print.c \
				$(CHECKER_DIR)check_for_sorted.c \
				$(CHECKER_DIR)check_for_reverse_sorted.c \
				$(STATISTICS_DIR)statistics.c \
				$(STATISTICS_DIR)rank_transformation.c \
				
PUSH_SWAP_OBJS	:= $(patsubst $(SRCS_DIR)%.c,$(OBJECTS_DIR)%.o,$(PUSH_SWAP_MANDATORY_FILES))

PUSH_SWAP_BONUS_OBJS	:=	$(patsubst $(BONUS_DIR)%.c,$(OBJECTS_DIR)%.o,$(PUSH_SWAP_BONUS_FILES))



all: $(LIBFT) $(NAME)

$(LIBFT_DIR):
	@if [ ! -d "$(LIBFT_DIR)" ]; \
	then git clone $(LIBFT_URL)	$(LIBFT_DIR); \
	fi
	# @cd $(LIBFT_DIR) && make

$(LIBFT): $(LIBFT_DIR)
	@$(MAKE) -C $(LIBFT_DIR)
	@cd $(LIBFT_DIR) && make
	@touch $(LIBFT)
	
$(NAME): $(LIBFT) $(MLX) $(FDF_OBJS)
	@if	[ "$$(uname)" = "Darwin" ]; \
	then \
		$(CC) $(CFLAGS) $(FDF_OBJS) $(LIBFT) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME); \
	else \
		$(CC) $(CFLAGS) $(FDF_OBJS) $(LIBFT) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -o $(NAME); \
	fi
		
$(NAME): $(LIBFT) $(PUSH_SWAP_OBJS)
		$(CC) $(CFLAGS) $(PUSH_SWAP_OBJS) $(LIBFT) -o $(NAME)

$(OBJECTS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus:	all $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(PUSH_SWAP_BONUS_OBJS)
		$(CC) $(CFLAGS) $(PUSH_SWAP_BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
		
$(OBJECTS_DIR)%.o: $(BONUS_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJECTS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean || true

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean || true
	rm -rf $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus
