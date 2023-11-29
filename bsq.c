#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dir[3][2] = {{1,0},{0,1},{1,1}};//,{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};


int* checkmate(char** pointer, int fila, int columna)
{
    int* current = (int*)malloc(2 * sizeof(int));
    current[0] = fila;
    current[1] = columna;

    int r;

    r = 0;
    if(pointer[fila][columna] == 'o')
    {
        return current;
    }else
    {
        
        while(r <= 2)
        {
            fila = fila+dir[r][0];
            columna = columna+dir[r][1];

            if((fila < 9 || fila >= 0) && (columna  < 28 || columna >= 0))
            {
                pointer[fila][columna] = 'v';
                checkmate(pointer,fila,columna);
            }
            r++;
        }
    }
    return current;
}

void BSQ(char** map)
{
    int i;
    int j;
    int coord1;
    int coord2;
    int** result = (int**)malloc(2 * sizeof(int*));
    for(i = 0; i < 2; i++)
        result[i] = (int*)malloc(2 * sizeof(int));
    int* aux = (int*)malloc(2 * sizeof(int));


    i = 0;
    j = 0;

    //Change for rows
    while( i <= 9)
    {
        j = 0;
        while( j <= 28)
        {
            if(map[i][j] != 'o')
            {
                int* temp = checkmate(map,i,j);
                memcpy(aux, temp, sizeof(int)*2);
                free(temp);
            }
            coord1 = result[0][0] - result[1][0] * result[0][1] - result[1][1];
            coord2 = i - aux[0] * j - aux[1];
            if(coord2 > coord1)
            {
                result[0][0] = i;
                result[0][1] = j;
                memcpy(result[1], aux, sizeof(int)*2);
            }
        }
    }

    printf("%d | %d || %d | %d", result[0][0],result[0][1],result[1][0],result[1][1]);
    for(i = 0; i < 2; i++)
        free(result[i]);
    free(result);
    free(aux);
}


 int main()
{
    char** map = (char**)malloc(9 * sizeof(char*));
    for(int i = 0; i < 9; i++)
        map[i] = (char*)malloc(28 * sizeof(char));
    char* temp_map[9] = 
    {"...........................",
    "....o......................",
    "............o..............",
    "...........................",
    "....o......................",
    "...............o...........",
    "...........................",
    "......o..............o.....",
    "..o.......o................"};

    for(int i = 0; i < 9; i++)
        strcpy(map[i], temp_map[i]);

    BSQ(map);




}


/*main(){
    array
    size = 9
    int i = 0
    while (i < size){
        if (search_square(array, size-i, 0, 0,0) == 1){
            break
        }
        i+=1
    }

}



int search_square(array, size, curr_size, x ,y){
    if (x == strlen(array[0])){
        return 0
    }
    if (y == 9){
        return search_square(array, size, 0, x+1 ,0)
    }
    int i = 0
    while (i < size){
        if array[x+i][y] == "o":
            return search_square(array, size, 0, x ,y+1)

        i++;
    }
    if (size == curr_size + 1){
        return draw_solution(array,x,y, size)
    }else{
        return search_square(array, size, curr_size+1, x ,y+1)
    }

}

draw_solution(array, x , y){
    int i = 0;
    int j = 0;
    while (i < size):
        while (j < size):
            array[x-i][y+j] = "x"
            j+=1
        i+=1
    return 1
}*/