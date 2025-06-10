#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void user_logic(int n, string& s) 
{
    string output{};
    
    for(int i = 0; i < n; i++)
    {
        char current = s[i];
        int current_difficulty = (current - 'a' + 1) % 5;
        
        // Find the correct position to insert current character
        int insert_pos = 0;
        
        for(int j = 0; j < output.size(); j++)
        {
            char existing = output[j];
            int existing_difficulty = (existing - 'a' + 1) % 5;
            
            // If current has higher difficulty, or same difficulty but comes later alphabetically
            if(current_difficulty > existing_difficulty || 
               (current_difficulty == existing_difficulty && current > existing))
            {
                insert_pos = j + 1;
            }
            else
            {
                break;
            }
        }
        
        // Insert character at the determined position
        output.insert(insert_pos, 1, current);
    }
    
    s = output;
}

int main() {
    int n;
    string s;
    
    cin >> n >> s;
    
    user_logic(n, s);
    
    cout << s << endl;
    
    return 0;
}
