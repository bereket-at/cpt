// Sun, Oct 18, 2026 at 09:15 PM
#include <stdio.h>  // used for: printf
#include <stdlib.h> // used for: atoi, malloc, and free
#include <string.h> // used for: strcmp and strlen

int main(int argc, char *argv[]) {
  char *cmd[] = {"enc", "dec", "version", "help"};

  if (argc < 2) {
    printf("missing command line arguments. \n");
    return 1;
  }

  if (strcmp(argv[1], cmd[2]) == 0) {
    printf("\033[1;38;2;0;123;167mCrypt Version 4.0 \033[0m\n\nFEATURES: "
           "\nUsed malloc() to make a copy of messages and modify the copies "
           "\nIncluded help argument \nIncluded space character encryption "
           "\n\nBuilt in C at Sun, Oct 18, 2026 at "
           "09:15 PM \nbereket-at \n");
    return 0;
  } else if (strcmp(argv[1], cmd[3]) == 0) {
    printf("valid option arguments are: \nenc       - encrypt message \ndec    "
           "   - decrypt message \nversion   - check version \nhelp      - get "
           "help \n\nthe formats are: \n    cpt <option> <message> <step>\n");
    return 0;
  }

  if (argc < 4) {
    printf("missing command line arguments. \n");
    return 1;
  } else if (argc > 4) {
    printf("cpt takes only 3 arguments. \n");
    return 1;
  }

  int step = atoi(argv[3]);

  if (step > 8) {
    printf("please use encrypting step below 9. \n");
    return 1;
  } else if (step < 1) {
    printf("invalid encryption steps. \n");
    return 1;
  }

  if (strcmp(argv[1], cmd[0]) == 0) {
    char *to_encrypt = argv[2];
    int slen = strlen(to_encrypt);

    char *newmsg = malloc(slen + 1);
    if (newmsg == NULL) {
      return 1;
    }

    strcpy(newmsg, to_encrypt);
    for (int i = 0; i < slen; i++) {
      if (newmsg[i] == ' ') {
        newmsg[i] = '_';
        continue;
      }
      newmsg[i] -= step;
    }

    printf("%s \n", newmsg);
    free(newmsg);
    return 0;
  } else if (strcmp(argv[1], cmd[1]) == 0) {
    char *to_decrypt = argv[2];
    int slen = strlen(to_decrypt);

    char *newmsg = malloc(slen + 1);
    if (newmsg == NULL) {
      return 1;
    }

    strcpy(newmsg, to_decrypt);
    for (int i = 0; i < slen; i++) {
      if (newmsg[i] == '_') {
        newmsg[i] = ' ';
        continue;
      }
      newmsg[i] += step;
    }

    printf("%s \n", newmsg);
    free(newmsg);
    return 0;
  } else {
    printf("cpt: %s: command not found. \nrun 'cpt help' to get help. \n",
           argv[1]);
    return 1;
  }
}
