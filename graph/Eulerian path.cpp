class Solution {
  //An undirected graph has an Eulerian trail if and only if exactly zero or two vertices have odd degree,
  //and if all of its vertices with nonzero degree belong to a single connected component.
public:
  bool WordsCanRange(int n,vector<string> words){
    if(n<=0 || words.empty()) return false;
    // edge is a 2-D array.
    int edge[26][26] = {0};
    int inDegree[26] = {0};
    int outDegree[26] = {0};
    bool visited[26] = {0};
    
    while(n>0){
      inDegree[words[n-1][0]-'a']++;
      outDegree[words[n-1].back()-'a']++;
      edge[words[n-1][0]-'a'][words[n-1].back()-'a'] = 1;
      n--;
    }
    
    bool headFind = false;
    bool tailFind = false;
    bool wordsCanRange = true;
    if(isConnected(edge,visited)) {
      for(int i=0;i<26;i++){
        if(inDegree[i] > 0 || outDegree[i] > 0){
          if(headFind == false && outDegree[i]-inDegree[i]==1)
            headFind = true;
          else if(tailFind == false && outDegree[i]-inDegree[i]==-1)
            tailFind = true;
          else if (outDegree[i] == inDegree[i])
            continue;
          else
            wordsCanRange = false;
        }
      } else
        wordsCanRange = false;
      return wordsCanRange;
    }
  }
private:
  bool isConnected(int& edge[][26],bool& visited[]){
    int connection_count=0;
    for(int i=0;i<26;i++){
      for(int j=0;j<26;j++){
        if(edge[i][j] == 1 && visited[i] == false) {
          dfs(i,edge,visited);
          connection_count++;
        }
      }
    }
  }
  void dfs(int i,int& edge[][26],bool& visited[]){
    visited[i] = true;
    for(int j=0;j<26;j++){
      if(visited[j] == false && edge[i][j] == 1)
        dfs(j,edge,visited);
      if(visited[j] == false && edge[j][i] == 1)
        dfs(j,edge,visited);
    }
    return;
  }
}
