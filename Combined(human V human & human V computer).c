#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

struct Player {
    int X;
    int Y;
};
typedef struct Player playerNo;

char markP1;
char markP2;
char markC;

void displayBoard(char board[3][3]);
void fillspaces(char board[3][3]);
void relativePosition(char board[3][3]);
void getCoordinate(int* coord);
bool isOccupied(char board[3][3], int x, int y);

int checkRowWin(char board[3][3], char player_mark);
int checkColWin(char board[3][3], char player_mark);
int checkPrimaryDiagonalWin(char board[3][3], char player_mark);
int checkSecondaryDiagonalWin(char board[3][3], char player_mark);
int checkResult(char board[3][3], char markA, char markB);

void selectTwoPlayerMarks();
void runTwoPlayerTurns(char board[3][3]);
void playTwoPlayerGame();

void selectComputerGameMarks();
void computerTurn(char board[3][3], int* x, int* y);
int bestMoveCheck(char board[3][3], int* x, int* y);
int bestMoveBlock(char board[3][3], int* x, int* y);
int rowwiseMove(char board[3][3], int* X, int* Y, char mark);
int colwiseMove(char board[3][3], int* X, int* Y, char mark);
int primaryDiagonalMove(char board[3][3], int* X, int* Y, char mark);
int secDiagonalMove(char board[3][3], int* X, int* Y, char mark);
void runComputerTurns(char board[3][3]);
void playComputerGame();

void displayMenu();

int main(){
    srand(time(NULL));

    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            playTwoPlayerGame();
        } else if (choice == 2) {
            playComputerGame();
        } else {
            printf("Invalid choice. Please enter 1 or 2.\n");
        }

        printf("\nDo you want to play another game? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
        printf("\n");
    } while (choice == 1);

    printf("\nThanks for playing Tic-Tac-Toe!\n");
    return 0;
}

void relativePosition(char arr[3][3]){
    printf("\n\nHere are the relative positions i.e, coordinates (x,y):\n");
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            printf("  (%d,%d)  ", i, j);
        }
        puts("");
    }
    return;
}

void fillspaces(char arr[3][3]){
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            arr[i][j] = '.';
        }
    }
    return;
}

void displayBoard(char arr[3][3]){
    printf("\n\nHere is your board. Dot('.') represents the empty spaces:-\n");
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            printf("  %c ", arr[i][j]);
        }
        puts("");
    }
    return;
}

void getCoordinate(int *n){
    *n = -1;

    while(*n > 2 || *n < 0){
        printf("Please enter a coordinate (0, 1, or 2): ");
        scanf("%d", n);

        if(*n > 2 || *n < 0){
            printf("You entered an invalid coordinate. Enter again. \n");
        }
    }
}

bool isOccupied(char arr[3][3], int x, int y){
    if (x < 0 || x > 2 || y < 0 || y > 2) {
        return true;
    }
    if(arr[x][y] != '.'){
        return true;
    } else {
        return false;
    }
}

int checkRowWin(char arr[3][3], char player_mark){
    for(int i = 0; i < 3; ++i){
        if(arr[i][0] == player_mark && arr[i][1] == player_mark && arr[i][2] == player_mark){
            return 1;
        }
    }
    return 0;
}

int checkColWin(char arr[3][3], char player_mark){
    for(int i = 0; i < 3; ++i){
        if(arr[0][i] == player_mark && arr[1][i] == player_mark && arr[2][i] == player_mark){
            return 1;
        }
    }
    return 0;
}

int checkPrimaryDiagonalWin(char arr[3][3], char player_mark){
    if(arr[0][0] == player_mark && arr[1][1] == player_mark && arr[2][2] == player_mark){
        return 1;
    }
    return 0;
}

int checkSecondaryDiagonalWin(char arr[3][3], char player_mark){
    if(arr[0][2] == player_mark && arr[1][1] == player_mark && arr[2][0] == player_mark){
        return 1;
    }
    return 0;
}

int checkResult(char arr[3][3], char markA, char markB){
    if(checkRowWin(arr, markA) ||
       checkColWin(arr, markA) ||
       checkPrimaryDiagonalWin(arr, markA) ||
       checkSecondaryDiagonalWin(arr, markA)){
        if (markA == markP1) {
            printf("\nPlayer 1 (%c) Won!\n", markP1);
        } else if (markA == markP2) {
            printf("\nPlayer 2 (%c) Won!\n", markP2);
        } else if (markA == markC) {
            printf("\nComputer (%c) Won!\n", markC);
        }
        return 1;
    }

    if(checkRowWin(arr, markB) ||
       checkColWin(arr, markB) ||
       checkPrimaryDiagonalWin(arr, markB) ||
       checkSecondaryDiagonalWin(arr, markB)){
        if (markB == markP1) {
            printf("\nPlayer 1 (%c) Won!\n", markB);
        } else if (markB == markP2) {
            printf("\nPlayer 2 (%c) Won!\n", markB);
        } else if (markB == markC) {
            printf("\nComputer (%c) Won!\n", markB);
        }
        return 1;
    }
    return 0;
}

