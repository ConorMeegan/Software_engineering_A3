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
    int position;

};

struct slot
{
    char terrain[20];  // Level Ground, City, Hill

};

void ability_modification(int counter);
void successful_near_attack(int counter_2);
void failed_near_attack(int counter, int counter_2);
void successful_distant_attack(int counter, int counter_2);
void failed_distant_attack(int counter_2);
void magic_attack(int counter, int counter_2);

struct player players_array[100];  //global variables for convenience

int main(void)
{
    srand(time(NULL));  //generating random every time

    //different variables used
    int number_of_players;
    int number_of_slots = 0;
    int i;
    int counter;
    int random_number;

    printf("Welcome to the game Crossfire!\n");
    printf("Please enter the number of players you would like to have (there is a max of 6 players and minimum of 2): ");
    scanf("%d", &number_of_players);  //gets the number of players in the game from the user

    if(number_of_players > 6)  //implemented if there's an invalid number of players
    {
        while(number_of_players > 6 || number_of_players < 2)
        {
            printf("Enter a valid number of players you would like to have (max 6): ");
            scanf("%d \n", &number_of_players);
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



}

void ability_modification(int counter)
{
    //checks what terrain the slot is and modifies the player's attributes based on what this and also the player's current attributes
    if(strcmp(slots_array[counter].terrain, "Level Ground")==0)  //strcmp evaluates to 0 if the terrain is Level Ground
    {
        //prints out the new stats if any of them hav changed based on the slot terrain
        printf("\n%s is now in a Level Ground slot\n", players_array[counter].name);

    }

    if(strcmp(slots_array[counter].terrain, "Hill")==0)
    {
        if(players_array[counter].dexterity < 50)
        {
            players_array[counter].strength = players_array[counter].strength - 10;

            printf("\n%s is now in a Hill slot\n", players_array[counter].name);

        }
        else if(players_array[counter].dexterity >= 60)
        {
            players_array[counter].strength = players_array[counter].strength + 10;

            printf("\n%s is now in a Hill slot\n", players_array[counter].name);

        }
        else if(players_array[counter].dexterity <= 50 && players_array[counter].dexterity < 60)
        {
            printf("\n%s is now in a Hill slot\n", players_array[counter].name);

        }
    }

    if(strcmp(slots_array[counter].terrain, "City")==0)
    {
        if(players_array[counter].smartness > 60)
        {
            players_array[counter].magic_skills = players_array[counter].magic_skills + 10;

            printf("\n%s is now in a City slot\n", players_array[counter].name);

        }
        else if(players_array[counter].smartness <= 50)
        {
            players_array[counter].dexterity = players_array[counter].dexterity - 10;

            printf("\n%s is now in a City slot\n", players_array[counter].name);

        }
        else if(players_array[counter].smartness > 50 && players_array[counter].smartness <= 60)
        {
            printf("\n%s is now in a City slot\n", players_array[counter].name);

        }
    }
}

void successful_near_attack(int counter_2)
{
    players_array[counter_2].life_points = players_array[counter_2].life_points - (players_array[counter_2].strength / 2);

    printf("\nSuccessful near attack. %s life points are now %d\n", players_array[counter_2].name, players_array[counter_2].life_points);
}

void failed_near_attack(int counter, int counter_2)
{
    players_array[counter].life_points = players_array[counter].life_points - (players_array[counter_2].strength * 0.3);

    printf("\nFailed near attack. %s life points still %d\n", players_array[counter_2].name, players_array[counter_2].life_points);
}

void successful_distant_attack(int counter, int counter_2)
{
    players_array[counter_2].life_points = players_array[counter_2].life_points - (players_array[counter].strength * 0.3);

    printf("\nSuccessful distant attack. %s life points are now %d\n", players_array[counter_2].name, players_array[counter_2].life_points);
}

void failed_distant_attack(int counter_2)
{
    printf("\nFailed distant attack. %s life points are still %d\n", players_array[counter_2].name, players_array[counter_2].life_points);
}

void magic_attack(int counter, int counter_2)
{
    players_array[counter_2].life_points = players_array[counter_2].life_points - ((players_array[counter].magic_skills / 2) + (players_array[counter].smartness * 0.2));

    printf("\nSuccessful magic attack. %s life points are now %d\n", players_array[counter_2].name, players_array[counter_2].life_points);
}

