


/*  GIVEN A 2D ARRAY M*N  PRINT OR RETURN A VECTOR WITH VALUES IN SPIRAL*/
vector<int> spiralOrder(const vector<vector<int> > &A) {        //vector can be passed as a reference and inside function will access normally as A


    vector<int> result;

    int m = A.size();               // VECTOR.SIZE()  RETURNS NUMBER OF ROWS
    int n = A[0].size();            // VECTOR[0].SIZE() RETURNS NUMBER OF COLUMNS
    int t=0, b=m-1, l=0, r = n-1;
    int dir =0;
    //dir =0 is left to right
    //dir = 1 is top to bottom
    //dir =2 is right to left
    //dir = 3 is bottom to top


    // t -------------------
    //   -------------------
    //   -------------------
    // b -------------------
    //   l                 r


    while(t<=b&&l<=r){

        if (dir==0){
            for(int i = l; i<=r; i++){          // going l to r along 't'th row
                result.push_back(A[t][i]);
            }
            t++;
        }
        else if (dir==1){
            for(int i = t; i<=b; i++){          // going t to b along 'r'th column
                result.push_back(A[i][r]);
            }
            r--;
        }
        else if (dir==2){
            for(int i = r; i>=l; i--){          // going r to l along 'b'th row
                result.push_back(A[b][i]);
            }
            b--;
        }
        else if (dir==2){
            for(int i = b; i>=t; i--){          // going b to t along 'l'th column
                result.push_back(A[i][l]);
            }
            l++;
        }

        dir = (dir+1)%4;                        // updating dir in each iteration
    }

    return result;

}


/* PROGRAM FOR RESIZING THE NEW VECTOR B TO THAT OF ORIGINAL VECTOR A */
/* NOTE THAT VECTOR A MIGHT HAVE EACH ROW WITH DIFFIRENT COLUMN */
/* HENCE WE FIND COLUMN BY VECTOR[i].SIZE*/

vector<vector<int> > ResizingVector(vector<vector<int> > &A) {
    vector<vector<int> > B;
    B.resize(A.size());                         //RESIZE THE NUMBER OF ROWS
    for (int i = 0; i < A.size(); i++) {
        B[i].resize(A[i].size());               //RESIZING NUMBER OF COLUMNS/ELEMENTS IN EACH ROW
        }
    return B;
}

/* PROGRAM FOR RESIZING THE NEW VECTOR B TO THAT OF ORIGINAL VECTOR A AND REVERSING ELEMENTS OF EACH ROW*/

vector<vector<int> > performOps(vector<vector<int> > &A) {
    vector<vector<int> > B;
    B.resize(A.size());
    for (int i = 0; i < A.size(); i++) {
        B[i].resize(A[i].size());
        for (int j = 0; j < A[i].size(); j++) {
            B[i][A[i].size() - 1 - j] = A[i][j];
        }
    }
    return B;
}


/* ROTATE ARRAY BY B COUNTS*/
vector<int> Solution::rotateArray(vector<int> &A, int B) {
    vector<int> ret;
    for (int i = 0; i < A.size(); i++) {
        ret.push_back(A[(i + B)%A.size()]);
    }
    return ret;
}





vector<int> performOps(vector<int> A) {
    vector<int> B(2 * A.size(), 0);
    for (int i = 0; i < A.size(); i++) {
        B[i] = A[i];
        B[i + A.size()] = A[(A.size() - i) % A.size()];
    }
    return B;
}


/* Do NOT REFER*/
int maxSubArray(const vector<int> &A) {
    int n = A.size();

    if (n==1) return A[0];

    int m = n/2;
    vector<int> B(m);
    vector<int> C(n-m);

    for(int i =0;i<m;i++){
        B[i]=A[i];
    }

    for(int i=m;i<n;i++){
        C[i]=A[i];
    }

    int left_MaxSubarrSum = maxSubArray(B);
    int right_MaxSubarrSum = maxSubArray(C);

    int left_sum = INT_MIN, right_sum = INT_MIN, sum=0;

    for(int i =0;i<m;i++){
        sum += B[i];
        left_sum = max(sum,left_sum);
    }

    sum =0;
    for(int i=m;i<n;i++){
        sum +=C[i];
        right_sum = max(sum, right_sum);
    }
    int ans = max(left_MaxSubarrSum, right_MaxSubarrSum);
    return max(left_sum+right_sum,ans);
}

/* MAX SUM OF CONTAGIOUS SUB ARRAY*/

int Solution::maxSubArray(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int maxsum = A[0] , cursum = A[0] ;
    for(int i=1;i<A.size();i++)
    {
        cursum = max(cursum+A[i],A[i]);     // STORES MAXIMUM WITH CURRENT ELEMENT
        maxsum = max(maxsum,cursum);        // STORES MAXIMUM SUM UNTIL NOW THAT COULD OR COULD NOT INCLUDE LATEST ELEMENT
    }
    return maxsum ;
}

/* Adding 1 to a number formed by elements of array [0,1,2,3]-->[0,1,2,4]  [9,9,9]-->[1,0,0,0]*/

