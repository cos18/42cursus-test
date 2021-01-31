/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:50:29 by sunpark           #+#    #+#             */
/*   Updated: 2021/01/31 13:58:57 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;
    int     result;

    line = NULL;
    printf("[TEST 1] GNL with test.c\n");
    fd = open("test.c", O_RDONLY);
    while ((result = get_next_line(fd, &line)) == 1)
    {
        printf("%d>%s\n", result, line);
        free(line);
    }
    printf("%d>%s\n\n", result, line);
    free(line);
    close(fd);
    
    line = NULL;
    printf("[TEST 2] GNL with LARGE FILE\n");
    fd = open("lorem_ipsum", O_RDONLY);
    while ((result = get_next_line(fd, &line)) == 1)
        free(line);
    printf("LAST<%d>%s\n", result, line);
    free(line);
    close(fd);
    
    line = NULL;
    printf("[TEST 3] Can GNL handle errors?\n");
    result = get_next_line(300, &line);
    printf("fd : 300 => <%d>%s\n", result, line);
    if (line)
        free(line);
    line = NULL;
    fd = open("never_exist_file", O_RDONLY);
    result = get_next_line(fd, &line);
    printf("wrong file => <%d>%s\n", result, line);
    if (line)
        free(line);
    if (fd != -1)
        close(fd);
    
    printf("TEST End!\nWaiting for leaks check...\n");
    while (1)
        (void)fd;
}