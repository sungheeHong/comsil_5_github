#include "LinkedList.h"

template <typename T>
class Stack : public LinkedList<T>{
        public:
                bool Delete (T &element){
                        //first�� 0�̸� false��ȯ
                        if(this->first==0){
                        	return false;
						}
						
						// LinkedList�� �޸� Stack�� current�� ����Ű�� ���� ����
						Node<T> *current;
						current = this->first;
						this->first=current->link;
						element = current->data;
						delete current;
						this->current_size--;

                        return true;
                        }
};
