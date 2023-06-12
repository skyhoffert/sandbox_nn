
#include "node.h"

#include "global.h"

#include <string.h>

void print_node(char* window, struct node* node)
{
    int x = (((int)(node->id[0] - 'a')) * 4) + 3;
    int y = (((int)(node->id[1] - '0')) * 4) + 3;
    int idx = (y * WINDOW_WIDTH) + x;
    strncpy(window+idx, node->id, 2);

    window[idx-1] = '|';
    window[idx+2] = '|';
    window[idx+3] = '-';

    window[idx-WINDOW_WIDTH-1] = '+';
    window[idx-WINDOW_WIDTH+0] = '-';
    window[idx-WINDOW_WIDTH+1] = '-';
    window[idx-WINDOW_WIDTH+2] = '+';
    window[idx-WINDOW_WIDTH+3] = '/';

    window[idx+WINDOW_WIDTH-1] = '+';
    window[idx+WINDOW_WIDTH+0] = '-';
    window[idx+WINDOW_WIDTH+1] = '-';
    window[idx+WINDOW_WIDTH+2] = '+';
    window[idx+WINDOW_WIDTH+3] = '\\';
}
