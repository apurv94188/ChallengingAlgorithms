/* Solution:
https://leetcode.com/problems/course-schedule-ii/
directed edge from a course to its pre-requiste course.
Use DFS:
Start from root (which is not a pre-requisite to any other course):
 mark the current node as VISITING.
 for each adjacent nodes (its pre-requiste courses):
    if status is VISITING:
        No answer - as it forms a looop (i.e. deadlock)
    if status is VISTIED:
        Course has already been completed. So safe and ignore
    if status is NOT_VISITED:
        run DFS on this sub-tree

*/
#define NOT_VISITED 0
#define VISITING 1
#define VISITED 2

class Node {
    public:
    int cn;
    int status = NOT_VISITED;
    vector<Node*> vec_next;
    Node (int num) : cn(num){}
};

class Solution {
public:
    
    // get the order of the courses for this sub-tree
    vector<int> get_course_order(Node* curr_course) {
        curr_course->status = VISITING;
        vector<int> next_courses = {};
        
        // loop over pre-requiste course of this course
        for (Node* next : curr_course->vec_next) {
            
            // already this coourse is in VISITING stage so deadlock
            if (next->status == VISITING){
                curr_course->status = NOT_VISITED;
                return {};
            }
            
            // already completed this sub-tree successffully - so safe to ignore
            if (next->status == VISITED)
                continue;
            
            // run DFS on this noon-visited sub-tree
            next->status = VISITING;
            vector<int> temp = get_course_order(next);
            
            // if no ordering can be done in the sub-tree - NO SOlution
            if (temp.size() == 0)
                return {};
            
            next_courses.insert(next_courses.end(), temp.begin(), temp.end());
        }
        
        // found an order
        next_courses.push_back(curr_course->cn);
        curr_course->status = VISITED;
        return next_courses;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> course_order;
        if (prerequisites.size()==0){
            for (int i=0; i<numCourses; ++i)
                course_order.push_back(i);
            return course_order;
        }
                
        
        set<int> totally_dependent; // list of courses which are not pre-requisite to any other course
        // totally_dependent ar the courses which act as root to each tree. We will use DFS to find
        
        vector<Node*> ref (numCourses, NULL);
        
        int pre; //pre_course
        int post; // post_course
        
        // create depedent course tree
        for (vector<int> prereq : prerequisites) {
            pre = prereq[1];
            post = prereq[0];
            
            // check if post courrse occured before
            if (ref[post] == NULL) { //No
                ref[post] = new Node(post);
                // it is potentially tottaly dependent course
                totally_dependent.insert(post);
            }
            
            if (ref[pre] == NULL)
                ref[pre] = new Node(pre);
            
            // if pre was previously said to be totally dependent then it is not now, so rmove it
            if (totally_dependent.find(pre) != totally_dependent.end())
                totally_dependent.erase(pre);
            
            ref[post]->vec_next.push_back(ref[pre]);
        }
        
        if (totally_dependent.size()==0)
            return {};
        
        for (int start_course : totally_dependent){
            
            // run DFS
            vector<int> order = get_course_order(ref[start_course]);
            
            // if no ordering can be done
            if (order.size()==0)
                return {};
            
            // found an order
            course_order.insert(course_order.end(), order.begin(), order.end());
            
        }
        
        for (int c=0; c<ref.size(); ++c){
            if (ref[c] == NULL) // single course - nor has a pre-requisite nor is a pre-requiste too any other
                course_order.push_back(c);
            else if (ref[c]->status != VISITED)
                return {};
        }
        
        return course_order;
    }
};
