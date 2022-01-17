/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <yelatman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:36:55 by yelatman          #+#    #+#             */
/*   Updated: 2022/01/17 14:32:40 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <string.h>

# define BIT_COUNT 8

void	ft_putchar(char c);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_putnbr(int n);
#endif
