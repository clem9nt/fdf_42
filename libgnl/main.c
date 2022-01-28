/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:14:07 by cvidon            #+#    #+#             */
/*   Updated: 2022/01/26 11:13:17 by clem9nt          888   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <time.h>
#define TIC(T) clock_t T = clock()
#define TOC(T) printf("%s: %.4fs\n", (#T), (double)(clock() - (T)) / CLOCKS_PER_SEC)

int	main(void)
{
	int		fd;
	char	*ret;

	TIC(hello);
	for (int i = 0; i < 1000000; i++)
	{
		fd = open("file", O_RDONLY);
		ret = get_next_line(fd);
		free (ret);
	}
	TOC(hello);

	/* ret = get_next_line(fd); */
	/* printf("%s", ret); */
	/* free (ret); */
	/* ret = get_next_line(fd); */
	/* printf("%s", ret); */
	/* free (ret); */
	/* ret = get_next_line(fd); */
	/* printf("%s", ret); */
	return (0);
}
