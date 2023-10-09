#include <iostream>
#include <cstring>
using namespace std;

//LinkedList Node
template <typename T>
class Node{
        public:
                //�����͸� ������ ����
                T data;
                //��屸��ü �̿�; ��������� �ּҸ� ������ ������
                Node *link;

                Node(T element){
                  data = element;
                  link = 0;
                }
        };

//LinkedList Class
template <typename T>
class LinkedList{
        protected:
                //ù��° ����� �ּҸ� ������ ������
                Node<T> *first;
                int current_size;
        public:
                //������, �ʱ�ȭ
                LinkedList(){
                        first = 0;
                        current_size = 0;
                };

                //��� ������ ����
                int GetSize(){
                        return current_size;
                };

                //�� �տ� ���Ҹ� ����, LinkedList�� Stack �Ѵ� ����
                void Insert(T element);

                //�� ���� ���Ҹ� ����, ���� ���߿� ���� ���� ����  - LinkedList
                virtual bool Delete(T &element);

                //����Ʈ ���
                void Print();
};



//�� ��带 �� �տ� ���̰� ���� ����
template <typename T>
void LinkedList<T>::Insert(T element){
        //��� ����
        Node<T> *newnode = new Node<T>(element);

        //�� ��尡 ù��° ��带 ����Ŵ
        //newnode�� �������̱� ������ -> �� ����� �Լ�, ������ �ҷ��� newnode.link�� ���� ����
        newnode -> link = first;
        first = newnode;
        current_size++;
};

//������ ����� ���� �����ϸ鼭 �޸𸮿��� �Ҵ� ����
template <typename T>
bool LinkedList<T>::Delete(T &element){

        if (first == 0)
                return false;

        Node<T> *current = first;
        Node<T> *previous = 0;

        //������ ������ ã�ư��� �ݺ���
        while(1){
                if (current->link == 0){  //������ ��带 ã�°�
                        if (previous)
                                previous -> link = current -> link;
                        else
                                first = first -> link;
                        break;
                }
                previous = current;
                current = current -> link;
        }
        element = current -> data;
        delete current;
        current_size--;

        return true;
};


//����Ʈ�� ����ϴ� Print �Լ�
template <typename T>
void LinkedList<T>::Print(){
        Node<T> *i;
        int index = 1;

        if (current_size != 0){
                for( i = first; i != NULL; i=i->link){
                        if (index == current_size){
                                cout << "[" << index << "|";
                                cout << i -> data <<"]";
                        }

                        else {
                                cout << "[" << index << "|";
                                cout << i -> data << "]->";
                                index++;
                        }
                }
                cout << endl;
        }

}

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


int main()
{
	double dVal;
	string strVal;
	LinkedList<double> dList;
	LinkedList<string> strList;
	dList.Insert(3.14);
	dList.Insert(123456);
	dList.Insert(-0.987654);
	dList.Print();
	dList.Delete(dVal);
	cout<<"������ ������ ����: "<<dVal<<endl;
	dList.Print();
	dList.Insert(777.777);
	dList.Print();
	dList.Delete(dVal);
	cout<<"������ ������ ����: "<<dVal<<endl;
	dList.Delete(dVal);
	cout<<"������ ������ ����: "<<dVal<<endl;
	dList.Print();
	dList.Delete(dVal);
	cout<<"������ ������ ����: "<<dVal<<endl;
	dList.Print();
	strList.Insert("This");
	strList.Insert("is a");
	strList.Insert("Template");
	strList.Insert("Example");
	strList.Print();
	strList.Delete(strVal);
	cout<<"������ ������ ����: "<<strVal<<endl;
	strList.Insert("Class");
	strList.Print();
	return 0;
}

