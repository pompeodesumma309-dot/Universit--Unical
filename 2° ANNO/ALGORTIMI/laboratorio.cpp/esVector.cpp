#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Insieme{
private:
    vector<T> elements;
public:
    template <typename T>
    Insieme(){}
    
    //add
    void Insieme<T>::add(const T& element){
        if (!is_in(element)) elements.push_back(element);
    }

    //remove
    template <typename T>
    void Insieme<T>::remove(const T& element){
        auto it = find(elements.begin(), elements.end(), element);
        if (it != elements.end()){
            elements.erase(it);
        }
    }

    //is_in
    template <typename T>
    bool Insieme<T>::is_in(const T& element) const{
        return find(elements.begin(), elements.end(), element) != elements.end();
    }

    //empty
    template <typename T>
    bool Insieme<T>::empty() const{
        return elements.size() == 0;
    }

    //unione
    template <typename T>
    Insieme<T> Insieme<T>::unionTo(const Insieme<T>& other) const{
        Insieme<T> newSet;
        for(unsigned i=0; i<elements.size(); i++){
            newSet.add(elements[i]);
        }
        for(unsigned i=0; i<other.elements.size(); i++){
            newSet.add(other.elements[i]);
        }
        return newSet;
    }
    
    //intersezione
    template <typename T>
    Insieme<T> Insieme<T>::intersect(const Insieme<T>& other) const{
        Insieme<T> newSet;
        for(unsigned i=0; i<elements.size(); i++){
            if(other.is_in(elements[i])) newSet.add(elements[i]);
        }
        
        return newSet;
    }
    

    //differenza
    template <typename T>
    Insieme<T> Insieme<T>::difference(const Insieme<T>& other) const{
        Insieme<T> newSet;
        for(unsigned i=0; i<elements.size(); i++){
            if(!other.is_in(elements[i])) newSet.add(elements[i]);
        }
        
        return newSet; 
    }
};

int main(){
return 0;
}