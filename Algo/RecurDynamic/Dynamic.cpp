#include "RecurDynamic.h"

/*-------------FIBONACCI--------------------------*/
int fibonacciDyn(int i, int memo[])
{
    if (i == 0 || i == 1)
        return i;

    if (memo[i] == 0)
    {
        memo[i] = fibonacciDyn(i - 1, memo) + fibonacciDyn(i - 2, memo);
    }
    return memo[i];
}

int fibonacciDyn(int n)
{
    return fibonacciDyn(n, new int[n + 1]());
}
/*___________________________________________________________________*/

/*----------------TRIPLE STEP -----------------*/
// Very last step child can go 1step or 2step or 3 step
// If last step was 1 step then it will again have 3
// possibilities for remaining steps 1,2,3. so it continues
// recursively

int CountWaysDyn(int i, int memo[])
{
    if (i < 0)
        return 0;
    else if (i == 0)
        return 1;
    else
    {
        if (memo[i] == 0)
        {
            memo[i] = CountWaysDyn(i - 1, memo) + CountWaysDyn(i - 2, memo) + CountWaysDyn(i - 3, memo);
        }
        return memo[i];
    }
}

int CountWaysDyn(int n)
{
    return CountWaysDyn(n, new int[n + 1]());
}

/*___________________________________________________________________*/