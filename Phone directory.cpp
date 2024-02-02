Q.Phone directory
Link-->https://www.geeksforgeeks.org/problems/phone-directory4628/1
code-->
class Solution
{   
    public:
    
   class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    // Constructor initializes data and sets all children to null
    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    // Constructor initializes root node with empty character
    Trie() {
        root = new TrieNode('\0');
    }

    // Recursive function to insert a word into the Trie
    void insertUtil(TrieNode* root, string word) {
        // Base case: reach the end of the word
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // Calculate index of first character in the alphabet
        int index = word[0] - 'a';

        // Check if child node exists for the character
        TrieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            // Create a new child node
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursively insert the remaining characters
        insertUtil(child, word.substr(1));
    }
     void insertWord(string word) {
        insertUtil(root, word);
    }
    void printSuggestions(TrieNode * curr , vector<string>&temp , string prefix){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }
        for(char ch='a';ch<='z';ch++){
            TrieNode * next = curr->children[ch-'a'];
            if(next!=NULL){
                prefix.push_back(ch);
                printSuggestions(next , temp , prefix);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>> getsugesstions(string str){
        TrieNode * prev = root;
        vector<vector<string>> output;
        string prefix="";
        for(int i=0;i<str.length();i++){
            char lastchar= str[i];
            prefix.push_back(lastchar);
            
            
            TrieNode * curr =prev->children[lastchar-'a'];
            
            if(curr==NULL){
                break;
            }
            vector<string>temp;
            printSuggestions(curr , temp ,prefix);
            output.push_back(temp);
            temp.clear();
            prev=curr;
        }
        
        int remaining = str.size() - output.size();
        for (int i = 0; i < remaining; i++) {
            output.push_back({"0"});
        }

        return output;
        
    }
    };
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        Trie * t= new Trie();
        for(int i =0;i<n;i++){
            string str = contact[i];
            t->insertWord(str);
            
        }
        return t->getsugesstions(s);
    }
};

Expected Time Complexity: O(|s| * n * max|contact[i]|)
Expected Auxiliary Space: O(n * max|contact[i]|) 
