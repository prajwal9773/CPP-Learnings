#include<iostream>
using namespace std;



class Heap{
    public:
    int *arr;
    int capacity;
    int size;

    Heap(int val){
        this->size = 0;
        this->capacity = val;
        arr = new int[val];
    }

    void insert(int data){
        //overflow
        if(size == capacity){
            cout<<"size is full"<<endl;
        }

        else{
            size++;
            int index = size;
            arr[index] = data;

            // ab heapify karlo 
            while(index>1){
                int parent = index/2;
                if(arr[index] > arr[parent]){
                    swap(arr[index], arr[parent]);
                    index = parent;
                }
                else{
                    break;
                }

            }


        }

    }

    void print(){
        for(int i=0;i<=size;i++){
            cout<<arr[i]<<" ";

        }
    }

    int deleteFromHeap(){
        int ans = arr[1];
        arr[1] = arr[size];
        size--;

        //hepify
        int index = 1;
        while(index<size){
            int leftIndex = 2* index;
            int rightIndex = 2* index +1;
            int largest = index;
            if(leftIndex<=size && arr[leftIndex] > arr[largest]){
                largest = leftIndex;
            }
            if(rightIndex<=size && arr[rightIndex] > arr[largest]){
                largest = rightIndex;
            }
            if(index == largest) {
            break;
          }

          else{
            swap(arr[index], arr[largest]);
            index = largest;
          }




        }


        return ans;

    }
};


void heapify(int *arr, int n, int index){
           int leftIndex = 2* index;
            int rightIndex = 2* index +1;
            int largest = index;
            if(leftIndex<=n && arr[leftIndex] > arr[largest]){
                largest = leftIndex;
            }
            if(rightIndex<=n && arr[rightIndex] > arr[largest]){
                largest = rightIndex;
            }
            if(index!=largest) {
                 swap(arr[index], arr[largest]);
                index = largest;
                heapify(arr, n, index);
           
          }

          

}


void heapSort(int arr[], int n){
   while(n!=1){
    swap(arr[1], arr[n]);
    n--;
    heapify(arr, n, 1);
   }
    
}

void buildHeap(int arr[], int n) {
  for(int index = n/2; index>0; index--) {
    heapify(arr, n, index);
  }
}

int main() {
  int arr[] = {-1,5,10,15,20,25,12};
  int n = 6;
  buildHeap(arr,6);
  for(int i=1; i<=6; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  
  cout << "printing heap: " << endl;
   heapSort(arr, n);
  for(int i=1; i<=6; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

 


//   Heap h(20);
//   //insertion
//   h.insert(10);
//   h.insert(20);
//   h.insert(5);
//   h.insert(11);
//   h.insert(6);

//   cout << "Printing the content of heap: " << endl;
//   h.print();
//   int ans = h.deleteFromHeap();
//   cout << "Answer: " << ans << endl;
//   cout << "Printing the content of heap: " << endl;


//   h.print();



  return 0;
}