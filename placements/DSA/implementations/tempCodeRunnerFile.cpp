MinHeap minheap(10);
   minheap.insertKey(4);
   minheap.insertKey(2);
   cout << minheap.extractMin() << "\n";
   minheap.insertKey(6);
   minheap.deleteKey(0);
   cout << minheap.extractMin() << "\n";
   cout << minheap.extractMin() << "\n";