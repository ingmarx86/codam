/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:14:24 by inoteboo          #+#    #+#             */
/*   Updated: 2023/04/26 09:41:16 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include <unistd.h>
# include <stdarg.h>
# include <signal.h>
# include <stdlib.h>

void	char_feeder(char *str, int pid);
void	bit_shooter(char ascii, int count, int pid);
void	flow_control(int sig);
int		ft_atoi(const char *str);

#endif
