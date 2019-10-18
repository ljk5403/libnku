#ifndef LINEARQUEUE
#define LINEARQUEUE
template<class T>
class LinearQueue
{
public:
  LinearQueue(int LQMaxSize);     //创建空队列
  ~LinearQueue();//删除队列
  bool IsEmpty();
  //判断队列是否为空，空返回true，非空返回false
  bool IsFull();
  //判断队列是否为满，满返回true，不满返回false
  bool Insert(const T& x);    //入队，在队列尾部插入元素x
  bool GetElement(T& x);      //求队头元素的值放入x中
  bool Delete(T& x);
  //出队，从队头删除一个元素，并将该元素的值放入x中
  void OutPut(ostream& out) const;
  //输出队列
private:
  int size;   //队列实际元素个数
  int MaxSize;  //队列中最大元素个数
  int front, rear;  //队列的队头和队尾指针
  T *element; //一维动态数组
};
//实现构造函数
template<class T>
LinearQueue<T>::LinearQueue(int LQMaxSize)
{
  MaxSize = LQMaxSize;
  element = new T[MaxSize];
  size = 0;
  front = 0;
  rear = 0;
}
//实现析构函数
template<class T>
LinearQueue<T>::~LinearQueue()
{
  delete []element;
}
//实现判断栈是否为空
template<class T>
bool LinearQueue<T>::IsEmpty()
{
  return size == 0;
}
//实现判断栈是否为满
template<class T>
bool LinearQueue<T>::IsFull()
{
  return size == MaxSize;
}
//实现入队
template<class T>
bool LinearQueue<T>::Insert(const T& x)
{
  if (IsFull())
    return false;
  else
  {
    element[rear] = x;
    rear = (rear + 1) % (MaxSize);
    size++;
    return true;
  }
}
//实行求队头元素
template<class T>
bool LinearQueue<T>::GetElement(T& x)
{
  if (IsEmpty())
    return false;
  else
  {
    x = element[front];
    return true;
  }
}
//实现出队
template<class T>
bool LinearQueue<T>::Delete(T& x)
{
  if (IsEmpty())
    return false;
  else
  {
    x = element[front];
    front = (front + 1) % (MaxSize);
    size--;
    return true;
  }
}
//实现顺序队列的输出
template<class T>
void LinearQueue<T>::OutPut(ostream& out) const
{
  int index;
  index = front;
  for (int i = 0; i < size; i++)
  {
    out << element[index] << endl;
    index = (index + 1) % MaxSize;
  }
}
//重载插入运算符<<
template<class T>
ostream& operator<<(ostream& out, const LinearQueue<T>& x)
{
  x.OutPut(out);
  return out;
}
#endif
