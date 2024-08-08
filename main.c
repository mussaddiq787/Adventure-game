
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CW2.C"

int main() {
    char command[1000];
    int room = 0;
    printf("Welcome to the adventure game!\nType help for a list of commands.\n");
    while (fgets(command,1000,stdin)) {
        if (processCommand(command, &room) == 0) break;
    }
    return 0;
}