void selectTwoPlayerMarks(){
    char temp_mark;

    do {
        printf("\nPlayer 1, kindly select your mark (O or X): ");
        scanf(" %c", &temp_mark);
        
        if (temp_mark >= 'a' && temp_mark <= 'z') {
            temp_mark = temp_mark - ('a' - 'A');
        }

        if(temp_mark != 'O' && temp_mark != 'X'){
            printf("Invalid character. Enter again. \n");
        } else {
            markP1 = temp_mark;
            markP2 = (markP1 == 'O' ? 'X' : 'O');
            printf("Player 1 is '%c', Player 2 is '%c'.\n", markP1, markP2);
            break;
        }
    } while(true);
}

void runTwoPlayerTurns(char board[3][3]){
    playerNo currentPlayerInput;
    char currentMark;

    for(int turn = 0; turn < 9; ++turn){
        if(turn % 2 == 0){
            printf("\n\nPlayer 1's turn (Mark: %c):\n", markP1);
            currentMark = markP1;
        } else {
            printf("\n\nPlayer 2's turn (Mark: %c):\n", markP2);
            currentMark = markP2;
        }

        do {
            printf("Enter X coordinate: ");
            getCoordinate(&currentPlayerInput.X);
            printf("Enter Y coordinate: ");
            getCoordinate(&currentPlayerInput.Y);

            if(isOccupied(board, currentPlayerInput.X, currentPlayerInput.Y)){
                printf("\nInvalid input. That space is already occupied. Enter again:-\n");
            } else {
                break;
            }
        } while(true);

        board[currentPlayerInput.X][currentPlayerInput.Y] = currentMark;

        displayBoard(board);

        if(checkResult(board, markP1, markP2)){
            return;
        }
    }
    printf("\nIt's a Draw!\n");
}

void playTwoPlayerGame(){
    char board[3][3];
    printf("\n--- Starting Two-Player Game ---\n");
    relativePosition(board);
    fillspaces(board);
    displayBoard(board);
    selectTwoPlayerMarks();
    runTwoPlayerTurns(board);
}

void selectComputerGameMarks(){
    char temp_mark;

    do {
        printf("\nKindly select your mark (O or X): ");
        scanf(" %c", &temp_mark);
        
        if (temp_mark >= 'a' && temp_mark <= 'z') {
            temp_mark = temp_mark - ('a' - 'A');
        }

        if(temp_mark != 'O' && temp_mark != 'X'){
            printf("Invalid character. Enter again: \n");
        } else {
            markP1 = temp_mark;
            markC = (markP1 == 'O' ? 'X' : 'O');
            printf("You are '%c', Computer is '%c'.\n", markP1, markC);
            break;
        }
    } while(true);
}

int rowwiseMove(char arr[3][3],int* X,int* Y, char mark){
   for(int i = 0; i < 3; ++i){
        int countMark = 0;
        int x_cord = -1;
        int y_cord = -1;
        bool blocked = false;

        for(int j = 0; j < 3; ++j){
            if(arr[i][j] == mark){
                countMark++;
            } else if (arr[i][j] == '.') {
                x_cord = i;
                y_cord = j;
            } else {
                blocked = true;
                break;
            }
        }
        if(!blocked && countMark == 2 && x_cord != -1){
            *X = x_cord;
            *Y = y_cord;
            return 1;
        }
    }
    return 0;
}

int colwiseMove(char arr[3][3],int* X,int* Y, char mark){
    for(int i = 0; i < 3; ++i){
        int countMark = 0;
        int x_cord = -1, y_cord = -1;
        bool blocked = false;

        for(int j = 0; j < 3; ++j){
            if(arr[j][i] == mark){
                countMark++;
            } else if (arr[j][i] == '.') {
                x_cord = j;
                y_cord = i;
            } else {
                blocked = true;
                break;
            }
        }
        if(!blocked && countMark == 2 && x_cord != -1){
            *X = x_cord;
            *Y = y_cord;
            return 1;
        }
    }
    return 0;
}

int primaryDiagonalMove(char arr[3][3],int* X, int* Y, char mark){
    int countMark = 0;
    int emptyX = -1, emptyY = -1;
    char opponentMark = (mark == markP1) ? markC : markP1;

    for (int i = 0; i < 3; ++i) {
        if (arr[i][i] == mark) {
            countMark++;
        } else if (arr[i][i] == '.') {
            emptyX = i;
            emptyY = i;
        } else if (arr[i][i] == opponentMark) {
            return 0;
        }
    }

    if (countMark == 2 && emptyX != -1) {
        *X = emptyX;
        *Y = emptyY;
        return 1;
    }
    return 0;
}

