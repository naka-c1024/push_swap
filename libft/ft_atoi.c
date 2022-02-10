/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:33:01 by ynakashi          #+#    #+#             */
/*   Updated: 2021/10/24 17:56:47 by ynakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	read_sign(char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

static int	is_space(char c)
{
	if ((c == ' ') || (c == '\t') || (c == '\n')
		|| (c == '\v') || (c == '\r') || (c == '\f'))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	long	ans;

	ans = 0;
	i = 0;
	sign = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		sign = read_sign(str[i++]);
	while (ft_isdigit(str[i]))
	{
		if ((ans * 10 + (str[i] - '0')) / 10 != ans)
		{
			if (sign == -1)
				return ((int)LONG_MIN);
			else
				return ((int)LONG_MAX);
		}
		ans *= 10;
		ans += str[i] - '0';
		i++;
	}
	return (ans * sign);
}
// not NULL guard
/*
#include <libc.h>
int	main(void)
{
	char	a[] = "999999999999999999999999999999999";
	printf("%d = %d\n", ft_atoi(a),atoi(a));
	char	b[] = "--100";
	printf("%d = %d\n", ft_atoi(b),atoi(b));
	char	c[] = "\n+\t3";
	printf("%d = %d\n", ft_atoi(c),atoi(c));
	char	d[] = "2147483648";
	printf("%d = %d\n", ft_atoi(d),atoi(d));
	char	e[] = "-2147483649";
	printf("%d = %d\n", ft_atoi(e),atoi(e));
	char	f[] = "100ab100";
	printf("%d = %d\n", ft_atoi(f),atoi(f));
	char	g[] = "\0";
	printf("%d = %d\n", ft_atoi(g),atoi(g));
	char	h[] = "111.11";
	printf("%d = %d\n", ft_atoi(h),atoi(h));
	char	i[] = "-2147483648";
	printf("%d = %d\n", ft_atoi(i),atoi(i));
	char	j[] = "2147483647";
	printf("%d = %d\n", ft_atoi(j),atoi(j));
	char	k[] = "  ---+--+1234ab567";
	printf("%d = %d\n", ft_atoi(k),atoi(k));
	char	l[] = "\t\n\v\f\r 42";
	printf("%d = %d\n", ft_atoi(l),atoi(l));
	char	m[] = "00042";
	printf("%d = %d\n", ft_atoi(m),atoi(m));
	char	n[] = " +--123-";
	printf("%d = %d\n", ft_atoi(n),atoi(n));
}
 */
// これはやらない
/*
#include <libc.h>
void check_atoi(const char *str, int f(const char *), int ft_f(const char *))
{
	printf("%s, %d, %d\n", str, f(str), ft_f(str));
}

int main(void)
{
	check_atoi(" 2147483645", atoi, ft_atoi);
	check_atoi(" 2147483646", atoi, ft_atoi);
	check_atoi(" 2147483647", atoi, ft_atoi);
	check_atoi(" 2147483648", atoi, ft_atoi);
	check_atoi(" 2147483649", atoi, ft_atoi);
	check_atoi("-2147483645", atoi, ft_atoi);
	check_atoi("-2147483646", atoi, ft_atoi);
	check_atoi("-2147483647", atoi, ft_atoi);
	check_atoi("-2147483648", atoi, ft_atoi);
	check_atoi("-2147483649", atoi, ft_atoi);
	printf("---------------\n");
	printf("LONG_MAX: %ld\n", LONG_MAX);
	printf("---------------\n");
	check_atoi("63410682753376583680", atoi, ft_atoi);
	check_atoi("63410682753376583681", atoi, ft_atoi);
	check_atoi("-63410682753376583680", atoi, ft_atoi);
	check_atoi("-63410682753376583681", atoi, ft_atoi);
	printf("---------------\n");
	printf("LONG_MAX: %ld\n", LONG_MAX);
	printf("---------------\n");
	check_atoi("9223372036850000000", atoi, ft_atoi);
	check_atoi("9223372036854775000", atoi, ft_atoi);
	check_atoi("9223372036854775805", atoi, ft_atoi);
	check_atoi("9223372036854775806", atoi, ft_atoi);
	check_atoi("9223372036854775807", atoi, ft_atoi);
	check_atoi("9223372036854775808", atoi, ft_atoi);
	check_atoi("9223372036854775809", atoi, ft_atoi);
	check_atoi("-9223372036854775805", atoi, ft_atoi);
	check_atoi("-9223372036854775806", atoi, ft_atoi);
	check_atoi("-9223372036854775807", atoi, ft_atoi);
	check_atoi("-9223372036854775808", atoi, ft_atoi);
	check_atoi("-9223372036854775809", atoi, ft_atoi);
	printf("---------------\n");
	check_atoi("18446744073700000000", atoi, ft_atoi);
	check_atoi("18446744073709551613", atoi, ft_atoi);
	check_atoi("18446744073709551614", atoi, ft_atoi);
	check_atoi("18446744073709551615", atoi, ft_atoi);
	check_atoi("18446744073709551616", atoi, ft_atoi);
	check_atoi("18446744073709551617", atoi, ft_atoi);
	check_atoi("-18446744073709551613", atoi, ft_atoi);
	check_atoi("-18446744073709551614", atoi, ft_atoi);
	check_atoi("-18446744073709551615", atoi, ft_atoi);
	check_atoi("-18446744073709551616", atoi, ft_atoi);
	check_atoi("-18446744073709551617", atoi, ft_atoi);
	printf("---------------\n");
	check_atoi("63410682753376583678", atoi, ft_atoi);
	check_atoi("63410682753376583679", atoi, ft_atoi);
	check_atoi("63410682753376583680", atoi, ft_atoi);
	check_atoi("63410682753376583681", atoi, ft_atoi);
	check_atoi("63410682753376583682", atoi, ft_atoi);
	check_atoi("-63410682753376583678", atoi, ft_atoi);
	check_atoi("-63410682753376583679", atoi, ft_atoi);
	check_atoi("-63410682753376583680", atoi, ft_atoi);
	check_atoi("-63410682753376583681", atoi, ft_atoi);
	check_atoi("-63410682753376583682", atoi, ft_atoi);
}
 */
