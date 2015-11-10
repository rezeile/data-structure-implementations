// stack.h: header file
/* class definition */
template< class T>
class Stack {
   T items[100];
   int top;
public:
   Stack();
   // ~Stack();
   // void push(Typ);
   // Typ pop();
   // int empty();
   // int full();
};

/* class definiton */
Stack<T>::Stack() {
	top = -1;
}
