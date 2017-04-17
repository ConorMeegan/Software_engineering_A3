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
    for (counter = 0; counter < 7; counter++)
    {
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

            //put pointers to adjacent slots and own slot used later for close attacks
            slots_array[counter][counter2].own_slot = &slots_array[counter][counter2];
            slots_array[counter][counter2].up = &slots_array[counter-1][counter2];
            slots_array[counter][counter2].down = &slots_array[counter+1][counter2];
            slots_array[counter][counter2].left = &slots_array[counter][counter2-1];
            slots_array[counter][counter2].right = &slots_array[counter][counter2+1];

            //for any slots on the edge of the board the pointers to off the board are set to null
            if (counter2 == 0)
            {
                slots_array[counter][counter2].left = NULL;
            }
            if (counter == 0)
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
    //board is printed so players can see it
    printf("\n\nThe board is:\n__________________________________________________"
    "_______________________________________________________\n");
    for (counter = 0; counter < 7; counter++) {
        for (counter2 = 0; counter2 < 7; counter2++) {
            printf("%14s|", slots_array[counter][counter2].terrain);
            if (counter2 == 6)
            {
                printf("\n");
            }
        }
    }
    printf("__________________________________________________"
    "_______________________________________________________");

    //putting players in random slots
    for (counter = 0; counter < number_of_players; counter++) {
        players_array[counter].position[0] = (rand()%7);
        players_array[counter].position[1] = (rand()%7);

    }

    //these variables are used in the action loop of the game
    char decision, option_movement, exit_game, attack_type, attack_decision;
    int exit = 0, has_not_quit = 0, number_of_players2 = number_of_players, ignore = 0;
    //int far_attack_column2, change_column_direction, , counter3 = 0;
    int x1, x2, y1, y2, far_attack_row, far_attack_column;
    int quit_players[6], close_attack[6], far_attack[6], far_players, close_players;

    //set all arrays to set value of 10
    for(counter = 0; counter < 7; counter++) {
        quit_players[counter] = 10;
        close_attack[counter] = 10;
        far_attack[counter] = 10;
    }

    printf("\n\nThe first number indicates what row you are in and the second is your column.");
    //prints all players positions
    for(counter2 = 0; counter2 < number_of_players; counter2++)
    {
        printf("\n%s's position is (%d, %d).", players_array[counter2].name, players_array[counter2].position[0] + 1,
        players_array[counter2].position[1] + 1);
    }

    //movement, attacking and quitting all happen in this loop
    //this loop only ends when players decide to end game or there is a winner
    for (counter = 0; counter < number_of_players; counter++) {

        has_not_quit = 0;
        ignore = 0;

        //when a player from one to six quits the corresponding element in quit players array
        //is set to equal the players number eg if player 2 quits then quit_players[2] = 2
        //if a player quits they cant be given any more turns so each time counter is iterated
        //this if statement checks if that player has quit yet
        if (quit_players[counter] == counter) {
            has_not_quit = 1;
        }

        //if player has not quit they can be given a turn
        if (has_not_quit == 0) {
            printf("\n\n************************************************");
            printf("\n%s, your position is (%d, %d).\n", players_array[counter].name, players_array[counter].position[0] + 1, players_array[counter].position[1] + 1);
            printf("Would you like to move, attack or quit? (m/a/q): ");
            fflush(stdin);
            scanf("%c", &decision);

            //movement
            if (decision == 'm')
            {
                exit = 0;
                while (exit == 0) {
                    printf("Would you like to move left, right, up or down? (l/r/u/d) ");
                    fflush(stdin);
                    scanf("%c", &option_movement);

                    //all of these if statements check whether the pointer to the chosen direction is NULL
                    //if it is not then player is free to move that way
                    if (option_movement == 'l') {
                        if (slots_array[players_array[counter].position[0]][players_array[counter].position[1]].left == NULL) {
                            printf("\nYou are on the edge of the board and can not move this way. Please try again.\n");
                        }
                        //now further down if exit = 1 it is known the player can move in the chosen direction
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

            //quitting
            if (decision == 'q')
            {
                printf("\nYou have quit the game.\n");
                //use quit players array so players who have quit can be easily identified
                quit_players[counter] = counter;
                //number_of_players2 keeps track of how many players are in the game
                //it is initialised to equal the number of players and is decrimented 
                //every time a player quits or dies
                number_of_players2 -= 1;
            }

            //attacking
            if (decision == 'a')
            {
                close_players = 0;
                far_players = 0;
                for (counter2 = 0; counter2 < number_of_players; counter2++)
                {
                    //if a player is found to be close or far eg player 2 then close attack[2] = 2
                    //this makes it easier to identify what players are close or far later on
                    close_attack[counter2] = 10;
                    far_attack[counter2] = 10;
                }
                //tell player rules of attacking
                printf("\nIf a player is directly beside you or in your slot you can perform a close attack.");
                printf("\nIf a player is between 1 and 5 spaces away you may perform a distant attack.");
                printf("\nYou may attack any player with a magic attack but only if your magic skills "
                "plus your smartness is greater than 150.\n");
                //this loop searches for any players in adjacent slots
                for (counter2 = 0; counter2 < number_of_players; counter2++) {
                    ignore = 0;

                    //if the player being looked at has quit the game or is the player who is
                    //attempting to attack they should be ignored
                    if (quit_players[counter2] == counter2 || counter2 == counter)
                    {
                        ignore = 1;
                    }
                    if (ignore == 0)
                    {
                        //using pointers to check if the pointer from the attacker player up down left right or there own slot
                        //is equal to the own slot pointer of any other player
                        if (slots_array[players_array[counter].position[0]][players_array[counter].position[1]].left
                        == slots_array[players_array[counter2].position[0]][players_array[counter2].position[1]].own_slot)
                        {
                            printf("\n%s is directly to your left.", players_array[counter2].name);
                            close_players+=1;
                            close_attack[counter2] = counter2;
                        }

                        if (slots_array[players_array[counter].position[0]][players_array[counter].position[1]].right
                        == slots_array[players_array[counter2].position[0]][players_array[counter2].position[1]].own_slot)
                        {
                            printf("\n%s is directly to your right.", players_array[counter2].name);
                            close_players+=1;
                            close_attack[counter2] = counter2;
                        }

                        if (slots_array[players_array[counter].position[0]][players_array[counter].position[1]].up
                        == slots_array[players_array[counter2].position[0]][players_array[counter2].position[1]].own_slot)
                        {
                            printf("\n%s is directly above you.", players_array[counter2].name);
                            close_players+=1;
                            close_attack[counter2] = counter2;
                        }

                        if (slots_array[players_array[counter].position[0]][players_array[counter].position[1]].down
                        == slots_array[players_array[counter2].position[0]][players_array[counter2].position[1]].own_slot)
                        {
                            printf("\n%s is directly below you.", players_array[counter2].name);
                            close_players+=1;
                            close_attack[counter2] = counter2;
                        }

                        if (slots_array[players_array[counter].position[0]][players_array[counter].position[1]].own_slot
                        == slots_array[players_array[counter2].position[0]][players_array[counter2].position[1]].own_slot)
                        {
                            printf("\n%s is in your slot.", players_array[counter2].name);
                            close_players+=1;
                            close_attack[counter2] = counter2;
                        }
                    }
                }

                //finding players in far attack range
                for (counter2 = 0; counter2 < number_of_players; counter2++) {
                    if (quit_players[counter2] != counter2)
                    {
                        x1 = players_array[counter].position[0];
                        y1 = players_array[counter].position[1];
                        x2 = players_array[counter2].position[0];
                        y2 = players_array[counter2].position[1];

                        //add the distance between x and y values and if its between 1 and 5 far attack is possible
                        far_attack_row = x1 - x2;
                        far_attack_column = y1 - y2;

                        //both differences must be positive
                        if (far_attack_row < 0)
                        {
                            far_attack_row = far_attack_row*(-1);
                        }
                        if (far_attack_column < 0)
                        {
                            far_attack_column = far_attack_column*(-1);
                        }
                        if (far_attack_row + far_attack_column > 1 &&
                        far_attack_row + far_attack_column < 5)
                        {
                            //player is in range
                            far_players+=1;
                            far_attack[counter2] = counter2;
                            printf("\n%s is in range for a distant attack.", players_array[counter2].name);
                        }
                    }
                }

                //this is extra code written in the case that a distant attack could
                //only be carried out on a player exactly 3 spaces away
                /*far_attack_row = players_array[counter].position[0] - 3;
                            far_attack_column = players_array[counter].position[1];
                            far_attack_column2 = players_array[counter].position[1] + 1;
                            change_column_direction = 0;

                            for (counter3 = 0; counter3 < 7; counter3++)
                            {
                                printf ("\n(%d %d) %d", far_attack_row + 1, far_attack_column + 1, far_attack_column2 + 1);
                                //check far spaces on left side of board
                                if (players_array[counter2].position[0] == far_attack_row &&
                                    players_array[counter2].position[1] == far_attack_column)
                                {
                                    printf("\n%s is three spaces away.", players_array[counter2].name);
                                    far_players += 1;
                                    far_attack[counter2] = counter2;
                                }

                                //check far spaces on right side of board
                                if (far_attack_row >= players_array[counter].position[0] - 2 &&
                                    far_attack_row < players_array[counter].position[0] + 3)
                                {
                                    printf ("(%d %d)", far_attack_row+1, far_attack_column2+1);
                                    if (players_array[counter2].position[0] == far_attack_row &&
                                        players_array[counter2].position[1] == far_attack_column2)
                                    {
                                        printf("\n%s is three spaces away.", players_array[counter2].name);
                                        far_players += 1;
                                        far_attack[counter2] = counter2;
                                    }
                                }

                                if (far_attack_column == players_array[counter].position[1] - 3)
                                {
                                    change_column_direction = 1;
                                }
                                if (change_column_direction == 0)
                                {
                                    far_attack_column -= 1;

                                    if (far_attack_row >= players_array[counter].position[0] - 2)
                                    {
                                        far_attack_column2+=1;
                                    }
                                }
                                else if (change_column_direction == 1)
                                {
                                    far_attack_column += 1;

                                    if (far_attack_row >= players_array[counter].position[0] - 2)
                                    {
                                        far_attack_column2-=1;
                                    }

                                }

                                far_attack_row += 1;

                            }


                        }
                    }*/


                printf("\n\nThere are %d players close to you and %d players in range for a distant attack.", close_players, far_players);

                printf("\nIf you choose an attack for which there are no players in range "
                "you will not attack and it will be the next players turn");


                printf("\nWould you like to perform a close, far or magic attack? (c/f/m) ");
                fflush(stdin);
                scanf("%c", &attack_type);

                //implementing close attack
                if (attack_type == 'c')
                {
                    if (close_players == 1)
                    {
                        for (counter2 = 0; counter2 < number_of_players; counter2++) {
                            if (close_attack[counter2] == counter2)
                            {
                                if (players_array[counter2].strength <= 70)
                                {
                                    successful_near_attack(counter2);
                                    if ( players_array[counter2].life_points < 1)
                                    {
                                        printf("\n%s now has 0 life points and is out of the game.", players_array[counter2].name);
                                        quit_players[counter2] = counter2;
                                        number_of_players2-=1;
                                    }
                                }
                                else if (players_array[counter2].strength > 70)
                                {
                                    failed_near_attack(counter, counter2);
                                    if ( players_array[counter].life_points < 1)
                                    {
                                        printf("\n%s now has 0 life points and is out of the game.", players_array[counter].name);
                                        quit_players[counter] = counter;
                                        number_of_players2-=1;
                                    }
                                }
                            }
                        }
                    }
                    //more than one player who can be attacked
                    else if (close_players > 1)
                    {
                        printf("\nYou will be given an option to attack the players"
                        " close to you one by one.\n");
                        for (counter2 = 0; counter2 < number_of_players; counter2++) {
                            if (close_attack[counter2] == counter2)
                            {
                                printf("\nWould you like to attack %s? (y/n) ", players_array[counter2].name);
                                fflush(stdin);
                                scanf("%c", &attack_decision);

                                if (attack_decision == 'y')
                                {

                                    if (players_array[counter2].strength <= 70)
                                    {
                                        successful_near_attack(counter2);
                                        if ( players_array[counter2].life_points < 1)
                                        {
                                            printf("\n%s now has 0 life points and is out of the game.", players_array[counter2].name);
                                            quit_players[counter2] = counter2;
                                            number_of_players2-=1;
                                        }
                                    }
                                    else if (players_array[counter2].strength > 70)
                                    {
                                        failed_near_attack(counter, counter2);
                                    }
                                    //to ensure attacker can only perform one attack
                                    counter2 = number_of_players + 1;
                                }
                            }
                        }

                        if (counter2 == number_of_players)
                        {
                            printf("\nYou did not attack.\n");
                        }
                    }
                    else
                    {
                        printf("\nThere are no players close to you.");
                    }
                }

                //implementing far attack
                else if (attack_type == 'f') {

                    printf("\nYou will be given an option to attack the players"
                    " in range for a far attack one by one.\n");
                    printf("There are %d players in range.\n", far_players);

                    for (counter2 = 0; counter2 < number_of_players; counter2++) {
                        //if a player is in range this if statement will be entered
                        if (far_attack[counter2] == counter2)
                        {
                            printf("\nWould you like to attack %s? (y/n) ", players_array[counter2].name);
                            fflush(stdin);
                            scanf("%c", &attack_decision);

                            if (attack_decision == 'y')
                            {
                                //implement failed or successful distant attack
                                if (players_array[counter2].dexterity >= players_array[counter].dexterity)
                                {
                                    failed_distant_attack(counter2);
                                }
                                else if (players_array[counter2].dexterity < players_array[counter].dexterity)
                                {
                                    successful_distant_attack(counter, counter2);
                                    if ( players_array[counter2].life_points < 1)
                                    {
                                        printf("\n%s now has 0 life points and is out of the game.", players_array[counter2].name);
                                        quit_players[counter2] = counter2;
                                        number_of_players2-=1;
                                    }
                                }
                                //to ensure attacker can only perform one attack
                                counter2 = number_of_players + 1;
                            }
                        }
                    }

                    if (counter2 == number_of_players)
                    {
                        printf("\nYou did not attack.\n");
                    }
                }

                //magic attack
                else if (attack_type == 'm')
                {
                    if (players_array[counter].smartness + players_array[counter].magic_skills > 150)
                    {
                        printf("\nYou will be given an option to attack each player"
                        " with a magic attack one by one.\n");

                        for (counter2 = 0; counter2 <number_of_players; counter2++) {

                        //player can attack any player but themselves or a player who has quit
                            if (counter2 != counter && quit_players[counter2] != counter2) {
                                printf("\nWould you like to attack %s? (y/n) ", players_array[counter2].name);
                                fflush(stdin);
                                scanf("%c", &attack_decision);

                                if (attack_decision == 'y')
                                {
                                    magic_attack(counter, counter2);
                                    if ( players_array[counter2].life_points < 1)
                                    {
                                        printf("\n%s now has 0 life points and is out of the game.", players_array[counter2].name);
                                        quit_players[counter2] = counter2;
                                        number_of_players2-=1;
                                    }
                                    counter2 = number_of_players + 1;
                                }
                            }
                        }
                        if (counter2 == number_of_players)
                        {
                            printf("\nYou did not attack.");
                        }
                    }
                    else
                    {
                        printf("\nYou do not have the necessary stats to perform a magic attack.");
                    }
                }

            }

            //every time every player has had the same number of turns players are given the option to end game
            if (counter == number_of_players - 1) {
                printf("\nWould you like to end the game? (y/n) ");
                fflush(stdin);
                scanf("%c", &exit_game);

                if (exit_game == 'y') {
                    counter = 10;
                }
                //if players don't want to end game reset counter to minus one which will then 
                //increment to 0 (player 1) next turn
                else {
                    counter = -1;
                }
            }

            //if there is only one player left end game
            if (number_of_players2 < 2) {
                counter = number_of_players + 1;
            }

        }


    }

    if (number_of_players2 == 1)
    {
        for (counter2 = 0; counter2 < number_of_players; counter2++) {
            if (quit_players[counter2] != counter2)
            {
                printf("\n\n%s is the winner!\n", players_array[counter2].name);
            }
        }
    }
    else
    {
        printf("\n\nThe game was ended before any player won!\n");
    }
}

//has to take in the board positions and the player
//function then carries out the changes based on terrain and the player's attributes

void ability_modification(int positionA, int positionB, int counter)
{
    //checks what terrain the slot is and modifies the player's attributes based on what this and also the player's current attributes
    if(strcmp(slots_array[positionA][positionB].terrain, "Level Ground")==0)  //strcmp evaluates to 0 if the terrain is Level Ground
    {
        //prints out the new stats if any of them have changed based on the slot terrain
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

//attacking functions that take in either one or two players depending on the type of attack
//functions carry out the result of the attacks and prnt out the changes to a player's stats

void successful_near_attack(int counter2)
{
    players_array[counter2].life_points = players_array[counter2].life_points - (players_array[counter2].strength / 2);

    printf("\nSuccessful near attack. %s's life points are now %d\n", players_array[counter2].name, players_array[counter2].life_points);
}

void failed_near_attack(int counter, int counter2)
{
    players_array[counter].life_points = players_array[counter].life_points - (players_array[counter2].strength * 0.3);

    printf("\nFailed near attack. %s's life points still %d\n", players_array[counter2].name, players_array[counter2].life_points);
    printf("%s, your life points are now %d after the unsuccessful attack\n", players_array[counter].name, players_array[counter].life_points);
}

void successful_distant_attack(int counter, int counter2)
{
    players_array[counter2].life_points = players_array[counter2].life_points - (players_array[counter].strength * 0.3);

    printf("\nSuccessful distant attack. %s's life points are now %d\n", players_array[counter2].name, players_array[counter2].life_points);
}

void failed_distant_attack(int counter2)
{
    printf("\nFailed distant attack. %s's life points are still %d\n", players_array[counter2].name, players_array[counter2].life_points);
}

void magic_attack(int counter, int counter2)
{
    players_array[counter2].life_points = players_array[counter2].life_points - ((players_array[counter].magic_skills / 2) + (players_array[counter].smartness * 0.2));

    printf("\nSuccessful magic attack. %s's life points are now %d\n", players_array[counter2].name, players_array[counter2].life_points);
}

