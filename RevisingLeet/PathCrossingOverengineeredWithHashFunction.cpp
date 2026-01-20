class Solution {
public:
//We making our own hashing function before gta 6 now crazy
//Overengineered piece of code for easy problem Loma death
struct PairHash{
    size_t operator()(const pair<int,int >& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};
    bool isPathCrossing(string path) {
      unordered_set<pair<int,int> , PairHash> visited;
      int x = 0, y = 0;
      visited.insert({0,0});
      
      for(char c: path)
      {
        if(c == 'N') y++;
        else if(c == 'S') y--;
        else if(c == 'E') x++;
        else if(c == 'W') x--;

        if(!visited.insert({x,y}).second)
            return true;
      }
    return false;
    }
};
