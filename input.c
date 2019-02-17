#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int     ft_strlen(char *str)
{
    int len = 0;

    while (*str++)
        len++;
    return (len);
}


/* 
** identify() takes input string of '.'s and '#'s
** and returns id (0 - 18) of respective
** tetrimino, -2 when finished identifying all tetriminoes,
** and -1 for error
*/

int     identify(char *data)
{
    if (ft_strlen(data) == 16)
        return (1);
    return (-1);
}


char    *get_nth_tet(int fd, int n) // n is zero based
{
    char *curr;
    char *ret_tet;
    char *head;
    int ret;

    if (n < 0)
        return (NULL);
    n++;
    while (n--)
    {
        if (!(ret = read(fd, curr, 21)))
            return (NULL);
        curr[ret] = '\0';
    }
    if (!(ret_tet = (char *)malloc(sizeof(char) * 17)))
        return (NULL);
    head = ret_tet;
    while (++n < 21)
    {
        if (*curr == '\n')
        {
            curr++;
            continue;
        }
        *ret_tet = *curr;
        ret_tet++;
        curr++; 
    }
    *curr = '\0';
    *ret_tet = '\0';
    printf("nth_tet\n%s\n", head);
    return (head);    
}

int     main(int ac, char **av)
{
    int fd;
    int n;

    if (ac != 2)
        return (0);
    fd = open(av[1], O_RDONLY);
    printf("identify_ret: %d\n", identify(get_nth_tet(fd, 3)));
    
    // while ((id = identify(get_nth_tet(fd, n))) >= 0);
    // {
    //     arr[n++] = id;
    // }
    // if (id == -1)
    //     return (error());
    
    return (0);
}

