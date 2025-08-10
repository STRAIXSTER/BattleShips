#include <iostream>
#include <ctime>

void GridPlayer(char GRID[10][10],char YourArea[10][10]);
void GridEnemy(char GRID[10][10], char EnemyArea[10][10]);
void PlayerMove(char YourArea[10][10], char EnemyArea[10][10], char GRID[10][10], char player);
void EnemyMove(char YourArea[10][10], char EnemyArea[10][10], char GRID[10][10], char computer);
bool Winner(char YourArea[10][10], char EnemyArea[10][10], char GRID[10][10]);
bool Looser(char YourArea[10][10]);



int main()
{
    char YourArea[10][10] = {
                            {'~', '~', '~', '~', '~', '~', '~', '~', 'C', '~'},
                            {'~', '~', '~', '~', '~', '~', '~', '~', 'C', '~'},
                            {'~', 'A', 'A', 'A', '~', '~', '~', '~', 'C', '~'},
                            {'~', '~', '~', '~', '~', '~', '~', '~', 'C', '~'},
                            {'~', '~', '~', '~', '~', '~', 'B', '~', 'C', '~'},
                            {'~', '~', '~', '~', '~', '~', 'B', '~', '~', '~'},
                            {'~', '~', '~', '~', '~', '~', 'B', '~', '~', '~'},
                            {'~', '~', '~', '~', '~', '~', 'B', '~', '~', '~'},
                            {'~', 'D', 'D', '~', '~', '~', '~', '~', '~', '~'},
                            {'~', '~', '~', '~', '~', '~', '~', 'S', 'S', 'S'}
                            };


    char EnemyArea[10][10] ={
                            {'~', '~', '~', '~', 'B', 'B', 'B', 'B', '~', '~'},
                            {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                            {'~', '~', '~', '~', '~', '~', '~', '~', 'D', '~'},
                            {'~', '~', '~', '~', '~', 'C', '~', '~', 'D', '~'},
                            {'~', '~', '~', '~', '~', 'C', '~', '~', '~', '~'},
                            {'~', '~', '~', '~', '~', 'C', '~', '~', '~', '~'},
                            {'~', '~', '~', '~', '~', 'C', '~', '~', '~', '~'},
                            {'S', 'S', 'S', '~', '~', 'C', '~', '~', '~', '~'},
                            {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                            {'~', '~', '~', '~', 'A', 'A', 'A', '~', '~', '~'}
    };

    char GRID[10][10] = {
                            {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                            {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                            {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                            {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                            {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                            {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                            {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                            {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                            {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                            {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'}
    };

    char player = 'X';
    char computer = 'x';
    bool play = true;
    srand(time(NULL));


    GridPlayer(GRID, YourArea);
    GridEnemy(GRID, EnemyArea);

    while(play){
        PlayerMove(YourArea, EnemyArea, GRID, player);
        GridPlayer(GRID, YourArea);
        GridEnemy(GRID, EnemyArea);

        if(Winner(YourArea, EnemyArea, GRID)){
            play = false;
            break;
        }

        else if(Looser(YourArea)){
            play = false;
            break;
        }

        EnemyMove(YourArea, EnemyArea, GRID, computer);
        GridPlayer(GRID, YourArea);
        GridEnemy(GRID, EnemyArea);
    }
    
    return 0;
}

void GridPlayer(char GRID[10][10] , char YourArea[10][10]){

    std::cout << "YOU" <<'\n';
    std::cout <<"   ------------------------------------------" <<'\n';
    std::cout <<"    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10|" <<'\n';
    std::cout <<"   ------------------------------------------" <<'\n';
    std::cout <<"  A | " << YourArea[0][0] << " | " << YourArea[0][1] << " | " << YourArea[0][2] << " | " << YourArea[0][3] << " | " << YourArea[0][4]<< " | " << YourArea[0][5] << " | " << YourArea[0][6] << " | " << YourArea[0][7] << " | " << YourArea[0][8] << " | " << YourArea[0][9] << " |" <<'\n';
    std::cout <<"   ------------------------------------------" <<'\n';
    std::cout <<"  B | " << YourArea[1][0] << " | " << YourArea[1][1] << " | " << YourArea[1][2] << " | " << YourArea[1][3] << " | " << YourArea[1][4]<< " | " << YourArea[1][5] << " | " << YourArea[1][6] << " | " << YourArea[1][7] << " | " << YourArea[1][8] << " | " << YourArea[1][9] << " |" <<'\n';
    std::cout <<"   ------------------------------------------" <<'\n';
    std::cout <<"  C | " << YourArea[2][0] << " | " << YourArea[2][1] << " | " << YourArea[2][2] << " | " << YourArea[2][3] << " | " << YourArea[2][4]<< " | " << YourArea[2][5] << " | " << YourArea[2][6] << " | " << YourArea[2][7] << " | " << YourArea[2][8] << " | " << YourArea[2][9] << " |" <<'\n';
    std::cout <<"   ------------------------------------------" <<'\n';
    std::cout <<"  D | " << YourArea[3][0] << " | " << YourArea[3][1] << " | " << YourArea[3][2] << " | " << YourArea[3][3] << " | " << YourArea[3][4]<< " | " << YourArea[3][5] << " | " << YourArea[3][6] << " | " << YourArea[3][7] << " | " << YourArea[3][8] << " | " << YourArea[3][9] << " |" <<'\n';
    std::cout <<"   ------------------------------------------" <<'\n';
    std::cout <<"  E | " << YourArea[4][0] << " | " << YourArea[4][1] << " | " << YourArea[4][2] << " | " << YourArea[4][3] << " | " << YourArea[4][4]<< " | " << YourArea[4][5] << " | " << YourArea[4][6] << " | " << YourArea[4][7] << " | " << YourArea[4][8] << " | " << YourArea[4][9] << " |" <<'\n';
    std::cout <<"   ------------------------------------------" <<'\n';
    std::cout <<"  F | " << YourArea[5][0] << " | " << YourArea[5][1] << " | " << YourArea[5][2] << " | " << YourArea[5][3] << " | " << YourArea[5][4]<< " | " << YourArea[5][5] << " | " << YourArea[5][6] << " | " << YourArea[5][7] << " | " << YourArea[5][8] << " | " << YourArea[5][9] << " |" <<'\n';
    std::cout <<"   ------------------------------------------" <<'\n';
    std::cout <<"  G | " << YourArea[6][0] << " | " << YourArea[6][1] << " | " << YourArea[6][2] << " | " << YourArea[6][3] << " | " << YourArea[6][4]<< " | " << YourArea[6][5] << " | " << YourArea[6][6] << " | " << YourArea[6][7] << " | " << YourArea[6][8] << " | " << YourArea[6][9] << " |" <<'\n';
    std::cout <<"   ------------------------------------------" <<'\n';
    std::cout <<"  H | " << YourArea[7][0] << " | " << YourArea[7][1] << " | " << YourArea[7][2] << " | " << YourArea[7][3] << " | " << YourArea[7][4]<< " | " << YourArea[7][5] << " | " << YourArea[7][6] << " | " << YourArea[7][7] << " | " << YourArea[7][8] << " | " << YourArea[7][9] << " |" <<'\n';
    std::cout <<"   ------------------------------------------" <<'\n';
    std::cout <<"  I | " << YourArea[8][0] << " | " << YourArea[8][1] << " | " << YourArea[8][2] << " | " << YourArea[8][3] << " | " << YourArea[8][4]<< " | " << YourArea[8][5] << " | " << YourArea[8][6] << " | " << YourArea[8][7] << " | " << YourArea[8][8] << " | " << YourArea[8][9] << " |" <<'\n';
    std::cout <<"   ------------------------------------------" <<'\n';
    std::cout <<"  J | " << YourArea[9][0] << " | " << YourArea[9][1] << " | " << YourArea[9][2] << " | " << YourArea[9][3] << " | " << YourArea[9][4]<< " | " << YourArea[9][5] << " | " << YourArea[9][6] << " | " << YourArea[9][7] << " | " << YourArea[9][8] << " | " << YourArea[9][9] << " |" <<'\n';
    std::cout <<"   ------------------------------------------" <<'\n';
    std::cout << "                                     " <<'\n';
}

void GridEnemy(char GRID[10][10],char EnemyArea[10][10]){


    std::cout <<"COMPUTER"<< '\n';
    std::cout <<"   ------------------------------------------" <<'\n';
    std::cout <<"    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10|" <<'\n';
    std::cout <<"   ------------------------------------------" <<'\n';
    std::cout <<"  A | " << GRID[0][0] << " | " << GRID[0][1] << " | " << GRID[0][2] << " | " << GRID[0][3] << " | " << GRID[0][4] << " | " << GRID[0][5] << " | " << GRID[0][6] << " | " << GRID[0][7] << " | " << GRID[0][8] << " | " << GRID[0][9] << " |" <<'\n';
    std::cout <<"   ------------------------------------------" <<'\n';
    std::cout <<"  B | " << GRID[1][0] << " | " << GRID[1][1] << " | " << GRID[1][2] << " | " << GRID[1][3] << " | " << GRID[1][4] << " | " << GRID[1][5] << " | " << GRID[1][6] << " | " << GRID[1][7] << " | " << GRID[1][8] << " | " << GRID[1][9] << " |" <<'\n';
    std::cout <<"   ------------------------------------------" <<'\n';
    std::cout <<"  C | " << GRID[2][0] << " | " << GRID[2][1] << " | " << GRID[2][2] << " | " << GRID[2][3] << " | " << GRID[2][4] << " | " << GRID[2][5] << " | " << GRID[2][6] << " | " << GRID[2][7] << " | " << GRID[2][8] << " | " << GRID[2][9] << " |" <<'\n';
    std::cout <<"   ------------------------------------------" <<'\n';
    std::cout <<"  D | " << GRID[3][0] << " | " << GRID[3][1] << " | " << GRID[3][2] << " | " << GRID[3][3] << " | " << GRID[3][4] << " | " << GRID[3][5] << " | " << GRID[3][6] << " | " << GRID[3][7] << " | " << GRID[3][8] << " | " << GRID[3][9] << " |" <<'\n';
    std::cout <<"   ------------------------------------------" <<'\n';
    std::cout <<"  E | " << GRID[4][0] << " | " << GRID[4][1] << " | " << GRID[4][2] << " | " << GRID[4][3] << " | " << GRID[4][4] << " | " << GRID[4][5] << " | " << GRID[4][6] << " | " << GRID[4][7] << " | " << GRID[4][8] << " | " << GRID[4][9] << " |" <<'\n';
    std::cout <<"   ------------------------------------------" <<'\n';
    std::cout <<"  F | " << GRID[5][0] << " | " << GRID[5][1] << " | " << GRID[5][2] << " | " << GRID[5][3] << " | " << GRID[5][4]<< " | " << GRID[5][5] << " | " << GRID[5][6] << " | " << GRID[5][7] << " | " << GRID[5][8] << " | " << GRID[5][9] << " |" <<'\n';
    std::cout <<"   ------------------------------------------" <<'\n';
    std::cout <<"  G | " << GRID[6][0] << " | " << GRID[6][1] << " | " << GRID[6][2] << " | " << GRID[6][3] << " | " << GRID[6][4]<< " | " << GRID[6][5] << " | " << GRID[6][6] << " | " << GRID[6][7] << " | " << GRID[6][8] << " | " << GRID[6][9] << " |" <<'\n';
    std::cout <<"   ------------------------------------------" <<'\n';
    std::cout <<"  H | " << GRID[7][0] << " | " << GRID[7][1] << " | " << GRID[7][2] << " | " << GRID[7][3] << " | " << GRID[7][4]<< " | " << GRID[7][5] << " | " << GRID[7][6] << " | " << GRID[7][7] << " | " << GRID[7][8] << " | " << GRID[7][9] << " |" <<'\n';
    std::cout <<"   ------------------------------------------" <<'\n';
    std::cout <<"  I | " << GRID[8][0] << " | " << GRID[8][1] << " | " << GRID[8][2] << " | " << GRID[8][3] << " | " << GRID[8][4]<< " | " << GRID[8][5] << " | " << GRID[8][6] << " | " << GRID[8][7] << " | " << GRID[8][8] << " | " << GRID[8][9] << " |" <<'\n';
    std::cout <<"   ------------------------------------------" <<'\n';
    std::cout <<"  J | " << GRID[9][0] << " | " << GRID[9][1] << " | " << GRID[9][2] << " | " << GRID[9][3] << " | " << GRID[9][4]<< " | " << GRID[9][5] << " | " << GRID[9][6] << " | " << GRID[9][7] << " | " << GRID[9][8] << " | " << GRID[9][9] << " |" <<'\n';
    std::cout <<"   ------------------------------------------" <<'\n';
    std::cout << "                                     " <<'\n';
}

void PlayerMove(char YourArea[10][10], char EnemyArea[10][10], char GRID[10][10], char player){
    int Row;
    int Collumn;

    do{
    std::cout << "Enter the row number you want to bomb : " << '\n';
    std::cin >> Row;
    Row--;
    std::cout << "Enter the collum you want to bomb : " << '\n';
    std::cin >> Collumn;
    Collumn--; 
    
    if(EnemyArea[Row][Collumn] == 'A' || EnemyArea[Row][Collumn] == 'B' || EnemyArea[Row][Collumn] == 'C' || EnemyArea[Row][Collumn] == 'D' || EnemyArea[Row][Collumn] == 'S'){
        GRID[Row][Collumn] = player;
        std::cout << "Direct hit !" << '\n';
    }
    else if(GRID[Row][Collumn] == 'X'){
        std::cout << "You already hit this part. " << '\n';
    }
    
    else if(EnemyArea[Row][Collumn] == '~'){
        std::cout << "Missed !" << '\n';
        GRID[Row][Collumn] = '#';
    } 

    else if(EnemyArea[Row][Collumn] == '#'){
        std::cout << "You already hit this place. " << '\n';
    }

    }while(Row > 10 || Row < 0 || Collumn > 10 || Collumn < 0);


}

void EnemyMove(char YourArea[10][10], char EnemyArea[10][10], char GRID[10][10], char computer){
        int Row = 0;
        int Collumn = 0;
        do{
        int Row = rand() % 10 ;
        int Collumn = rand() % 10 ;    
        }while(YourArea[Row][Collumn] == 'x' || YourArea[Row][Collumn] == '#');
        

        if(YourArea[Row][Collumn] == 'A' || YourArea[Row][Collumn] == 'B' || YourArea[Row][Collumn] == 'C' || YourArea[Row][Collumn] == 'D' || YourArea[Row][Collumn] == 'S'){
            YourArea[Row][Collumn] = computer;
        }

        else if(YourArea[Row][Collumn] == '~'){
            YourArea[Row][Collumn] = '#';
        }

        else if(YourArea[Row][Collumn] = '#'){
            YourArea[Row][Collumn] = '#';
        }

}

bool Winner(char YourArea[10][10], char EnemyArea[10][10], char GRID[10][10]){

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(EnemyArea[i][j] == 'A' || EnemyArea[i][j] == 'B' || EnemyArea[i][j] == 'C' || EnemyArea[i][j] == 'D'){
                return false;
            } 
        }
    }
    
    std::cout << "You won !" << '\n';
    return true;
}

bool Looser(char YourArea[10][10]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(YourArea[i][j] == 'A' && YourArea[i][j] == 'B' && YourArea[i][j] == 'C' && YourArea[i][j] == 'D'){
                return false;
            }
        }
    }
    std::cout << "DEFEATED" << '\n';
    return true;
}