int secDiagonalMove(char arr[3][3],int* X, int* Y, char mark){
    int countMark = 0;
    int emptyX = -1, emptyY = -1;
    char opponentMark = (mark == markP1) ? markC : markP1;

    for (int i = 0; i < 3; ++i) {
        if (arr[i][2-i] == mark) {
            countMark++;
        } else if (arr[i][2-i] == '.') {
            emptyX = i;
            emptyY = 2-i;
        } else if (arr[i][2-i] == opponentMark) {
            return 0;
        }
    }

    if (countMark == 2 && emptyX != -1) {
        *X = emptyX;
        *Y = emptyY;
        return 1;
    }
    return 0;
}

int bestMoveCheck(char arr[3][3],int* x, int* y){
    if(rowwiseMove(arr, x, y, markC)){ return 1; }
    if(colwiseMove(arr, x, y, markC)){ return 1; }
    if(primaryDiagonalMove(arr, x, y, markC)){ return 1; }
    if(secDiagonalMove(arr, x, y, markC)){ return 1; }
    return 0;
}

int bestMoveBlock(char arr[3][3],int* x, int* y){
    if(rowwiseMove(arr, x, y, markP1)){ return 1; }
    if(colwiseMove(arr, x, y, markP1)){ return 1; }
    if(primaryDiagonalMove(arr, x, y, markP1)){ return 1; }
    if(secDiagonalMove(arr, x, y, markP1)){ return 1; }
    return 0;
}

void computerTurn(char board[3][3],int* x,int* y){
    if(bestMoveCheck(board,x,y)){
        printf("Computer makes a winning move (%d,%d).\n", *x, *y);
        return;
    }
    if(bestMoveBlock(board,x,y)){
        printf("Computer blocks player's winning move (%d,%d).\n", *x, *y);
        return;
    }
    if (board[1][1] == '.') {
        *x = 1;
        *y = 1;
        printf("Computer takes the center (1,1).\n");
        return;
    }
    int corners[4][2] = {{0,0}, {0,2}, {2,0}, {2,2}};
    for (int i = 0; i < 4; ++i) {
        int x_cand = corners[i][0];
        int y_cand = corners[i][1];
        if (board[x_cand][y_cand] == '.') {
            *x = x_cand;
            *y = y_cand;
            printf("Computer takes a corner (%d,%d).\n", *x, *y);
            return;
        }
    }
    int sides[4][2] = {{0,1}, {1,0}, {1,2}, {2,1}};
    for (int i = 0; i < 4; ++i) {
        int x_cand = sides[i][0];
        int y_cand = sides[i][1];
        if (board[x_cand][y_cand] == '.') {
            *x = x_cand;
            *y = y_cand;
            printf("Computer takes a side (%d,%d).\n", *x, *y);
            return;
        }
    }
    do {
        *x = rand() % 3;
        *y = rand() % 3;
    } while (isOccupied(board, *x, *y));
    printf("Computer picks a random empty spot (%d,%d).\n", *x, *y);
}

void runComputerTurns(char board[3][3]){
    playerNo playerInput;
    playerNo computerMove;
    int turnOrder;

    printf("Enter 1 if you want first turn, 2 if you want second turn: ");
    scanf("%d", &turnOrder);

    do{
        if(turnOrder < 1 || turnOrder > 2) {
            printf("You entered an invalid number. Enter again: ");
            scanf("%d", &turnOrder);
        } else {
            break;
        }
    }while(true);

    for(int turn = 0; turn < 9; ++turn){
        bool isPlayerTurn = (turnOrder == 1 && turn % 2 == 0) || (turnOrder == 2 && turn % 2 != 0);

        if(isPlayerTurn){
            printf("\n\nYour Turn (Mark: %c):\n", markP1);
            do{
                printf("Enter X coordinate: ");
                getCoordinate(&playerInput.X);
                printf("Enter Y coordinate: ");
                getCoordinate(&playerInput.Y);
                if(isOccupied(board, playerInput.X, playerInput.Y)){
                    printf("\nInvalid input. That space is already occupied. Enter again:-\n");
                } else {
                    break;
                }
            }while(true);
            board[playerInput.X][playerInput.Y] = markP1;
        } else {
            printf("\n\nComputer's Turn (Mark: %c)\n", markC);
            computerTurn(board, &computerMove.X, &computerMove.Y);
            board[computerMove.X][computerMove.Y] = markC;
        }

        displayBoard(board);

        if(checkResult(board, markP1, markC)){
            return;
        }
    }
    printf("\nIt's a Draw!\n");
}

void playComputerGame(){
    char board[3][3];
    printf("\n--- Starting Human vs. Computer Game ---\n");
    relativePosition(board);
    fillspaces(board);
    displayBoard(board);
    selectComputerGameMarks();
    runComputerTurns(board);
}

void displayMenu(){
    printf("======================================\n");
    printf("        TIC-TAC-TOE GAME MENU         \n");
    printf("======================================\n");
    printf("1. Play Human vs. Human\n");
    printf("2. Play Human vs. Computer (AI)\n");
    printf("======================================\n");
}