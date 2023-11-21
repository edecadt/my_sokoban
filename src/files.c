/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** Files
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

static int check_buffer(const char *buff)
{
    if (buff == NULL)
        return 84;
    while (*buff) {
        if (*buff != ' ' && *buff != '#' && *buff != '\n' &&
            *buff != 'P' && *buff != 'X' && *buff != 'O')
            return 84;
        buff++;
    }
    return 0;
}

char *fs_read_file(const char *filepath)
{
    struct stat st;
    char *buff;
    ssize_t size;
    int fd = open(filepath, O_RDONLY);

    if (stat(filepath, &st) == -1)
        return NULL;
    buff = malloc((st.st_size + 1) * sizeof(char));
    if (buff == NULL)
        return NULL;
    size = read(fd, buff, st.st_size);
    buff[size] = '\0';
    if (check_buffer(buff) == 84) {
        free(buff);
        return NULL;
    }
    close(fd);
    return buff;
}
