# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jesse <jesse@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/17 14:54:15 by juuttera          #+#    #+#              #
#    Updated: 2020/07/09 01:20:16 by jesse            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRC_PRINTF = ./printf_src/

SRC_LIBFT = ./libft_base_src/

SRC_FPRINTF = ./fprintf_src/

SRC_SNPRINTF = ./snprintf_src/

FLAGS = -Wall -Werror -Wextra

FILES_PRINTF = $(SRC_PRINTF)ft_printf.c $(SRC_PRINTF)ft_strncat_p.c $(SRC_PRINTF)print_conversion.c $(SRC_PRINTF)struct_funcs.c $(SRC_PRINTF)type_funcs.c \
			$(SRC_PRINTF)get_number.c $(SRC_PRINTF)append_funcs.c $(SRC_PRINTF)memfuncs.c $(SRC_PRINTF)conversion_funcs.c \
			$(SRC_PRINTF)conversion_funcs_2.c $(SRC_PRINTF)conversion_funcs_3.c $(SRC_PRINTF)float_func.c $(SRC_PRINTF)ll_hh.c \
			$(SRC_PRINTF)ft_strtrim_p.c $(SRC_PRINTF)nb_size_long.c $(SRC_PRINTF)float_func2.c $(SRC_PRINTF)is_type.c $(SRC_PRINTF)append_hash.c \
			$(SRC_PRINTF)append_funcs2.c $(SRC_PRINTF)append_funcs3.c $(SRC_PRINTF)append_funcs4.c

FILES_LIBFT = $(SRC_LIBFT)ft_atoi.c $(SRC_LIBFT)ft_bzero.c $(SRC_LIBFT)ft_isalnum.c $(SRC_LIBFT)ft_isalpha.c $(SRC_LIBFT)ft_isascii.c \
			$(SRC_LIBFT)ft_iscntrl.c $(SRC_LIBFT)ft_isdigit.c $(SRC_LIBFT)ft_isprint.c $(SRC_LIBFT)ft_memalloc.c $(SRC_LIBFT)ft_memchr.c \
			$(SRC_LIBFT)ft_memcmp.c $(SRC_LIBFT)ft_memcpy.c $(SRC_LIBFT)ft_memset.c $(SRC_LIBFT)ft_putchar_fd.c $(SRC_LIBFT)ft_putendl_fd.c \
			$(SRC_LIBFT)ft_putendl.c $(SRC_LIBFT)ft_putnbr.c $(SRC_LIBFT)ft_putstr_fd.c $(SRC_LIBFT)ft_putstr.c $(SRC_LIBFT)ft_strcat.c \
			$(SRC_LIBFT)ft_strchr.c $(SRC_LIBFT)ft_strcmp.c $(SRC_LIBFT)ft_strcpy.c $(SRC_LIBFT)ft_strdup.c $(SRC_LIBFT)ft_strlcat.c $(SRC_LIBFT)ft_strlen.c \
			$(SRC_LIBFT)ft_strncat.c $(SRC_LIBFT)ft_strncmp.c $(SRC_LIBFT)ft_strncpy.c $(SRC_LIBFT)ft_strnew.c $(SRC_LIBFT)ft_strnstr.c $(SRC_LIBFT)ft_strrchr.c \
			$(SRC_LIBFT)ft_strstr.c $(SRC_LIBFT)ft_tolower.c $(SRC_LIBFT)ft_toupper.c $(SRC_LIBFT)ft_lstdelone.c $(SRC_LIBFT)ft_strtrim.c $(SRC_LIBFT)ft_strsub.c \
			$(SRC_LIBFT)ft_strnequ.c $(SRC_LIBFT)ft_strmapi.c $(SRC_LIBFT)ft_strmap.c $(SRC_LIBFT)ft_strjoin.c $(SRC_LIBFT)ft_striteri.c $(SRC_LIBFT)ft_striter.c \
			$(SRC_LIBFT)ft_strequ.c $(SRC_LIBFT)ft_strdel.c $(SRC_LIBFT)ft_strclr.c $(SRC_LIBFT)ft_putnbr_fd.c $(SRC_LIBFT)ft_memmove.c $(SRC_LIBFT)ft_memdel.c \
			$(SRC_LIBFT)ft_memccpy.c $(SRC_LIBFT)ft_lstnew.c $(SRC_LIBFT)ft_lstdel.c $(SRC_LIBFT)ft_lstadd.c $(SRC_LIBFT)ft_itoa.c $(SRC_LIBFT)ft_duplicate.c \
			$(SRC_LIBFT)ft_lstiter.c $(SRC_LIBFT)ft_lstmap.c $(SRC_LIBFT)ft_strsplit.c $(SRC_LIBFT)ft_get_word_number.c $(SRC_LIBFT)ft_putchar.c \
			$(SRC_LIBFT)ft_iswhitespace.c $(SRC_LIBFT)ft_itoa_base.c $(SRC_LIBFT)ft_itoa_base2.c $(SRC_LIBFT)get_next_line.c $(SRC_LIBFT)free_arr.c

FILES_FPRINTF = $(SRC_FPRINTF)ft_fprintf.c $(SRC_FPRINTF)ft_fstrncat_fd.c $(SRC_FPRINTF)invalid_type_fd.c $(SRC_FPRINTF)printconversion_fd.c $(SRC_FPRINTF)struct_funcs_fd.c

FILES_SNPRINTF =	$(SRC_SNPRINTF)ft_snprintf.c \
					$(SRC_SNPRINTF)ft_strncat_sn.c \
					$(SRC_SNPRINTF)invalid_type_sn.c \
					$(SRC_SNPRINTF)struct_funcs_sn.c \
					$(SRC_SNPRINTF)printconversion_sn.c \
					$(SRC_SNPRINTF)buffer_management.c

INCLUDES_PRINTF = printf_includes

INCLUDES_LIBFT = libft_base_includes

INCLUDES_FPRINTF = fprintf_includes

INCLUDES_SNPRINTF = snprintf_includes

OBJECTS_PRINTF = $(subst ./printf_src/,./,$(FILES_PRINTF:.c=.o))

OBJECTS_LIBFT = $(subst ./libft_base_src/,./,$(FILES_LIBFT:.c=.o))

OBJECTS_FPRINTF = $(subst ./fprintf_src/,./,$(FILES_FPRINTF:.c=.o))

OBJECTS_SNPRINTF = $(subst ./snprintf_src/,./,$(FILES_SNPRINTF:.c=.o))

all: $(NAME)

$(NAME):
		gcc $(FLAGS) -I $(INCLUDES_SNPRINTF) -I$(INCLUDES_PRINTF) -I $(INCLUDES_LIBFT) -I$(INCLUDES_FPRINTF) -c $(FILES_PRINTF) $(FILES_LIBFT) $(FILES_FPRINTF) $(FILES_SNPRINTF)
		ar rc $(NAME) $(OBJECTS_PRINTF) $(OBJECTS_LIBFT) $(OBJECTS_FPRINTF) $(OBJECTS_SNPRINTF)
		ranlib $(NAME)
		make clean

clean:
		/bin/rm -f *.o

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all clean