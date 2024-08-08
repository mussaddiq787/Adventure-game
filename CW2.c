#include"CW2.h"
//Function Definitions
int processCommand(char command[], int *room) {
    char* token;
    int i;
    int success = 1;
    token = strtok(command, "\n"); //remove newline character
    if (strcmp(token, "help") == 0) {
        help();
    }
    else if (strcmp(token, "look") == 0 || strcmp(token, "l") == 0) {
        look(*room);
    }
    else if (strcmp(token, "north") == 0 || strcmp(token, "n") == 0) {
        move(*room);
        *room = movement_array[*room][0];
    }
    else if (strcmp(token, "east") == 0 || strcmp(token, "e") == 0) {
        move(*room);
        *room = movement_array[*room][1];
    }
    else if (strcmp(token, "south") == 0 || strcmp(token, "s") == 0) {
        move(*room);
        *room = movement_array[*room][2];
    }
    else if (strcmp(token, "west") == 0 || strcmp(token, "w") == 0) {
        move(*room);
        *room = movement_array[*room][3];
    }
    else if (strcmp(token, "killMonster") == 0 || strcmp(token, "killmonster") == 0 || strcmp(token, "km") == 0 ||
             strcmp(token, "kill zombie") == 0 || strcmp(token, "kill werewolf") == 0 || strcmp(token, "kill dragon") == 0) {
        killMonster(*room);
    }
    else if (strcmp(token, "get diamond cross") == 0 || strcmp(token, "get sword") == 0 ||
             strcmp(token, "get Sword") == 0 || strcmp(token, "get elixir") == 0) {
        getObject(*room);
    }
    else if (strcmp(token, "drop copper key") == 0 || strcmp(token, "drop food") == 0 ||
             strcmp(token, "drop golden chalice") == 0) {
        dropObject(*room);
    }
    else if (strcmp(token, "inventory") == 0 || strcmp(token, "i") == 0) {
        inventory();
    }
    else if (strcmp(token, "eat food") == 0 || strcmp(token, "drink elixir") == 0 ||
             strcmp(token, "use medpack") == 0) {
        heal(*room);
    }
    else if (strcmp(token, "unlock door") == 0) {
        unlock(*room);
    }
    else if (strcmp(token, "exit") == 0) {
        printf("You have exited the game.\n");
        printf("Your final score is %d.\n", player_xp);
        success = 0;
    }
    else {
        printf("Invalid command.\n");
    }
    return success;
}
//help function
void help() {
    printf("Commands:\n");
    printf("north/n, east/e, south/s, west/w - move in the specified direction\n");
    printf("look/l - look around the room\n");
    printf("killMonster/killmonster/km - fight a monster in the room\n");
    printf("get diamond cross/get sword/get Sword/get elixir - get an item in the room\n");
    printf("drop copper key/drop food/drop golden chalice - drop an item from your inventory\n");
    printf("inventory/i - display items in your inventory\n");
    printf("eat food/drink elixir/use medpack - restore health\n");
    printf("unlock door - unlock a locked door\n");
    printf("exit - exit the game\n");
}
//look
void look(int room) {
    printf("%s", look_array[room]);
}

void move(int room) {
    if (room == 0) {
        printf("You are at the entrance.\n");
    }
    else if (room == 14) {
        printf("You have reached the exit.\n");
    }
    else {
        printf("You are entering Room%d.\n", room);
    }
}

int killMonster(int room) {
    int monster_hp;
    int monster_damage;
    int player_damage;
    if (monster_array[room] == -1) {
        printf("There is no monster in this room.\n");
        return 0;
    }
    else {
        printf("You are fighting a monster.\n");
        monster_hp = monster_array[room] * 3;
        monster_damage = monster_array[room] * 2;
        player_damage = 3;
        while (monster_hp > 0 && player_hp > 0) {
            monster_hp -= player_damage;
            player_hp -= monster_damage;
            printf("The monster has %d HP left.\n", monster_hp);
            printf("You have %d HP left.\n", player_hp);
        }
        if (player_hp <= 0) {
            printf("You have been killed by the monster!\nGame Over.\n");
            return 0;
        }
        else {
            printf("You have killed the monster!\nYou gain 3 XP.\n");
            player_xp += 3;
            return 1;
        }
    }
}

void getObject(int room) {
    if (room == 2) {
        if (player_inventory[0] == -1) {
            printf("You have picked up the food.\n");
            player_inventory[0] = 0;
        }
        else {
            printf("Your inventory is full.\n");
        }
    }
    else if (room == 4) {
        if (player_inventory[1] == -1) {
            printf("You have picked up the medpack.\n");
            player_inventory[1] = 0;
        }
        else {
            printf("Your inventory is full.\n");
        }
    }
    else if (room == 6) {
        if (player_inventory[2] == -1) {
            printf("You have picked up the sword.\n");
            player_inventory[2] = 0;
        }
        else {
            printf("Your inventory is full.\n");
        }
    }
    else if (room == 8) {
        if (player_inventory[0] == -1) {
            printf("You have picked up the bronze key.\n");
            player_inventory[0] = 1;
        }
        else {
            printf("Your inventory is full.\n");
        }
    }
    else if (room == 9) {
        if (player_inventory[1] == -1) {
            printf("You have picked up the elixir.\n");
            player_inventory[1] = 1;
        }
        else {
            printf("Your inventory is full.\n");
        }
    }
    else if (room == 10) {
        if (player_inventory[2] == -1) {
            printf("You have picked up the diamond cross.\n");
            player_inventory[2] = 1;
        }
        else {
            printf("Your inventory is full.\n");
        }
    }
    else if (room == 12) {
        if (player_inventory[0] == -1) {
            printf("You have picked up the silver spear.\n");
            player_inventory[0] = 2;
        }
        else {
            printf("Your inventory is full.\n");
        }
    }
    else if (room == 13) {
        if (player_inventory[1] == -1) {
            printf("You have picked up the golden chalice.\n");
            player_inventory[1] = 2;
        }
        else {
            printf("Your inventory is full.\n");
        }
    }
    else {
        printf("There is no item in this room.\n");
    }
}