vector<int> Solution::plusOne(vector<int> &A) {
    vector<int> B;

    int index=-1;
    for(int i=0; i<A.size();i++)        // check for leading zeros
    {
        if (A[i]==0)
        {
            index = i;
        }
        else
        {
            break;
        }
    }

    if (index!=(-1))
    {
        A.erase(A.begin(),A.begin()+index);     //removing leading zeros
    }

    B.resize(A.size());
    int m=0,cry=0;
    for(int i=A.size()-1; i>=0; i--)
    {
        if (i == A.size()-1){           //TAKES CARE OF INCREMENTING LAST ELEMENT BY 1
        m=A[i]+1+cry;
        if (m > 9)                      // CHECK FOR CARRY
        {
            B[i]=m%10;
            cry=m/10;
        }
        else                            // IF NO CARRY
        {
            B[i]=m;
            cry=0;
        }
        }
        else                            // FOR ELEMENTS OTHER THAN LAST ELEMENT
        {
            m=A[i]+cry;
        if (m > 9)
        {
            B[i]=m%10;
            cry=m/10;
        }
        else
        {
            B[i]=m;
            cry=0;
        }

        }

    }

    if (B[0]==0&&cry!=0)
    {
        B.emplace(B.begin(),cry);

    }
    else if(B[0]==0)
    {
        B.erase(B.begin());
    }


    return B;
}

/* PASCAL TRIANGLE*/

vector<vector<int> > Solution::generate(int A) {



    vector<vector<int>> PasTrg;
    PasTrg.resize(A);

    for(int i=0;i<A;i++)
    {
        PasTrg[i].resize(i+1);
    }
    if (A==0) return PasTrg;


    PasTrg[0][0] = 1;

    for(int i=1;i<A;i++)                        // ITERATOR FOR ROWS
    {
        for(int j=0;j<=i;j++)                   // ITERATOR FOR COLUMNS FROM 0 TO i
        {
            if((j==0)||(j==i))                  // CASES FOR 1
            {
                PasTrg[i][j]=1;

            }
            else                                // INBETWEEN CASES
            {
                PasTrg[i][j]=PasTrg[i-1][j]+PasTrg[i-1][j-1];

            }

        }
    }
    return PasTrg;

}


/*SORTING ARRAY IN WAVE LIKE MANNER*/
/* HIGH LOW HIGH LOW  HIGH LOW ....*/   /*  LOW = VALUE MUST BE LOWERE THAN EITHER NEIGHBOR VALUES*/
/*  TRICK SWAPPING i & i+1 values*/


vector<int> Solution::wave(vector<int> &A) {

    sort(A.begin(), A.end());

    int m,n;
    for(int i=0;i<A.size();i=i+2)
    {
        if(i<A.size()-1)
        {
            m=A[i];
            n=A[i+1];
            A[i]=n;
            A[i+1]=m;


        }
    }
    return A;
}

/* SPIRAL FILLING of MATRIX*/

vector<vector<int> > Solution::prettyPrint(int A) {

    int n = 2*A-1;
    vector<vector<int>> result;

    result.resize(n);

    for(int i=0; i<n;i++)
    {
        result[i].resize(n);
    }

    int l=0,t=0,r=n-1,b=n-1;
    int dir=0;

    while (t<=b&&l<=r)
    {
        if(dir==0)
        {
            for(int i=l; i<=r;  i++)
            {
                result[t][i]= A;
            }
            t++;
        }
        else if(dir==1)
        {
            for(int i=t; i<=b;  i++)
            {
                result[i][r]= A;
            }
            r--;
        }
        else if (dir==2)
        {
            for(int i=r; i>=l;  i--)
            {
                result[b][i]= A;
            }
            b--;

        }
        else if(dir==3)
        {
            for(int i=b; i>=t;  i--)
            {
                result[i][l]= A;
            }
            l++;
            A=A-1;

        }

        dir = (dir+1)%4;
    }

    return result;
}

//--------------Square Root of number efficient than babylon

int Solution::sqrt(int A) {
            int x= A;
            if (x == 0) return 0;
            int start = 1, end = x, ans;
            while (start <= end) {
                int mid = (start + end) / 2;
                if (mid <= x / mid) {
                    start = mid + 1;
                    ans = mid;
                } else {
                    end = mid - 1;
                }
            }
            return ans;
}

//---------------Babylon Method

int Solution::sqrt(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    float x = A, y=1,e=0.00001;

    while((x-y)>e)
    {
        x=(x+y)/2;
        y=A/x;
    }

    return x;
}

//-------------------BINARY SEARCH 1D ARRAY
int searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified


    int start_index  = 0;
    int end_index = A.size()-1;

    int mid;

    //if(B>=A[end_index]) return end_index+1;

    while (start_index <= end_index){
        mid = (start_index+end_index)/2;                    // UPDATING THE MID INDEX
        if(B == A[mid]) return mid;
        else if(B>A[mid])                                   // VALUE IN RIGHT HALF
        {
            start_index = mid + 1;                          // INCREMENT START TO MID+1 i>e START OF SECOND HALF
        }
        else                                                // VALUE IN LEFT HALF
        {
            end_index = mid - 1;                            // DECREMENT END TO MID-1 i.e. END OF LEFT HALF
        }
    }
    return end_index+1;                                     // to return possible location of missing element
}



//----------------------BINARY SEARCH 2D ARRAY m*n
int searchMatrix(vector<vector<int> > &A, int B) {
   int m=A.size();
   int n=A[0].size();
   int l=0,r=m-1,mid;
   if(B<A[0][0]||B>A[m-1][n-1]) return 0;
   while(l<=r){
    mid=l+(r-l)/2;
    if(B==A[mid][0]) return 1;
    else if(B>A[mid][0]) l=mid+1;
    else
      r=mid-1;
   }
   l=0;
   int searchrow=r;
   r=n-1;
   while(l<=r){
       mid=l+(r-l)/2;
       if(A[searchrow][mid]==B) return 1;
       else if(A[searchrow][mid]<B) l=mid+1;
       else
         r=mid-1;
   }
   return 0;
}

