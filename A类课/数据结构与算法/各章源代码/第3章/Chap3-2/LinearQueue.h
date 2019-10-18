#ifndef LINEARQUEUE
#define LINEARQUEUE
template<class T>
class LinearQueue
{
public:
  LinearQueue(int LQMaxSize);     //�����ն���
  ~LinearQueue();//ɾ������
  bool IsEmpty();
  //�ж϶����Ƿ�Ϊ�գ��շ���true���ǿշ���false
  bool IsFull();
  //�ж϶����Ƿ�Ϊ����������true����������false
  bool Insert(const T& x);    //��ӣ��ڶ���β������Ԫ��x
  bool GetElement(T& x);      //���ͷԪ�ص�ֵ����x��
  bool Delete(T& x);
  //���ӣ��Ӷ�ͷɾ��һ��Ԫ�أ�������Ԫ�ص�ֵ����x��
  void OutPut(ostream& out) const;
  //�������
private:
  int size;   //����ʵ��Ԫ�ظ���
  int MaxSize;  //���������Ԫ�ظ���
  int front, rear;  //���еĶ�ͷ�Ͷ�βָ��
  T *element; //һά��̬����
};
//ʵ�ֹ��캯��
template<class T>
LinearQueue<T>::LinearQueue(int LQMaxSize)
{
  MaxSize = LQMaxSize;
  element = new T[MaxSize];
  size = 0;
  front = 0;
  rear = 0;
}
//ʵ����������
template<class T>
LinearQueue<T>::~LinearQueue()
{
  delete []element;
}
//ʵ���ж�ջ�Ƿ�Ϊ��
template<class T>
bool LinearQueue<T>::IsEmpty()
{
  return size == 0;
}
//ʵ���ж�ջ�Ƿ�Ϊ��
template<class T>
bool LinearQueue<T>::IsFull()
{
  return size == MaxSize;
}
//ʵ�����
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
//ʵ�����ͷԪ��
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
//ʵ�ֳ���
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
//ʵ��˳����е����
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
//���ز��������<<
template<class T>
ostream& operator<<(ostream& out, const LinearQueue<T>& x)
{
  x.OutPut(out);
  return out;
}
#endif
