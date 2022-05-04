
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>

#define FILE_TOGUI "to_gui.sandbox_nn"
#define LOCK_TOGUI "to_gui.sandbox_nn.lock"
#define FILE_TONN "to_nn.sandbox_nn"
#define LOCK_TONN "to_nn.sandbox_nn.lock"

struct globals {
  int errno;
  int alive;
  char readmsg[128];
};

struct globals g;

void WriteToGui(char* str)
{
  // Write to gui
  FILE* lock = fopen(LOCK_TOGUI, "w");
  FILE* to_gui = fopen(FILE_TOGUI, "a");

  fprintf(to_gui, "%s\n", str);

  fclose(to_gui);
  fclose(lock);
  remove(LOCK_TOGUI);
}

void HandleReadMsg()
{
  printf("msg: %s\n", g.readmsg);

  int len = strlen(g.readmsg);

  if (len > 3 && memcmp(g.readmsg, "bu:", 3) == 0)
  {
    printf("got a board update.\n");
  }
}

void ReadFromGui()
{
  if (access(LOCK_TONN, F_OK) == 0) { return; }
  
  struct stat st;
  stat(FILE_TONN, &st);

  if (st.st_size <= 0) { return; }
  
  FILE* lock = fopen(LOCK_TONN, "w");
  FILE* fp = fopen(FILE_TONN, "r");

  // read contents
  while (1)
  {
    memset(g.readmsg, 0, 128);
    fgets(g.readmsg, 128, fp);

    if (g.readmsg[0] == '\0'){ break; }

    HandleReadMsg();
  }

  fclose(fp);
  fp = fopen(FILE_TONN, "w");
  fclose(fp);
  fclose(lock);
  remove(LOCK_TONN);
}

void INT(){ g.alive = 0; }

int main(int argc, char* argv[])
{

  printf("Hello NN tic-tac-toe.\n");
  fflush(stdout);

  signal(SIGINT, INT);

  g.alive = 1;

  WriteToGui("nnconnected");

  while (g.alive != 0)
  {
    ReadFromGui();
    sleep(1);
  }

  WriteToGui("nndisconnected");

  printf("Exiting.\n");
  return 0;

}
