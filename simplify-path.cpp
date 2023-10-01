//simplify path
//LC 71

/*Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

The canonical path should have the following format:

The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path does not end with a trailing '/'.
The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
Return the simplified canonical path.

*/



class Solution {
public:
   void buildAns(stack<string> &s, string &ans){
        if(s.empty()){
            return;
        }
        string minpath=s.top(); 
        s.pop();
        buildAns(s,ans);
        ans+=minpath;
    }
    string simplifyPath(string path) {
        stack<string> s;
        int i=0;
        while(i<path.size()){
            int start=i;
            int end=i+1;
            while(end<path.size() && path[end]!='/'){
                ++end;
            }
            string minpath=path.substr(start,end-start);
            i=end;
            if(minpath=="/" || minpath=="/."){
                continue;
            }
            if(minpath!="/.."){
                s.push(minpath);
            }
            else if(!s.empty()){
                s.pop();
            }
        }
        string ans=s.empty() ? "/" :"";
        buildAns(s,ans);
        return ans;
    }
};
