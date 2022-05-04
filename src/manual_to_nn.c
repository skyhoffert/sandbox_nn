
#include <stdio.h>
#include <string.h>

#define FILE_TONN "to_nn.sandbox_nn"
#define LOCK_TONN "to_nn.sandbox_nn.lock"

void WriteToNN(char* str)
{
  // Write to gui
  FILE* lock = fopen(LOCK_TONN, "w");
  FILE* to_gui = fopen(FILE_TONN, "w");

  fprintf(to_gui, "%s", str);

  fclose(to_gui);
  fclose(lock);
  remove(LOCK_TONN);
}

int main(int argc, char* argv[])
{

  printf("Hello manual_to_nn.\n");
  fflush(stdout);

  char buf[128];

  while (1)
  {
    fgets(buf, 128, stdin);

    if (strcmp(buf, "q\n") == 0) {
      break;
    }
    
    WriteToNN(buf);
  }

  printf("Exiting.\n");
  return 0;

}
