//
// Created by Conor Meegan on 07/04/2017.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct player
{
    char name[100];  //player's name
    char type[7];  //human, ogre, elf, wizard
    int dexterity;  //player attributes
    int smartness;
    int luck;
    int strength;
    int magic_skills;
    int life_points;
    int position[2];

};

struct slot
{
    char terrain[20];  // Level Ground, City, Hill
    int row, column;
    struct slot *left;
    struct slot *right;
    struct slot *up;
    struct slot *down;
    struct slot *own_slot;
};

void ability_modification(int positionA, int positionB, int counter);
void successful_near_attack(int counter2);
void failed_near_attack(int counter, int counter2);
void successful_distant_attack(int counter, int counter2);
void failed_distant_attack(int counter2);
void magic_attack(int counter, int counter2);

struct player players_array[100];  //global variables for convenience
struct slot slots_array[7][7];

int main(void)
{
    srand(time(NULL));  //generating random every time

    //different variables used
    int number_of_players;
    int i;
    int counter, counter2;
    int random_number;

    printf("Welcome to the game Crossfire!\n");
    printf("Please enter the number of players you would like to have (there is a max of 6 players and minimum of 2): ");
    scanf("%d", &number_of_players);  //gets the number of players in the game from the user

    if(number_of_players > 6 || number_of_players < 2)  //implemented if there's an invalid number of players
    {
        while(number_of_players > 6 || number_of_players < 2)
        {
            printf("Enter a valid number of players you would like to have (max 6, min 2): ");
            scanf("%d", &number_of_players);
        }
    }

    for(i=0; i<number_of_players; i++)
    {
        printf("\nPlease enter player %d name:", i+1);
        scanf("%s", players_array[i].name);  //gets the players to type in their name and then stores it in an array

        while(strcmp(players_array[i].type, "human")!=0 && strcmp(players_array[i].type, "ogre")!=0 && strcmp(players_array[i].type, "elf")!=0 && strcmp(players_array[i].type, "wizard")!=0)
        {
            printf("%s enter in your player type by typing in either: human, ogre, elf, wizard - ", players_array[i].name);
            scanf("%s", players_array[i].type);  //gets user to enter in their desired player type
        }
    }

    for(i=0; i<number_of_players; i++)
    {
        //assigning the attributes to each player
        if(strcmp(players_array[i].type,"human") ==0)  //implements if the player is a human
        {
            players_array[i].dexterity = ((rand() % (100)) + 1);  //using ranged formula r = ((rand() % (max + 1 - min)) + min)
            players_array[i].smartness = ((rand() % (100)) + 1);
            players_array[i].luck = ((rand() % (100)) + 1);
            players_array[i].strength = ((rand() % (100)) + 1);
            players_array[i].magic_skills = ((rand() % (100)) + 1);
            players_array[i].life_points = 100;

            //repeats if sum of all attributes is greater than or equal to 300 until valid attributes are generated
            while(players_array[i].dexterity + players_array[i].smartness + players_array[i].luck + players_array[i].strength + players_array[i].magic_skills >= 300)
            {
                players_array[i].dexterity = ((rand() % (100)) + 1);
                players_array[i].smartness = ((rand() % (100)) + 1);
                players_array[i].luck = ((rand() % (100)) + 1);
                players_array[i].strength = ((rand() % (100)) + 1);
                players_array[i].magic_skills = ((rand() % (100)) + 1);
            }

            //printing out the user's attributes for them to see
            printf("\n%s -- Player Type: %s", players_array[i].name, players_array[i].type);
            printf("\n%s stats are as follows\n", players_array[i].name);
            printf("\nLife Points: %d \n", players_array[i].life_points);
            printf("\nDexterity: %d", players_array[i].dexterity);
            printf("\nSmartness: %d", players_array[i].smartness);
            printf("\nLuck: %d",  players_array[i].luck);
            printf("\nStrength: %d", players_array[i].strength);
            printf("\nMagic Skills: %d \n", players_array[i].magic_skills);
        }
        if(strcmp(players_array[i].type,"ogre") ==0)  //implements if the player is an ogre
        {
            players_array[i].magic_skills = 0;
            players_array[i].smartness = ((rand() % (20)) + 1);
            players_array[i].strength = ((rand() % (100+1-80)) + 80);
            players_array[i].dexterity = ((rand() % (100+1-80)) + 80);
            players_array[i].luck = ((rand() % (50)) + 1);
            players_array[i].life_points = 100;

            //repeats if sum of smartness and luck attributes are greater than 50 until valid attributes are generated
            while(players_array[i].smartness + players_array[i].luck > 50)
            {
                players_array[i].smartness = ((rand() % (20)) + 1);
                players_array[i].luck = ((rand() % (50)) + 1);
            }

            printf("\n%s -- Player Type: %s", players_array[i].name, players_array[i].type);
            printf("\n%s stats are as follows\n", players_array[i].name);
            printf("\nLife Points: %d \n", players_array[i].life_points);
            printf("\nDexterity: %d", players_array[i].dexterity);
            printf("\nSmartness: %d", players_array[i].smartness);
            printf("\nLuck: %d",  players_array[i].luck);
            printf("\nStrength: %d", players_array[i].strength);
            printf("\nMagic Skills: %d \n", players_array[i].magic_skills);
        }
        if(strcmp(players_array[i].type,"elf") ==0)  //implements if the player is an elf
        {
            players_array[i].luck = ((rand() % (100+1-60)) + 60);
            players_array[i].smartness = ((rand() % (100+1-70)) + 70);
            players_array[i].strength = ((rand() % (50)) + 1);
            players_array[i].magic_skills = ((rand() % (79+1-51)) + 51);
            players_array[i].dexterity = ((rand() % (100)) + 1);
            players_array[i].life_points = 100;

            printf("\n%s -- Player Type: %s", players_array[i].name, players_array[i].type);
            printf("\n%s stats are as follows\n", players_array[i].name);
            printf("\nLife Points: %d \n", players_array[i].life_points);
            printf("\nDexterity: %d", players_array[i].dexterity);
            printf("\nSmartness: %d", players_array[i].smartness);
            printf("\nLuck: %d",  players_array[i].luck);
            printf("\nStrength: %d", players_array[i].strength);
            printf("\nMagic Skills: %d \n", players_array[i].magic_skills);
        }
        if(strcmp(players_array[i].type,"wizard") ==0)  //implements if the player is a wizard
        {
            players_array[i].luck = ((rand() % (100+1-50)) + 50);
            players_array[i].smartness = ((rand() % (100+1-90)) + 90);
            players_array[i].strength = ((rand() % (20)) + 1);
            players_array[i].magic_skills = ((rand() % (100+1-80)) + 80);
            players_array[i].dexterity = ((rand() % (100)) + 1);
            players_array[i].life_points = 100;

            printf("\n%s -- Player Type: %s", players_array[i].name, players_array[i].type);
            printf("\n%s stats are as follows\n", players_array[i].name);
            printf("\nLife Points: %d \n", players_array[i].life_points);
            printf("\nDexterity: %d", players_array[i].dexterity);
            printf("\nSmartness: %d", players_array[i].smartness);
            printf("\nLuck: %d",  players_array[i].luck);
            printf("\nStrength: %d", players_array[i].strength);
            printf("\nMagic Skills: %d \n", players_array[i].magic_skills);
        }
    }



    //board creation
    for (counter = 0; counter < 7; counter++) {
        for (counter2 = 0; counter2 < 7; counter2++) {
            random_number = 1 + rand()%3;

            if (random_number == 1)
            {
                strcpy(slots_array[counter][counter2].terrain, "City");

            }

            else if (random_number == 2)
            {
                strcpy(slots_array[counter][counter2].terrain, "Hill");

            }

            else if (random_number == 3)
            {
                strcpy(slots_array[counter][counter2].terrain, "Level Ground");

            }

            slots_array[counter][counter2].row = counter;
            slots_array[counter][counter2].column = counter2;

            //put pointers to adjacent slots and own slot
            slots_array[counter][counter2].own_slot = &slots_array[counter][counter2];
            slots_array[counter][counter2].up = &slots_array[counter-1][counter2];
            slots_array[counter][counter2].down = &slots_array[counter+1][counter2];
            slots_array[counter][counter2].left = &slots_array[counter][counter2-1];
            slots_array[counter][counter2].right = &slots_array[counter][counter2+1];

            if (counter == 0)
            {
                slots_array[counter][counter2].left = NULL;
            }
            if (counter2 == 0)
            {
                slots_array[counter][counter2].up = NULL;
            }
            if (counter == 6)
            {
                slots_array[counter][counter2].down = NULL;
            }
            if (counter2 == 6)
            {
                slots_array[counter][counter2].right = NULL;
            }
        }
    }

    //putting players in the slots
    for (counter = 0; counter < number_of_players; counter++) {
        players_array[counter].position[0] = 1+(rand()%7);
        players_array[counter].position[1] = 1+(rand()%7);

    }


    char decision, option_movement, exit_game;
    int exit = 0, has_not_quit = 0, number_of_players2 = number_of_players, counter3 = 0, ignore = 0;
    int quit_players[6];

    for(counter = 0; counter < 7; counter++) {
        quit_players[counter] = 10;
    }

    for (counter = 0; counter < number_of_players; counter++) {

        has_not_quit = 0;
        ignore = 0;

        if (quit_players[counter] == counter) {
            has_not_quit = 1;
         }


        if (has_not_quit == 0) {
            printf("\n%s, your position is (%d, %d).\n", players_array[counter].name, players_array[counter].position[0] + 1, players_array[counter].position[1] + 1);
            printf("Would you like to move, attack or quit? (m/a/q): ");
            fflush(stdin);
            scanf("%c", &decision);

            if (decision == 'm')
            {
                exit = 0;
                while (exit == 0) {
                    printf("Would you like to move left, right, up or down? (l/r/u/d) ");
                    fflush(stdin);
                    scanf("%c", &option_movement);

                    if (option_movement == 'l') {
                        if (slots_array[players_array[counter].position[0]][players_array[counter].position[1]].left == NULL) {
                            printf("\nYou are on the edge of the board and can not move this way. Please try again.\n");
                        }
                        else {
                            exit = 1;
                            players_array[counter].position[1] -= 1;
                        }

                    }
                    else if (option_movement == 'r') {
                        if (slots_array[players_array[counter].position[0]][players_array[counter].position[1]].right == NULL) {
                            printf("\nYou are on the edge of the board and can not move this way. Please try again.\n");
                        }
                        else {
                            exit = 1;
                            players_array[counter].position[1] += 1;
                        }

                    }
                    else if (option_movement == 'u') {
                        if (slots_array[players_array[counter].position[0]][players_array[counter].position[1]].up == NULL) {
                            printf("\nYou are on an edge of the board and can not move this way. Please try again.\n");
                        }
                        else {
                            exit = 1;
                            players_array[counter].position[0] -= 1;
                        }

                    }
                    else if (option_movement == 'd') {
                        if (slots_array[players_array[counter].position[0]][players_array[counter].position[1]].down == NULL) {
                            printf("\nYou are on the edge of the board and can not move this way. Please try again.\n");
                        }
                        else {
                            exit = 1;
                            players_array[counter].position[0] += 1;
                        }

                    }
                    else {
                        printf("Please enter a valid option (l,r,u or d).\n");
                    }
                    if (exit == 1) {
                        printf("Your new position is (%d, %d).\n", players_array[counter].position[0] + 1, players_array[counter].position[1] + 1);
                        ability_modification(players_array[counter].position[0], players_array[counter].position[1], counter);
                    }

                }
            }

            if (decision == 'q')
            {
                printf("\nYou have quit the game.\n");
                quit_players[counter] = counter;
                number_of_players2 -= 1;
            }

            if (decision == 'a')
            {
                printf("\nIf a player is directly beside you or in your slot you can perform a near attack.");
                printf("\nIf a player is 3 spaces away you may perform a distant attack.");
                //this loop searches for any players in adjacent slots
                for (counter2 = 0; counter2 < number_of_players; counter2++) {
                    ignore = 0;

                    if (quit_players[counter2] == counter2)
                    {
                        ignore = 1;
                    }
                    if (ignore = 0)
                    {
                        if (slots_array[players_array[counter].position[0]][players_array[counter].position[1]].left == slots_array[players_array[counter2].position[0]][players_array[counter2].position[1]].own_slot)
                        {
                            printf("%s is directly to your left");
                        }
                    }

                }
            }


            if (counter == number_of_players - 1) {
                printf("\nWould you like to end the game? (y/n) ");
                fflush(stdin);
                scanf("%c", &exit_game);

                if (exit_game == 'y') {
                    counter = 10;
                }
                else {
                    counter = -1;
                }
            }

            if (number_of_players2 < 2) {
                counter = 3;
            }

        }


    }

}

