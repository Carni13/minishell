/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:32:24 by jremy             #+#    #+#             */
/*   Updated: 2022/04/04 10:17:05 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXE_H
# define EXE_H

enum {in, out};

typedef struct s_sequ
{
	int		max_cmd;
	int		index;
	int		pipe[2];
	int		hd_count;
	char	**path;
	char	**envp;
}	t_sequ;

t_cmd		*create_cmd_list(t_lexing *lexing, t_msh *msh);
void		execute_child(t_sequ *seq, t_cmd *cmd, t_cmd *first_cmd);
int			__init_seq(t_sequ *seq, char ***envp, t_cmd *cmd);
int			__launcher_fork(t_sequ *seq, t_cmd *cmd, t_cmd *first_cmd);
int			__exec_builtin(char **arg, t_msh *msh, t_cmd *cmd);
int			__is_builtin(char **arg);
t_redirect	*__create_new_redirect(t_lexing *lexing);
void		__redirect_add_back(t_redirect **alst, t_redirect *new);
int			__add_redirect(t_cmd *cmd, t_lexing *lexing);
void		__redirect_list_clear(t_redirect *start);
void		__exit_child(t_sequ *seq, t_cmd *cmd, int errno_copy, int error);
int			__handle_redirect(t_cmd *cmd);
int			__find_max_cmd(t_cmd *cmd);
char		*__get_name(int index);
void		__cmd_add_back(t_cmd **alst, t_cmd *new);
char		*__get_path(char **path, char *cmd_n);
int			__is_builtin(char **arg);
int			__exec_builtin(char **arg, t_msh *msh, t_cmd *cmd);
int			__save_fd(int *std);
int			__restore_fd(int *std);
void		__init_child(t_sequ *seq, t_cmd *cmd, t_cmd *first_cmd,
				int pv_pipe_out);
int			__reset_cmd_start(t_cmd *cmd, t_redirect *save);
int			__test_access_read(t_cmd *cmd);
int			__test_access_write(t_cmd *cmd);
#endif
