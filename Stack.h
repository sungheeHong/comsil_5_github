#include "LinkedList.h"

template <typename T>
class Stack : public LinkedList<T>{
        public:
                bool Delete (T &element){
                        //first가 0이면 false반환
                        if(this->first==0){
                        	return false;
						}
						
						// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
						Node<T> *current;
						current = this->first;
						this->first=current->link;
						element = current->data;
						delete current;
						this->current_size--;

                        return true;
                        }
};
