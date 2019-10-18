#include<iostream>
using namespace std;

template<class Type>
struct heap {
	Type *S;  //保存节点数组
	int heapsize;
};

//把下标为index的节点下移
template<class Type>
void siftDown(heap<Type> &H, int index) {
	int parent, largest;
	Type siftkey;
	bool done;

	siftkey = H.S[index];
	parent = index;
	done = false;

	while ((2* parent <= H.heapsize) && !done) {
		if ((2* parent < H.heapsize) && (H.S[2* parent ] < H.S[2* parent + 1])) {
			largest = 2 * parent + 1;
		} else {
			largest = 2 * parent;
		}

		if (siftkey < H.S[largest]) {
			H.S[parent] = H.S[largest];
			parent = largest;
		} else {
			done = true;
		}

		H.S[parent] = siftkey;
	}
}

//把下标为index的节点上移
template<class Type>
void siftUp(heap<Type> &H, int index) {
	bool done = false;
	if (index != 1) {
		while (!done && index != 1) {
			if (H.S[index / 2] < H.S[index]) {
				H.S[0] = H.S[index];
				H.S[index] = H.S[index / 2];
				H.S[index / 2] = H.S[0];
			}else{
				done = true;
			}
			index = index / 2;
		}
	}
}

//删除并返回堆的根元素
template<class Type>
Type removeRoot(heap<Type> &H) {
	Type outkey;

	outkey = H.S[1];
	H.S[1] = H.S[H.heapsize];
	H.heapsize--;
	siftDown(H, 1);
	return outkey;
}

//把A放入堆中
template<class Type>
void insert(heap<Type> &H, Type A) {
	H.heapsize++;
	H.S[H.heapsize] = A;
	siftUp(H, H.heapsize);
}

//创建堆
template<class Type>
void createHeap(int n, heap<Type> &H) {
	H.heapsize = n;
	for (int i = n / 2; i >= 1; i--) {
		siftDown(H, i);
	}
}
