#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
using namespace std;
void RoadDictionary(string start, string end, set<string> dictionary){
    
    //tworzymy pusta kolejke zlozona ze stosu
    queue<stack<string>> QueueStack;
    //dodajemy pierwsze slowo do kolejki stosow
    stack<string> Stack;
    Stack.push(start);
    QueueStack.push(Stack);
    
    //przetestowane slowa
    set<string> usedWords;
    stack<string> endStack;
    string test;
	      //dopoki kolejka nie jest pusta
	      while (!QueueStack.empty()) {
                //zdejmujemy z kolejki pierwszy stos i wstawiamy do tymczasowego stosu
                endStack = QueueStack.front();
                QueueStack.pop();
                //bierzemy slowo ktore znajduje sie na poczatku stosu
                string word = endStack.top();
                    
                //jezeli slowo = slowu koncowemu to konczymy alg
                if(word == end) {
                cout << start << " -> " << end << ": \n";
                //Wypisujemy ścieżke słów
                while(!endStack.empty()){
                    cout<<endStack.top()<<" <- ";
                    endStack.pop();
                }
            } 
            else {
                //Sprawdzamy slowa sasiadujace (czyli takie ktore sa w tym samym stosie)
                for (int i = 0; i < word.size(); i++) {
                        for (char j = 'a'; j <= 'z'; j++) {
                            test = word.substr(0, i) + j + word.substr(i + 1);                  
                            //Sprawdzamy czy nowe slowo istnieje w slowniku
                            if (dictionary.find(test)!=dictionary.end()) {
                            
                            //Jeżeli istnieje i się nie powtarza to dodajemy stos do kolejki
                                if(!usedWords.count(test)) {
                                        //wykorzystujemy tymczasowy stos, aby dodac nowe slowo do nowego stosu kolejki
                                        stack<string> tmp = endStack;
                                        tmp.push(test);
                                        QueueStack.push(tmp);
                                }
                            }
                            //Nowe slowo dodajemy do slownika przebadanych slow
                            usedWords.insert(test);
                    }
                }
            }
        }
}
int main()
{

    set<string> D;
    string w;
    for(int i = 0; i<370103; i++){
        std::cin>>w;
        if(w.length()==4)
            D.insert(w);
    }
    RoadDictionary("cook", "door", D);
    
    return 0;
}


    
    
