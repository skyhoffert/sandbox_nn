
#include <stdio.h>
#include <string.h>

#include "global.h"
#include "node.h"

void print_window(char* window)
{
    char line[WINDOW_WIDTH+1];
    line[WINDOW_WIDTH] = 0;
    for (int i = 0; i < WINDOW_HEIGHT; i++)
    {
        strncpy(line, window+(i*WINDOW_WIDTH), WINDOW_WIDTH);
        printf("%s\n", line);
    }
}

int main(int argc, char* argv[])
{
    UNUSED(argc);
    UNUSED(argv);

    printf("Hello, sandbox_nn.\n");
    
    printf("Make sure this looks like a good size window.\n");
    char line[WINDOW_WIDTH+1];
    memset(line, '.', WINDOW_WIDTH);
    line[WINDOW_WIDTH-1] = 0;

    for (int i = 0; i < WINDOW_HEIGHT; i++)
    {
        printf("%s\n", line);
    }

    printf("\nRunning\n\n");

    char window[WINDOW_WIDTH*WINDOW_HEIGHT];
    memset(window, ' ', WINDOW_SIZE);

    int nnodes = 10;
    struct node nodes[nnodes];
    for (int i = 0; i < nnodes; i++)
    {
        sprintf(nodes[i].id, "%c%d", 'a', i);
    }

    for (int i = 0; i < nnodes; i++)
    {
        print_node(window, &nodes[i]);
    }

    print_window(window);

    return 0;
}
