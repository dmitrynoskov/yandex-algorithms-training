#include <iostream>
#include <string>

using namespace std;

string solve(int a, int b, int c) {
     if (c < 0) {
       return "NO SOLUTION\n";    
   } else if (a == 0) {
       if (b == c * c) {
           return "MANY SOLUTIONS\n";
       } else {
           return "NO SOLUTION\n"; 
       }
   } else {
       if (!((c * c - b) % a)) {
            return to_string((c * c - b) / a);    
       } else {
           return "NO SOLUTION\n";
       }
   }

}

int main() {  
    int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c);
    return 0;
}