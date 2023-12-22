#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

char* choiceName(int choice) {
  switch (choice) {
    case 1:
      return "Paper";
      break;
    case 2:
      return "Rock";
      break;
    case 3:
      return "Scissors";
    default:
      return "Invalid";
  }
}

int generateAiChoice() {
  srand(time(0));
  return (int)(rand() % 3) + 1;
}

int isDraw(int userChoice, int aiChoice) {
  if (userChoice == aiChoice) {
    return 1;
  } else {
    return 0;
  }
}

int isUserWinner(int userChoice, int aiChoice) {
  if ((userChoice == 2 && aiChoice == 3) ||
      (userChoice == 2 && aiChoice == 1) ||
      (userChoice == 3 && aiChoice == 1)) {
    return 1;
  } else {
    return 0;
  }
}

int isChoiceValid(int choice) {
  if (choice == 1 || choice == 2 || choice == 3) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  printf("====== 1: PAPER | 2: ROCK | 3: SCISSORS ======\n\n");
  printf("Enter your choice number: ");

  int userChoice;
  scanf("%d", &userChoice);

  while (!isChoiceValid(userChoice)) {
    printf("Choice not valid!\n");
    printf("Select 1, 2 or 3... ");
    scanf("%d", &userChoice);
  }

  printf("Your choice is %s\n", choiceName(userChoice));

  printf("The AI choice is... \n");

  sleep(2);

  int aiChoice = generateAiChoice();

  printf("%s!\n", choiceName(aiChoice));

  sleep(1);

  printf("Then...\n");
  if (isDraw(userChoice, aiChoice)) {
    printf("Draw!\n");
  } else if (isUserWinner(userChoice, aiChoice)) {
    printf("You won!\n");
  } else {
    printf("You lost! :(\n");
  }

  return 0;
}
