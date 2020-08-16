NAME=test_input

LIB_INC=./libft/libft_base_includes/

LIB=./libft/libft.a

INC=./includes/

AC= ./autocomplete/

INPUT= ./input/

FILES=	main.c	\
		$(INPUT)input_history.c \
		$(INPUT)update_screen.c \
		$(INPUT)input_init.c \
		$(INPUT)input_editor.c \
		$(INPUT)input_editor_funcs.c \
		$(INPUT)input_word_at_cursor.c \
		$(INPUT)input_complete.c \
		$(INPUT)input_complete_path_handling.c \
		$(INPUT)input_key_management.c \
		$(INPUT)input_esc_seq.c \
		$(INPUT)input_buffer_management.c \
		$(INPUT)input_editor_funcs_2.c \
		$(INPUT)input_word_editing.c \
		$(INPUT)input_editor_undo_redo.c \
		$(AC)path_handling.c \
		$(AC)trie_query.c \
		$(AC)trie_setup.c \
		$(AC)trie_utility.c \
		$(AC)trie_verify_query.c

FLAGS= -Wall -Werror -Wextra

$(NAME):
	make re -C ./libft
	make test

test:
	gcc $(FLAGS) $(FILES) -I $(LIB_INC) -I $(INC) $(LIB) -o $(NAME)

re:
	make fclean
	make $(NAME)

fclean:
	rm -rf $(NAME)