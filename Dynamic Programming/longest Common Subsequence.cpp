#include <bits/stdc++.h>



#define ll long long int
#define ull unsigned long long int

using namespace std;

#define MAX 1000
#define NIL 1

// Solving longest Common Subsequence problem using DP tabulation approach

void lcsString(long **ptr, long row, long column, string &temp){

	if(ptr[row][column] == 0)
		return ;

	else if((ptr[row][column] > ptr[row-1][column]) && (ptr[row][column] > ptr[row][column-1]) )
		lcsString(ptr, row - 1, column - 1,temp);

	else if((ptr[row][column] > ptr[row-1][column]) && (ptr[row][column] <= ptr[row][column-1]) )
		lcsString(ptr, row - 1, column,temp);

	else if((ptr[row][column] <= ptr[row-1][column]) && (ptr[row][column] > ptr[row][column-1]) )
			lcsString(ptr, row , column -1,temp);
	else
		lcsString(ptr, row -1, column,temp);

	temp += ptr[row][column];

}

/* LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. 
 * For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.
 */ 

long longestCommonSubsequenceCount(string A, string B, string &output){

	long lcs[A.length() +1][B.length() +1];

	// Initializing auxiliary row[0][] &column[][0] with 0


	for (long rowSize = 0; rowSize <= A.length() ; ++rowSize) {
		for (long columnSize = 0; columnSize <= B.length() ; ++columnSize) {

			if(rowSize == 0 || columnSize == 0)
				lcs[rowSize][columnSize] = 0;
            // Diagonal value
			else if(A[rowSize-1] == B[columnSize-1])
				lcs[rowSize][columnSize] = lcs[rowSize-1][columnSize-1] + 1;
            // Max of top value & left value
			else
				lcs[rowSize][columnSize] = max(lcs[rowSize-1][columnSize],lcs[rowSize][columnSize-1]);
		}
	}
//	lcsString(lcs, A.length(), B.length(), output);

	return lcs[A.length()][B.length()];
}





int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	string temp;

	cout << longestCommonSubsequenceCount("AGGTAB","GXTXAYB",temp) << temp;





    return 0;
}















