#include "RecurDynamic.h"

/*-------------FIBONACCI--------------------------*/
int fibonacci(int i)
{
    if (i == 0)
        return 0;
    if (i == 1)
        return 1;

    return fibonacci(i - 1) + fibonacci(i - 2);
}
/*___________________________________________________________________*/


/*----------------TRIPLE STEP --------------------*/

/*-----------Description-----------------------*/
// As a very last step child can go 1step or 2step or 3 step
// If last step was 1 step then it will again have 3
// possibilities for remaining steps 1,2,3. so it continues
// recursively

int countWays(int n)
{
    if (n < 0)
        return 0;
    else if (n == 0)
        return 1;
    else
    {
        return countWays(n - 1) + countWays(n - 2) + countWays(n - 3);
    }
}
/*___________________________________________________________________*/




/*--------------------ROBOT IN A GRID--------------------------------*/


//-----------------Utility function----------------------------------

 vector<vector<bool>> createGirdMaze(int size, bool test)
{
    vector<vector<bool>> myMaze(size, vector<bool>(size));
    for (int i = 0; i < myMaze.size(); i++)
    {
        for (int j = 0; j < myMaze[0].size(); j++)
        {
            if (j == 0)
                myMaze[i][j] = 1;
            else if (i == 4)
                myMaze[i][j] = 1;
            else
                myMaze[i][j] = 0;
        }
    }


    if (test == true)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << "(" << i << "," << j << ") : " << myMaze[i][j] << " | ";
            }
            cout << endl;
        }
    }

    return myMaze;
   
}

bool getPath(vector<vector<bool>> maze,int row, int col, vector<pair<int, int>> &path)
{
    if((row<0)||(col<0)||(!maze[row][col]))         // CHECK for invalid row OR invalid col OR OBSTACLE(invalid place)
    {
        return false;
    }

    bool isAtOrigin = (row == 0) && (col == 0);

    if ((isAtOrigin)||
        (getPath(maze, row, col-1, path))||         //check for left place for right movement
        (getPath(maze, row-1, col, path)))          //check for upward place for downward movement
        {
            
            path.emplace_back(make_pair(row,col));
            return true;
        }

    return false;

}


vector<pair<int,int>> getPath (vector<vector<bool>> maze)
{
    vector<pair<int, int>> path;                //= new vector<pair<int, int>> ()

    if ( (maze.empty()) || (maze.size()==0) )
    {
        return path;
    }

    

    if (getPath(maze,maze.size()-1, maze[0].size()-1, path))
    {
        return path;
    }

    return path;


}

/*___________________________________________________________________*/



/*-----------------Magic Number-------------------------------------*/

int findMagicFast(vector<int>  &array, int start, int end)
{
    if(start>end) return -1;
    int mid = ( start + end )/2;
    
    if (mid == array[mid]) return mid;
    else if (mid < array[mid]) return findMagicFast(array, start, mid-1);
    else return findMagicFast(array, mid+1, end);

}

int findMagicFast(vector<int> &array)
{
    cout<< array.size()<<endl;
    return findMagicFast (array, 0, array.size()-1);
}




/*___________________________________________________________________*/
