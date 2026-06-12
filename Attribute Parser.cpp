#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <stack>
#include <sstream>
using namespace std;

int main() {  
    int n, q;
    cin >> n >> q;
    cin.ignore();
    
    map<string, map<string, string>> attr_map;
    stack<string> tag_stack;
    string current_tag = "";
    
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        
        if (line[1] == '/') {
            tag_stack.pop();
            current_tag = "";
            stack<string> temp = tag_stack;
            vector<string> parts;
            while (!temp.empty()) {
                parts.push_back(temp.top());
                temp.pop();
            }
            for (int j = parts.size() - 1; j >= 0; j--) {
                if (current_tag.empty()) current_tag = parts[j];
                else current_tag += "." + parts[j];
            }
        } 
        else {
            line = line.substr(1, line.length() - 2);
            stringstream ss(line);
            string tag_name;
            ss >> tag_name;
            
            string new_tag = current_tag.empty() ? tag_name : current_tag + "." + tag_name;
            tag_stack.push(tag_name);
            current_tag = new_tag;
            
            string att, eq, val;
            while (ss >> att) {
                ss >> eq >> val;
                val = val.substr(1, val.length() - 2); 
                attr_map[new_tag][att] = val;
            }
        }
    }
    for (int i = 0; i < q; i++) {
        string query;
        getline(cin, query);
        
        size_t tilde = query.find('~');
        string tag_path = query.substr(0, tilde);
        string attribute = query.substr(tilde + 1);
        
        if (attr_map.find(tag_path) != attr_map.end() &&
            attr_map[tag_path].find(attribute) != attr_map[tag_path].end()) {
            cout << attr_map[tag_path][attribute] << endl;
        } else {
            cout << "Not Found!" << endl;
        }
    }
    
    return 0;
}
