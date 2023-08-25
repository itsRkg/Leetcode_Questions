


typedef struct {
    int *arr;
    int front;
    int back;
    int size;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *queue;
    queue=malloc(sizeof(MyCircularQueue));
    (*queue).arr=malloc(sizeof(int)*k);
    (*queue).front=-1;
    (*queue).back=-1;
    (*queue).size=k;
    return queue;
}



bool myCircularQueueDeQueue(MyCircularQueue* obj) {
  int f=(*obj).front,r=(*obj).back,s=(*obj).size;
  if(f==-1 || f>r)
      return false;
  (*obj).front++;
    return true;    
}

int myCircularQueueFront(MyCircularQueue* obj) {
  int f=(*obj).front,r=(*obj).back,s=(*obj).size;
  if(f==-1 || f>r)
      return -1;
   return (*obj).arr[f%s];
}



bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
  int f=(*obj).front,r=(*obj).back,s=(*obj).size;
  if(f==-1 || f>r)
      return true;
  return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
  int f=(*obj).front,r=(*obj).back,s=(*obj).size;
  if(r-f+1 >=s)
      return true;
    return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free((*obj).arr);
    free(obj);
}

int myCircularQueueRear(MyCircularQueue* obj) {
  int f=(*obj).front,r=(*obj).back,s=(*obj).size;
  if( myCircularQueueIsEmpty(obj)) return -1; 

  return (*obj).arr[r%s];
}
 bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    int f=(*obj).front,r=(*obj).back;
 if(  myCircularQueueIsFull(obj) && r!=-1) return false; 
  if(r==-1)
  {
      ((*obj).front)++;
  }
    
      ((*obj).back)++;
      (*obj).arr[(*obj).back %(*obj).size]=value;
 
    return true;
}