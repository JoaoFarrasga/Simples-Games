int mainMenu() {
    
    printf("\t\t Main Menu \n"
           "\t 1 - Select Game\n"
           "\t 2 - Scoreboard\n"
           "\n\t 0 - Quit");

    int choice = getChoice(0, 2);
    switch (choice) {
        case 1:
            //Game Select
            break;
        
        case 2:
            //Score Select
            break;

        case 0:
            //Quit
            break;
        
        default:
            printf("\n\t//Invalid Option//\n\n");
            main();
            break;
    }
}

//GetChoice is a function to get the number between the numbers given
int getChoice(int min, int max) {

    int choiceInt = -1;

    printf("\n Select - ");
    scanf(" %d", &choiceInt);
    
    while (choiceInt > max || choiceInt < min) {
        printf("\n\t//Invalid Option//\n\n");
        printf("\n Select - ");
        scanf(" %d", &choiceInt);
    }

    system("cls");
    return choiceInt;
}
