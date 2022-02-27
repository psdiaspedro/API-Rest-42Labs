#ifndef CLI_H
#define CLI_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 50

typedef struct s_logs
{
	int		is_get;
	int		is_post;
	int		is_delete;
	int		get_root;
	int		get_me;
	int		get_db;
	int		post;
	int		del;
	char	*last_request_time;
	char	*last_request_method;
	char	*last_request_path;
	char	*last_request_status;
} t_logs;


void	print_last_request(t_logs *logs);
void	print_table(t_logs *logs);
void	check_method(t_logs *logs, char *line);
void	check_path(t_logs *logs, char *line);
void	last_request_path(t_logs *logs, char *line);
void	last_request_time(t_logs *logs, char *line);
void	last_request_status(t_logs *logs, char *line);
void	init(t_logs *logs);
void	get_report(t_logs *logs);


//libft functions
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnchr(const char *str, int len, int c);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*get_next_line(int fd);



#endif
