/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 01:44:48 by jesse             #+#    #+#             */
/*   Updated: 2020/08/23 14:24:09 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "libft.h"
# include "autocomplete_trie.h"

# include <termios.h>
# include <sys/ioctl.h>
# include <fcntl.h>

# define EDITING 0
# define DONE 42
# define MODE_RING 1
# define MODE_SINGLE 0
# define HISTORY_FILE "shell.history"

/*
** General config
*/

struct			s_buffer
{
	int		len;
	char	*data;
};

struct			s_prompt
{
	int		len;
	char	*prompt;
};

struct			s_history
{
	int				size;
	int				index;
	
	struct s_buffer *line;
};

struct			s_state_buffer
{
	int				len;
	int				pos;
	char			*data;
};

struct			s_state
{
	int						index;
	int						size;

	struct s_state_buffer	*state;
};

struct			s_clipboard
{
	int						index;
	int						size;
	int						mode;

	struct s_buffer			*line_stack;
};

struct			s_term_config
{
	int					window_cols;
	int					window_rows;
	int					pos;
	int					pos_old;
	int					used_rows;
	int					status;

	struct s_buffer		line;
	struct s_clipboard	clipboard;
	struct s_state		state_stack;
	struct s_history	history;
	struct s_prompt		prompt;
	struct termios		orig_termios;
};

struct			s_refresh_settings
{
	int	prompt_len;
	int rows;
	int	cols;
	int	old_rows;
	int	cursor_pos;
	int	cursor_pos2;
};

struct			s_line
{
	int		pos;
	char	*data;
};

struct			s_complete_handler
{
	int				size;
	int				index;
	struct s_line	*line;
};

/*
** Editor keys
*/

enum			e_input_keys
{
	ZERO = 0,
	ENTER = 13,
	TAB = 9,
	ESC = 27,
	BACKSPACE = 127,
	END = 999,
	ARROW_UP = 1000,
	ARROW_DOWN = 1001,
	ARROW_RIGHT = 1002,
	ARROW_LEFT = 1003,
	PRINTABLE = 1004,
	DEL = 1005,
	HOME = 1006,
	CTRL_B = 1007,
	CTRL_F = 1008,
	CTRL_G = 1009,
	CTRL_U = 1010,
	CTRL_R = 1011,
	CTRL_K = 1012,
	CTRL_Y = 1013,
	CTRL_W = 1014,
	CTRL_L = 1015
};

typedef	void	t_editor_fn(char c, struct s_term_config *term);

typedef struct	s_editor_key
{
	int			key;
	t_editor_fn	*fn;
}				t_key;

/*
** Init
*/

int				get_window_size(int *rows, int *cols);
void			init_config(struct s_term_config *term);
void			free_config(struct s_term_config *term);
void			reset_config(struct s_term_config *term);
int				init_editor(struct s_term_config *term);
void			start_editor(struct s_term_config *term);
void			restore_term(struct s_term_config *term);
char			*shell_get_input(struct s_term_config *term);

/*
** Buffer management
*/

void			init_buffer(struct s_buffer *buffer);
char			*allocate_data(const char *s, int str_len, int total_len);
char			*finalize_buffer(struct s_term_config *term,
				struct s_line *line, char *str, char *word_at_pos);
void			buffer_append(struct s_buffer *buffer, const char *s, int len);
void			buffer_free(struct s_buffer *buffer);
void			prepare_buffer(struct s_term_config *term);

/*
** Editor functions
*/

void			handle_key(char c, struct s_term_config *term);
void			parse_escape_seq(int *c);
void			editor_insert(char c, struct s_term_config *term);
void			editor_enter(char c, struct s_term_config *term);
void			editor_home(char c, struct s_term_config *term);
void			editor_backspace(char c, struct s_term_config *term);
void			editor_arrow_right(char c, struct s_term_config *term);
void			editor_arrow_left(char c, struct s_term_config *term);
void			editor_complete(char c, struct s_term_config *term);
void			editor_escape(char c, struct s_term_config *term);
void			editor_delete(char c, struct s_term_config *term);
void			editor_word_left(char c, struct s_term_config *term);
void			editor_word_right(char c, struct s_term_config *term);
void			editor_word_delete(char c, struct s_term_config *term);
void			editor_undo(char c, struct s_term_config *term);
void			editor_redo(char c, struct s_term_config *term);
void			editor_end(char c, struct s_term_config *term);
void			editor_kill_end(char c, struct s_term_config *term);
void			editor_kill_start(char c, struct s_term_config *term);
void			editor_paste(char c, struct s_term_config *term);
void			editor_clear_rows(char c, struct s_term_config *term);

/*
*	Clipboard & Kill ring
*/

void			add_to_clipboard(struct s_term_config *term, char *str);


/*
**	Word management
*/

int				word_border_at_left(struct s_term_config *term);
int				word_border_at_right(struct s_term_config *term);
int				get_from_pos(struct s_term_config *term, int pos);

/*
**	Render screen
*/

void			update_screen(struct s_term_config *term);

/*
** Autocomplete handling
*/

char			**trie_get_suggestions_arr(t_trie_node *root,
				const char *word, struct s_complete_handler *handler);
int				get_trie(struct s_complete_handler *handler,
						struct s_term_config *term);
int				get_arr_len(char **list);
int				free_path_query(char *path, char *query);
char			*word_at_pos(struct s_term_config *term);
char			*word_from_path(char *path);

/*
** History
*/

void			free_history(struct s_term_config *term);
void			print_history(struct s_term_config *term);
void			editor_history_up(char c, struct s_term_config *term);
void			editor_history_down(char c, struct s_term_config *term);
void			editor_history_add(struct s_term_config *term, char *str);
int				editor_history_load(struct s_term_config *term, const char *file);
int				editor_history_save(struct s_term_config *term, const char *file);

/*
** Undo | Redo
*/

void			add_state(struct s_term_config *term);
void			clear_states(struct s_term_config *term);

#endif
