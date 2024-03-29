class Solution {
private:
    map<string, int> cnt;
    
    struct Node {
        string data;
        string directory;
        map<string, Node*> next;
        Node(string value) {
            data = value;
            directory = "";
        }
    };
    
    void make_directory(Node* root, vector<vector<string>> &ans, vector<string> &path) {
        if(root == NULL)
            return;
        else if(root->directory == "X")
            return;
        path.push_back(root->data);
        ans.push_back(vector<string>(path));
        for(auto it: root->next) {
            if(it.second->directory != "X") {
                make_directory(it.second, ans, path);
                path.pop_back();
            }
        } 
    }
    
    void remove_duplicates(Node* root) {
        if(root == NULL) 
            return;
        if(cnt[root->directory] > 1) {
            // value X determines it wouldn't be included
           // cout << cnt[root->directory] << "-" << root->directory << endl;
            root->directory = "X";
        }
        for(auto it: root->next) {
            remove_duplicates(it.second);
        }
    }
    
    string mark_duplicates(Node* root) {
        if(root == NULL)
            return "X";
        string directory = "";
        for(auto it: root->next) {
            directory = directory + mark_duplicates(it.second);
			// note: used ordered map
            // why this line is added?? see the given testcase
            directory += "/";
        }
        root->directory = directory;
        if(directory.length() > 0)
            cnt[directory] += 1;
        return root->data + "/" + directory;
    }
    
    void create_tree(Node* root, vector<string> &path) {
        Node* curr = root;
        for(string name: path) {
            Node* node = curr->next[name];
            if(node == NULL) {
                node = new Node(name);
                curr->next[name] = node;
            }
            curr = node;
        }
    }
    
    
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = new Node("/");
        for(vector<string> path: paths)
            create_tree(root, path);
        
        mark_duplicates(root);
        remove_duplicates(root);
        
        vector<vector<string>> ans;
        vector<string> path;
        for(auto it: root->next) {
            make_directory(it.second, ans, path);
            path.clear();
        }
        
        return ans;
    }
    
    // ambiguity of this testcase while using ordered map
    // [["a"],["a","c"],["a","d"],["a","d","e"],["b"],["b","e"],["b","c"],["b","c","d"],["f"],["f","h"],["f","h","i"],["f","j"],["g"],["g","j"],["g","h"],["g","h","i"]]