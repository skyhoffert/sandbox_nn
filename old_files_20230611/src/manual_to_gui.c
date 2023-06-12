
#include <stdio.h>
#include <string.h>

#define FILE_TOGUI "to_gui.sandbox_nn"
#define LOCK_TOGUI "to_gui.sandbox_nn.lock"

void WriteToGui(char* str)
{
  // Write to gui
  FILE* lock = fopen(LOCK_TOGUI, "w");
  FILE* to_gui = fopen(FILE_TOGUI, "w");

  fprintf(to_gui, "%s", str);

  fclose(to_gui);
  fclose(lock);
  remove(LOCK_TOGUI);
}

int main(int argc, char* argv[])
{

  printf("Hello manual_to_gui.\n");
  fflush(stdout);

  char buf[128];

  while (1)
  {
    fgets(buf, 128, stdin);

    if (strcmp(buf, "q\n") == 0) {
      break;
    }
    
    WriteToGui(buf);
  }

  printf("Exiting.\n");
  return 0;

}
