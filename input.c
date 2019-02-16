#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int     identify(char *data)
{
    if (ft_strlen(data) == 16)
        return (1);
    return (-1);
}


char    *get_nth_tet(int fd, int n)
{
    char *curr;
    int ret;

    if (!(ret = read(fd, curr, 21)))
        return (NULL);
    
}

identify(read_please(fd));