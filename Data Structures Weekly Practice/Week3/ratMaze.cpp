#include<iostream>
using namespace std;

//Find path in maze
/* C/C++ program to solve Rat in a Maze problem using 
   backtracking */
#include <stdio.h> 
  
// Maze size 
#define N 4 
  
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]); 
  
/* A utility function to print solution matrix sol[N][N] */
void printSolution(int sol[N][N]) 
{ 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) 
            printf(" %d ", sol[i][j]); 
        printf("\n"); 
    } 
} 
  
/* A utility function to check if x, y is valid index for N*N maze */
bool isSafe(int maze[N][N], int x, int y) 
{ 
    // if (x, y outside maze) return false 
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1) 
        return true; 
  
    return false; 
} 
  
/* This function solves the Maze problem using Backtracking.  It mainly 
   uses solveMazeUtil() to solve the problem. It returns false if no  
   path is possible, otherwise return true and prints the path in the 
   form of 1s. Please note that there may be more than one solutions,  
   this function prints one of the feasible solutions.*/
bool solveMaze(int maze[N][N]) 
{ 
    int sol[N][N] = { { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 } }; 
  
    if (solveMazeUtil(maze, 0, 0, sol) == false) { 
        printf("Solution doesn't exist"); 
        return false; 
    } 
  
    printSolution(sol); 
    return true; 
} 
  
/* A recursive utility function to solve Maze problem */
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) 
{ 
    // if (x, y is goal) return true 
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) { 
        sol[x][y] = 1; 
        return true; 
    } 
  
    // Check if maze[x][y] is valid 
    if (isSafe(maze, x, y) == true) { 
        // mark x, y as part of solution path 
        sol[x][y] = 1; 
  
        /* Move forward in x direction */
        if (solveMazeUtil(maze, x + 1, y, sol) == true) 
            return true; 
  
        /* If moving in x direction doesn't give solution then 
           Move down in y direction  */
        if (solveMazeUtil(maze, x, y + 1, sol) == true) 
            return true; 
  
        /* If none of the above movements work then BACKTRACK:  
            unmark x, y as part of solution path */
        sol[x][y] = 0; 
        return false; 
    } 
  
    return false; 
} 
  
// driver program to test above function 
int main() 
{ 
    int maze[N][N] = { { 1, 0, 0, 0 }, 
                       { 1, 1, 0, 1 }, 
                       { 0, 1, 0, 0 }, 
                       { 1, 1, 1, 1 } }; 
  
    solveMaze(maze); 
    return 0; 
} 

/*

// Find number of ways of path
#define R 4 
#define C 4 
  
// Returns count of possible paths in a maze[R][C] 
// from (0,0) to (R-1,C-1) 
int countPaths(int maze[][C]) 
{ 
    // If the initial cell is blocked, there is no 
    // way of moving anywhere 
    if (maze[0][0]==-1) 
        return 0; 
  
    // Initializing the leftmost column 
    for (int i=0; i<R; i++) 
    { 
        if (maze[i][0] == 0) 
            maze[i][0] = 1; 
  
        // If we encounter a blocked cell in leftmost 
        // row, there is no way of visiting any cell 
        // directly below it. 
        else
            break; 
    } 
  
    // Similarly initialize the topmost row 
    for (int i=1; i<C; i++) 
    { 
        if (maze[0][i] == 0) 
            maze[0][i] = 1; 
  
        // If we encounter a blocked cell in bottommost 
        // row, there is no way of visiting any cell 
        // directly below it. 
        else
            break; 
    } 
  
    // The only difference is that if a cell is -1, 
    // simply ignore it else recursively compute 
    // count value maze[i][j] 
    for (int i=1; i<R; i++) 
    { 
        for (int j=1; j<C; j++) 
        { 
            // If blockage is found, ignore this cell  
            if (maze[i][j] == -1) 
                continue; 
  
            // If we can reach maze[i][j] from maze[i-1][j] 
            // then increment count. 
            if (maze[i-1][j] > 0) 
                maze[i][j] = (maze[i][j] + maze[i-1][j]); 
  
            // If we can reach maze[i][j] from maze[i][j-1] 
            // then increment count. 
            if (maze[i][j-1] > 0) 
                maze[i][j] = (maze[i][j] + maze[i][j-1]); 
        } 
    } 
  
    // If the final cell is blocked, output 0, otherwise 
    // the answer 
    return (maze[R-1][C-1] > 0)? maze[R-1][C-1] : 0; 
} 
  
// Driver code 
int main() 
{ 
    int maze[R][C] =  {{0,  0, 0, 0}, 
                       {0, -1, 0, 0}, 
                       {-1, 0, 0, 0}, 
                       {0,  0, 0, 0}}; 
    cout << countPaths(maze); 
    return 0; 
}

*/
