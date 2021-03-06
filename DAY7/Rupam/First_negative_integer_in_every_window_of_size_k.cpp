vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
              
               int i=0,j=0;
               vector<long long >ans;
               queue<long long>q;
               while(j<N){
                // if any number is negetive , push it into queue
                    if(A[j]<0){
                       q.push(A[j]);
                    }
                // creating the window
                  if(j-i+1<K){
                      j++;
                  }
                // now checking in the window 
                  else if(j-i+1 ==K){
                     // if the queue is empty that's mean there is no negetive element
                     if(q.empty()){
                       ans.push_back(0); 
                     }
                   
                   else{
                         // push the front negetive element into the answer
                         ans.push_back(q.front());
                     }
                     // if first element of the window == queue's top element
                     if(A[i]==q.front())
                     {q.pop();} // pop the front 
                     // maintainng the window
                     i++;
                     j++;
                      
                  }
          }
    return ans;
 }