void dropObject(int room) {
    if (room == 2) {
        if (player_inventory[0] == 0) {
            printf("You have dropped the food.\n");
            player_inventory[0] = -1;
        }
        else {
            printf("You have no food in your inventory.\n");
        }
    }
    else if (room == 4) {
        if (player_inventory[1] == 0) {
            printf("You have dropped the medpack.\n");
            player_inventory[1] = -1;
        }
        else {
            printf("You have no medpack in your inventory.\n");
        }
    }
    else if (room == 6) {
        if (player_inventory[2] == 0) {
            printf("You have dropped the sword.\n");
            player_inventory[2] = -1;
        }
        else {
            printf("You have no sword in your inventory.\n");
        }
    }
    else if (room == 8) {
        if (player_inventory[0] == 1) {
            printf("You have dropped the bronze key.\n");
            player_inventory[0] = -1;
        }
        else {
            printf("You have no bronze key in your inventory.\n");
        }
    }
    else if (room == 9) {
        if (player_inventory[1] == 1) {
            printf("You have dropped the elixir.\n");
            player_inventory[1] = -1;
        }
        else {
            printf("You have no elixir in your inventory.\n");
        }
    }
    else if (room == 10) {
        if (player_inventory[2] == 1) {
            printf("You have dropped the diamond cross.\n");
            player_inventory[2] = -1;
        }
        else {
            printf("You have no diamond cross in your inventory.\n");
        }
    }
    else if (room == 12) {
        if (player_inventory[0] == 2) {
            printf("You have dropped the silver spear.\n");
            player_inventory[0] = -1;
        }
        else {
            printf("You have no silver spear in your inventory.\n");
        }
    }
    else if (room == 13) {
        if (player_inventory[1] == 2) {
            printf("You have dropped the golden chalice.\n");
            player_inventory[1] = -1;
        }
        else {
            printf("You have no golden chalice in your inventory.\n");
        }
    }
    else {
        printf("You are not in a room with an item.\n");
    }
}

void inventory() {
    int i;
    printf("Your inventory:\n");
    for (i = 0; i < 3; i++) {
        if (player_inventory[i] == -1) {
            printf("Empty Slot\n");
        }
        else if (player_inventory[i] == 0) {
            if (i == 0) {
                printf("Food\n");
            } else if (i == 1) {
                printf("Medpack\n");
            } else {
                printf("Sword\n");
            }
        }
        else if (player_inventory[i] == 1) {
            if (i == 0) {
                printf("Bronze Key\n");
            } else if (i == 1) {
                printf("Elixir\n");
            } else {
                printf("Diamond Cross\n");
            }
        }
        else {
            if (i == 0) {
                printf("Silver Spear\n");
            } else {
                printf("Golden Chalice\n");
            }
        }
    }
}

void heal(int room) {
    if (room == 2 && player_inventory[0] == 0) {
        printf("You have eaten the food and restored 3 HP.\n");
        player_hp += 3;
    }
    else if (room == 4 && player_inventory[1] == 0) {
        printf("You have used the medpack and restored 5 HP.\n");
        player_hp += 5;
    }
    else if (room == 9 && player_inventory[1] == 1) {
        printf("You have drank the elixir and restored 4 HP.\n");
        player_hp += 4;
    }
    else {
        printf("You cannot heal in this room.\n");
    }
}

void unlock(int room) {
    if (room == 7 && player_inventory[0] == 1) {
        printf("You have unlocked the door with the bronze key.\n");
        unlock_door[0] = 1;
    }
    else if (room == 13 && player_inventory[1] == 2) {
        printf("You have unlocked the door with the golden chalice.\n");
        unlock_door[1] = 1;
    }
    else {
        printf("You cannot unlock the door in this room.\n");
    }
}

void attack(int room) {
    if (room == 3 && player_inventory[2] == 0) {
        printf("You have attacked the zombie with the sword and killed it.\n");
        monsters[room]= 0;
    }
    else if (room == 5 && player_inventory[2] == 0) {
        printf("You have attacked the werewolf with the sword and killed it.\n");
        monsters[room] = 0;
    }
    else if (room == 6 && player_inventory[2] == 0) {
        printf("You have attacked the monster with the sword and killed it.\n");
        monsters[room] = 0;
    }
    else if (room == 7 && player_inventory[0] == 2) {
        printf("You have attacked Dracula with the silver spear and killed him.\n");
        monsters[room] = 0;
    }
    else if (room == 11 && player_inventory[2] == 1) {
        printf("You have attacked the Bride of Dracula with the diamond cross and killed her.\n");
        monsters[room] = 0;
    }
    else if (room == 13 && player_inventory[1] == 2) {
        printf("You have attacked the dragon with the golden chalice and killed it.\n");
        monsters[room] = 0;
    }
    else {
        printf("You cannot attack the monster in this room.\n");
    }
}

