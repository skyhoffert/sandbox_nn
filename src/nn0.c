
#include <stdio.h>

#define FILE_TOGUI "to_gui.sandbox_nn"
#define FILE_LOCK "to_gui.sandbox_nn.lock"

int main(int argc, char* argv[])
{

  printf("Hello nn0.\n");

  FILE* lock = fopen(FILE_LOCK, "w");
  FILE* to_gui = fopen(FILE_TOGUI, "w");

  fprintf(to_gui, "test from nn0.c\n");
  fprintf(to_gui, "another line as well by the way, a little longer this time.\n");

  fclose(to_gui);
  fclose(lock);
  remove(FILE_LOCK);

  return 0;

}
