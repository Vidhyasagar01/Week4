#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
struct control {    
    int id;              
    string type;    
    string state;
 
bool operator ==(const control& other)const{
    return id==other.id;
}
 
bool operator ==(const string& state_val) const {
        return state == state_val;
    }
};
 
int main(){
    vector<control> v1;
    v1.push_back({1,"Button","Visible"});
    v1.push_back({2,"Button","Invisible"});
    v1.push_back({3,"Slider","Visible"});
    v1.push_back({4,"Slider","Invisible"});
    v1.push_back({5,"Button","Visible"});
    v1.push_back({6,"Button","Visible"});
    v1.push_back({7,"Button","Invisible"});
    v1.push_back({8,"Slider","Visible"});
    v1.push_back({9,"Slider","Invisible"});
    v1.push_back({10,"Button","Visible"});
    // Print all controls
    for_each(v1.begin(),v1.end(),[](control x){
        cout<<x.id<<" "<< x.type<<" "<<x.state<<endl;
    });
    
    // Find a specific control by id
    control target={4,"",""};
    auto it=find(v1.begin(),v1.end(),target);
     cout<<it-v1.begin()+1<<endl;
     
     // Find first control with an even id
     auto it1=find_if(v1.begin(),v1.end(),[](control x){
         return x.id%2==0;
     });
     
     // Find first adjacent controls with the same state
     cout<<it1-v1.begin()+1<<endl;
     auto it2=adjacent_find(v1.begin(),v1.end(),[](control x,control y){
         return x.state==y.state;
     });
     cout<<it2->id<<endl;
     
     // Count controls with state "Visible"
     auto it3=count(v1.begin(),v1.end(),"Visible");
     cout<<it3<<endl;
     
    // Count controls with even ids
     auto it4=count_if(v1.begin(),v1.end(),[](control x){
         return x.id%2==0;
     });
     cout<<it4<<endl;
    // Check if the first half equals the second half based on state and type
       bool eql = equal(v1.begin(), v1.end()-5, v1.begin() + 5, v1.end(), []( control a,  control b) {
        return a.state == b.state && a.type == b.type;  
    });
    cout << boolalpha<< eql << endl;
    return 0;
}