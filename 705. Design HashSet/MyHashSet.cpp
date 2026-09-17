class MyHashSet {
     vector<int> data;
public:

    MyHashSet() {
       
    }
    
    void add(int key) {
        auto it=find(data.begin(),data.end(),key);
        if(it!=data.end()){
            return;
        }
        else{
            data.push_back(key);
        }
        
    }
    
    void remove(int key) {
        auto it=find(data.begin(),data.end(),key);
        if(it!=data.end()){
        data.erase(it);
        }
        return;
    }
    
    bool contains(int key) {
        auto n=find(data.begin(),data.end(),key);
        if(n!=data.end())
        {
            return true;
        }

        return false;
    }
};