void ability_modification(int positionA, int positionB, int counter)
{
    //checks what terrain the slot is and modifies the player's attributes based on what this and also the player's current attributes
    if(strcmp(slots_array[positionA][positionB].terrain, "Level Ground")==0)  //strcmp evaluates to 0 if the terrain is Level Ground
    {
        //prints out the new stats if any of them hav changed based on the slot terrain
        printf("\n%s is now in a Level Ground slot, their abilities are unchanged\n", players_array[counter].name);

    }

    if(strcmp(slots_array[positionA][positionB].terrain, "Hill")==0)
    {
        if(players_array[counter].dexterity < 50)
        {
            players_array[counter].strength = players_array[counter].strength - 10;

            printf("\n%s is now in a Hill slot, their strength is now %d\n", players_array[counter].name, players_array[counter].strength);

        }
        else if(players_array[counter].dexterity >= 60)
        {
            players_array[counter].strength = players_array[counter].strength + 10;

            printf("\n%s is now in a Hill slot, their strength is now %d\n", players_array[counter].name, players_array[counter].strength);

        }
        else if(players_array[counter].dexterity <= 50 && players_array[counter].dexterity < 60)
        {
            printf("\n%s is now in a Hill slot, their abilities are unchanged\n", players_array[counter].name);

        }
    }

    if(strcmp(slots_array[positionA][positionB].terrain, "City")==0)
    {
        if(players_array[counter].smartness > 60)
        {
            players_array[counter].magic_skills = players_array[counter].magic_skills + 10;

            printf("\n%s is now in a City slot, their magic skills are now %d\n", players_array[counter].name, players_array[counter].magic_skills);

        }
        else if(players_array[counter].smartness <= 50)
        {
            players_array[counter].dexterity = players_array[counter].dexterity - 10;

            printf("\n%s is now in a City slot, their dexterity is now %d\n", players_array[counter].name, players_array[counter].dexterity);

        }
        else if(players_array[counter].smartness > 50 && players_array[counter].smartness <= 60)
        {
            printf("\n%s is now in a City slot, their abilities are unchanged\n", players_array[counter].name);

        }
    }
}

