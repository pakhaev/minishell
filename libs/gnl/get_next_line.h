/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:41:28 by cimyan            #+#    #+#             */
/*   Updated: 2020/12/28 15:53:42 by cimyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 1

size_t		ft_len(char *str, int f);
char		*ft_dup(char *str);
char		*ft_join(char *s1, char *s2);
int			ft_return(char *str);
char		*ft_ndup(char *str);
int			get_next_line(int fd, char **line);

#endif
