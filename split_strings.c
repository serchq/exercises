/*
Objective
Today we will expand our knowledge of strings, combining it with what we have already learned about loops. 
Check out the Tutorial tab for learning materials and an instructional video.

Task
Given a string, S, of length N that is indexed from 0 to N-1, print its even-indexed and odd-indexed characters 
as 2 space-separated strings on a single line (see the Sample below for more detail).

Note: 0 is considered to be an even index.

Example
s = adbecf

Print abc def

Input Format
The first line contains an integer, T (the number of test cases).
Each line i of the T  subsequent lines contain a string, S.

Constraints
- 1 <= T <= 10
- 2 <= length of S <= 10000

Output Format
For each String Sj (where 0<= j <= T-1), print Sj's even-indexed characters, followed by a space, 
followed by Sj's odd-indexed characters.

Sample Input
2
Hacker
Rank
Sample Output

Hce akr
Rn ak

Explanation

Test Case 0: S = "Hacker"
S[0] = "H"
S[1] = "a"
S[2] = "c"
S[3] = "k"
S[4] = "e"
S[5] = "r"

The even indices are 0, 2, and 4, and the odd indices are 1, 3, and 5. We then print a single line 
of 2 space-separated strings; the first string contains the ordered characters from S's even indices 
(Hce), and the second string contains the ordered characters from S's odd indices (akr).

Test Case 1: S = "Rank"
S[0] = "R"
S[1] = "a"
S[2] = "n"
S[3] = "k"

The even indices are 0 and 2, and the odd indices are 1 and 3. We then print a single line of 2 space-separated 
strings; the first string contains the ordered characters from S's even indices (Rn), and the second string 
contains the ordered characters from S's odd indices (ak).
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


#define MAX_SIZE 10000

void splitString(char *s){
    // char left[MAX_SIZE/2];
    // char right[MAX_SIZE/2];
    int stringSize = strlen(s);
    char *left = calloc(stringSize/2, sizeof(char));
    char *right = calloc(stringSize/2, sizeof(char));
    
    int lptr = 0, rptr = 0;
    
    for (int j = 0; j < stringSize; j++){
        if (j % 2 == 0){
            left[lptr] = s[j];        
            lptr++;
        } else {
            right[rptr] = s[j];
            rptr++;
        }
    }
    left[lptr] = '\0';
    right[rptr] = '\0';
    
    printf("%s %s\n",left, right);
    
    // free(left);
    // free(right);
}


int main(){
    char s[MAX_SIZE] = {"jkotzxzxrxtzytlruwrxytyzsuzytwyzxuzytryzuzysxvsmupouysywywqlhg"};
    
    splitString(s);
    
}



// int main() {

//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
//     int n;
//     scanf("%d", &n);
//     getchar();
    
//     for (int i = 0; i < n; i++){
//         char s[MAX_SIZE];
//         scanf("%[^\n]%*c", &s);
//         splitString(s);
//     }

    
//     return 0;
// }



/*
10
jkotzxzxrxtzytlruwrxytyzsuzytwyzxuzytryzuzysxvsmupouysywywqlhg
eklrywzvpxtvoptlrskmskszvwzsuzxrtvyzwruqvyxusqwupnurqmtltnltsmuyxqoksyurpwqpv
efhpuvqvnuwpvwysvnunostvpqvxtxsvqwqvsxtxvqpvtsonunvsywvpwunvqvupxzy
otytmpszumnryqvxpvnvxyvpvprumnvsqwqwtsqyqksqvnuqpxszwzsxsx
bhmptlqswsvoqsvzyzwoqtvowpyqxpwurpxutswtrpwzvrpkswzuo
rvovprxzvwrxpwpzsltzutxztrxqxt
ceiosyrtztvnqsuozrxvtqywqwyrxtnjh
djnsyzxszryqworuxpqvqwquvotzsqvoupwvztzupowtqnvpxqyrwutzuys
kovzuywsuvwxuxtwzryzuxyvouvyskoqtwryszxqqxzsyrwtqoksyvuovyxuzyrzwtxuxwvuswuqvryu
ptvzstvotxqyvzrwyqryzrpkswzryupwutmigc


jozzrtyluryysztyxztyuyxsuoyyyqh ktxxxztrwxtzuywzuyrzzsvmpuswwlg
elyzptotrkssvzuxtywuvxswpuqttlsuxosupqv krwvxvplsmkzwszrvzrqyuqunrmlntmyqkyrwp
ehuqnwvyvuotpvtsqqstvptouvyvwnquxy fpvvupwsnnsvqxxvwvxxqvsnnswpuvvpz
oymsunyvpnxvvrmvqqtqqsvupswss ttpzmrqxvvyppunswwsykqnqxzzxx
bmtqwvqvywqvwyxwrxtwrwvpszo hplssoszzotopqpupustpzrkwu
ropxvrppstuxtxx vvrzwxwzlztzrqt
cisrzvquzxtyqyxnh eoyttnsorvqwwrtj
dnyxzywrxqqqvtsvuwzzpwqvxywtus jszsrqoupvwuozqopvtuotnpqruzy
kvuwuwutzyuyovsotrsxqzywqkyuvxzrwxxvsuvy ozysvxxwrzxvuykqwyzqxsrtosvoyuyztuwuwqru

*/