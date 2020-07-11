#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const int Directions[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int num_islands(char** grid, int num_rows, int num_cols);

/* Helper functions */
void display_char_array(char ** grid, int num_rows);
int ** create_int_array(int num_rows, int num_cols, int value);
void destroy_int_array(int ** grid, int num_rows);
void display_int_array(int ** grid, int num_rows, int num_cols);


void main()
{
printf("Grid 1:\n");
char ** grid1 = (char **) malloc(4*sizeof(char *));
grid1[0]  = "11110";
grid1[1]  = "11010";
grid1[2]  = "11000";
grid1[3]  = "00000";
display_char_array(grid1, 4);
printf("Number of islands = %d\n\n", num_islands(grid1,4,5));


printf("Grid 2:\n");
char ** grid2 = (char **) malloc(4*sizeof(char *));
grid2[0]  = "11000";
grid2[1]  = "11000";
grid2[2]  = "00100";
grid2[3]  = "00011";
display_char_array(grid2, 4);
printf("Number of islands = %d\n\n", num_islands(grid2,4,5));


printf("Grid 3:\n");
char ** grid3 = (char **) malloc(8*sizeof(char *));
grid3[0]  = "11000000";
grid3[1]  = "11000011";
grid3[2]  = "00111001";
grid3[3]  = "00001000";
grid3[4]  = "00011100";
grid3[5]  = "01100010";
grid3[6]  = "01101111";
grid3[7]  = "10000100";
display_char_array(grid3, 8);
printf("Number of islands = %d\n\n", num_islands(grid3,8,8));

}

bool range(int r, int c, int num_rows, int num_cols){
    return r >= 0 && r < num_rows && c >= 0 && c < num_cols;
}

void move(char** grid, bool** visited, int num_rows, int num_cols, int r, int c){
    if(!range(r, c, num_rows, num_cols)) 
    return;
    
    if(visited[r][c]) 
    return;
    
    if(grid[r][c] == '0') 
    return;
    
    visited[r][c] = 1;
    
    for(int i = 0; i < 4; i++){
        int r0 = r+Directions[i][0];
        int c0 = c+Directions[i][1];
        move(grid, visited, num_rows, num_cols, r0, c0);
    }
}

int num_islands(char** grid, int num_rows, int num_cols){
    
    bool** visited = (bool**)malloc(sizeof(bool*)*num_rows);
    
    for(int r = 0; r < num_rows; r++){
        visited[r] = (bool*)malloc(sizeof(bool)*num_cols);
        memset(visited[r], 0, sizeof(bool)*num_cols);
    }
    
    int count = 0;
    for(int r = 0; r < num_rows; r++){
        for(int c = 0; c < num_cols; c++){
            if(grid[r][c] == '1' && !visited[r][c]){
                move(grid, visited, num_rows, num_cols, r, c);
                count++;
            }
        }
    }
    return count;
}


void display_char_array(char ** grid, int num_rows)
{
for (int k=0; k<num_rows; k++) {
    printf("%s\n", grid[k]);
}
}

