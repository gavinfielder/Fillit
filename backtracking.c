// void				set_pos(unsigned short tet, unsigned short x, unsigned short y);
#include <string.h>
#define X pos[0]
#define Y pos[1]

int                 *pos(void)
{
    int ret[2];
    
    ret[0] = 0;
    ret[1] = 0;
    return (ret);
}

int                 *pos(int pos[2], unsigned short grid_size) // update the position, consider logical assumptions with regard to id, return NULL if a greater grid_size is needed
{
    int ret[2];

    ret[0] = pos[0] + 1;
    ret[1] = pos[1] + 1;
    if (X == grid_size)
    {
        X = 0;
        Y++;
    }
    if (Y == grid_size)
        return (NULL);
    return (ret);
}

unsigned short		overlaps(unsigned short tet1, unsigned short tet2);

unsigned short      validate(unsigned short arr[26], int n, int pos[2])
{
    int i;
    unsigned short i_temp;
    unsigned short n_temp;

    while (i < n)
    {
        i_temp = arr[i];
        n_temp = arr[n];
        if (overlaps(i_temp, n_temp))
            return (0);
    }
    return (1);
}

unsigned short      backtracking(unsigned short arr[26], int n, int pos[2], unsigned short grid_size) // n is zero based
{
    if (!(pos))
        pos = p_init();
    if (!(arr[n + 1]))
        return (1); // finished backtracking
    if (validate(arr, n, pos)) // create please
    {
        set_pos(&arr[n], X, Y);
        if (backtracking(arr, n + 1, pos, grid_size))
            return (1);                
    }
    if (!(pos = next_pos(arr, pos, grid_size)) && n == 0)
        return (backtracking(arr, the_good(n), NULL, ++grid_size));
    return (backtracking(arr, n, pos, grid_size));
}

