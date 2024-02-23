
#include "pipex.h"

void error(char *err)
{
    perror(err);
    exit(1);
}

void error_free(char *err, t_pipex *pipex)
{
    free_threedim(pipex->args);
    free_twodim(pipex->envp);
    perror(err);
    exit(1);
}