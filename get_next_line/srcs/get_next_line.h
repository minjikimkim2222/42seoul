#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
# endif

# include <stdlib.h>
# include <unistd.h>

size_t  ft_strlen(char *str);
char    *ft_strdup(char *s);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strchr(const char *str, int c);
char    *AppendString(char *backup, char *buf);
char    *make_line(char *backup);
char    *update_backup(char *backup);
char    *read_set_backup(int fd, char *backup);
char    *get_next_line(int fd);

#endif