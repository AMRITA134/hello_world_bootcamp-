#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void game();

int main()
{
    int value;
    printf("Enter 1 for the rules for the game and 2 for the game to start: ");
    scanf("%d", &value);
    switch(value)
    {
        case 1: printf("Rules of the game are as follows:\n1. r for rock / stone, p for paper, and s for scissor.\n2. When rock and paper are shown, paper wins.\n3. When scissor and paper are shown, scissor wins.\n4. When the same choices are shown, it's a draw.\n");
               break;
        case 2: game();
               break;
        default: printf("The end."); 
                 break;           
    }
    return 0;
}

void game()
{ 
    srand(time(NULL));
    int n, p = 0, c = 0, value;
    char player, computer;
    int x = 1;

    while(x)
    {
       n = rand() % 100;
       if(n <= 45)
       {
          computer = 'r';
       }
       else if(n >= 65)
       {
          computer = 'p';
       }
       else
       {
          computer = 's';
       }
       printf("Player, please enter your choice (r for rock, p for paper, s for scissor): ");
       scanf(" %c", &player); // Note the space before %c

       if(player == computer)
       {
          printf("Draw\n");
       }
       else if((player == 'p' && computer == 'r') || (player == 's' && computer == 'p') || (player == 'r' && computer == 's'))
       {
          printf("You win\n");
          p++;
       }
       else
       {
          printf("Computer wins\n");
          c++;
       }
       printf("\nYour points are: %d and Computer points: %d\n", p, c);

       printf("Do you want to continue? (0 for no, 1 for yes): ");
       scanf("%d", &value);
       if(value == 0)
       {
           if(p > c)
           {
               printf("You win\n");
           }
           else if(c > p)
           {
               printf("Computer wins\n");
           }
           else
           {
               printf("It a draw\n");
           }
           printf("thank you for playing");
           break;
       }  
        else
        {
            x=2;
        }
        
       }
    }

