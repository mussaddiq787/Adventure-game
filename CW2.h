//Global Variables
int monsters[14] = {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0}; //monsters in each room
const char *look_array[14] = {
"You are in Room1.\nThere is a door to the north.\n",
"You are in Room2.\nThere is a door to the east and a door to the south.\nYou see food.\n",
"You are in Room3.\nThere is a door to the south.\nYou see a zombie.\n",
"You are in Room4.\nThere is a door to the east and a door to the west.\nYou see a medpack.\n",
"You are in Room5.\nThere is a door to the east.\nYou see a werewolf.\n",
"You are in Room6.\nThere is a door to the south.\nYou see a monster and a sword.\n",
"You are in Room7.\nThere is a door to the west.\nYou see Dracula and a copper key.\n",
"You are in Room8.\nThere is a door to the east.\nYou see a bronze key.\n",
"You are in Room9.\nThere is a door to the north and a door to the west.\nYou see an elixir.\n",
"You are in Room10.\nThere is a door to the east.\nYou see a Lizard-man and a diamond cross.\n",
"You are in Room11.\nThere is a door to the east.\nYou see the Bride of Dracula.\n",
"You are in Room12.\nThere is a door to the west.\nYou see a silver spear.\n",
"You are in Room13.\nThere is a door to the north.\nYou see a dragon and a golden chalice.\n",
"You are in the exit room.\nYou have successfully completed the game!\n"
};

const int movement_array[14][4] = {
    {2,-1,-1,-1},
    {3,1,-1,-1},
    {4,-1,1,-1},
    {5,-1,2,-1},
    {6,-1,-1,2},
    {7,-1,5,6},
    {8,6,-1,-1},
    {9,-1,7,10},
    {1,10,-1,9},
    {11,-1,8,-1},
    {12,11,-1,-1},
    {13,-1,12,-1},
    {14,-1,-1,13},
    {-1,-1,-1,-1}
};

const int monster_array[14] = {12, -1, 5, -1, 12, 4, 12, -1, -1, 5, 7, -1, 12, -1};

int player_hp = 12;
int player_xp = 0;
int player_inventory[3] = {-1, -1, -1};
int unlock_door[2] = {0, 0};
int current_room = 0;

//Function Prototypes
int processCommand(char command[], int *room);
void help();
void look(int room);
void move(int room);
int killMonster(int room);
void getObject(int room);
void dropObject(int room);
void inventory();
void heal(int room);
void unlock(int room);