void successful_near_attack(int counter2)
{
    players_array[counter2].life_points = players_array[counter2].life_points - (players_array[counter2].strength / 2);

    printf("\nSuccessful near attack. %s life points are now %d\n", players_array[counter2].name, players_array[counter2].life_points);
}

void failed_near_attack(int counter, int counter2)
{
    players_array[counter].life_points = players_array[counter].life_points - (players_array[counter2].strength * 0.3);

    printf("\nFailed near attack. %s life points still %d\n", players_array[counter2].name, players_array[counter2].life_points);
}

void successful_distant_attack(int counter, int counter2)
{
    players_array[counter2].life_points = players_array[counter2].life_points - (players_array[counter].strength * 0.3);

    printf("\nSuccessful distant attack. %s life points are now %d\n", players_array[counter2].name, players_array[counter2].life_points);
}

void failed_distant_attack(int counter2)
{
    printf("\nFailed distant attack. %s life points are still %d\n", players_array[counter2].name, players_array[counter2].life_points);
}

void magic_attack(int counter, int counter2)
{
    players_array[counter2].life_points = players_array[counter2].life_points - ((players_array[counter].magic_skills / 2) + (players_array[counter].smartness * 0.2));

    printf("\nSuccessful magic attack. %s life points are now %d\n", players_array[counter2].name, players_array[counter2].life_points);
}

