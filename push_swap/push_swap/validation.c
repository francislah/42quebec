/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:23:00 by flahoud           #+#    #+#             */
/*   Updated: 2022/06/20 13:45:41 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	nbr;
	long	i;
	int		sign;

	sign = 1;
	i = 0;
	nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		nbr = nbr * 10 + (str[i++] - '0');
	return (nbr * sign);
}

int	digit(char **str)
{
	int	i;
	int	j;

	j = 0;
	while (str[j])
	{
		i = -1;
		if (str[j][0] == '-' && str[j][1] >= '0' && str[j][1] <= '9')
			i++;
		while (str[j][++i])
			if (str[j][i] > '9' || str[j][i] < '0')
				return (0);
		j++;
	}
	return (j);
}

int	find_duplicate(int size, int *int_stack)
{
	int	i;
	int	j;
	int	k;
	int	*tmp;

	j = 0;
	i = 0;
	tmp = (int *) malloc(sizeof(int) * size);
	while (j < size)
	{
		tmp[i++] = int_stack[j++];
		k = 0;
		while (k < (i - 1))
		{
			if (tmp[i - 1] == tmp[k++])
			{
				free(tmp);
				return (0);
			}
		}
	}
	free(tmp);
	return (1);
}

int	*convert_intfromchar(char **argv, int *size)
{
	int		i[2];
	int		*intstack;

	i[0] = -1;
	i[1] = digit(argv);
	if (i[1] == 0)
		return (NULL);
	intstack = malloc(sizeof(int) * i[1]);
	if (!intstack)
		return (NULL);
	while (argv[++i[0]])
	{
		if (ft_strlen(argv[i[0]]) > 11 || (ft_atol(argv[i[0]]) < INT_MIN
				|| ft_atol(argv[i[0]]) > INT_MAX))
		{
			free(intstack);
			return (NULL);
		}
		else
		{
			intstack[i[0]] = ft_atol(argv[i[0]]);
			*size += 1;
		}
	}
	return (intstack);
}

int	*check_args(int argc, char **argv, int	*size)
{
	char	**temp;
	int		*intstack;
	int		i;

	temp = NULL;
	i = 0;
	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		temp = ft_split(argv[1], ' ');
		intstack = convert_intfromchar(temp, size);
		while (temp[i])
			free(temp[i++]);
		free(temp);
	}
	else
		intstack = convert_intfromchar(++argv, size);
	if (!intstack || !find_duplicate(size[0], intstack))
	{
		free(intstack);
		return (NULL);
	}
	return (intstack);
}
