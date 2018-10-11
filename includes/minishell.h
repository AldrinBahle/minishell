/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 09:39:32 by agama             #+#    #+#             */
/*   Updated: 2018/09/18 08:15:25 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** *************************** Definations of Headers *************************
*/
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# include "libft.h"

# define IS_QUOTE(x) (x == '"' || x == '\'')

/*
** *************************** Defination of Global variable ******************
*/

char	**g_envv;

/*
** *************************** Defination of function Prototypes **************
*/

void	change_dir(char *path, int print_path);
int		cd_builtin(char **command);
void	exit_shell(void);
char	*analyze_home_path(char *path, int reverse_pare);
void	display_prompt_msg(void);
int		echo_builtin(char **command);
int		exec_command(char **command);
int		exec_commands(char **commands);
int		find_env_var(char *var);
char	*get_env_var(char *var);
char	**realloc_envv(int new_size);
void	set_env_var(char *key, char *value);
int		setenv_builtin(char **command);
int		setenv_builtin(char **args);
void	signal_handler(int signo);
void	proc_signal_handler(int signo);
void	print_env(void);
void	init_envv(int argc, char **argv, char **envv);
int		unsetenv_builtin(char **command);
#endif
