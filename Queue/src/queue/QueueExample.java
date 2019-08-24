package queue;

import java.util.LinkedList;
import java.util.Queue;

/**
 *
 * @author fesabelilla
 */
public class QueueExample {
    public static void main(String[] args) {
      Queue<Integer> q = new LinkedList<>();  
      
      //add element in the queue
      for(int i = 0 ; i <5 ; i++)
          q.add(i);
      
      //display contents ot the queue
        System.out.println("Elements of queue : "+q);
        
      //remove head of the queue 
      int remove = q.remove();
        System.out.println("remove element : "+remove);
        
        System.out.println(q);
        
       //to view the head of the queue 
       int head = q.peek();
        System.out.println("Head of the queue :  "+head);
        
        //poll() = This method removes and returns the head of the queue.
        
        int pollElement = q.poll();
        System.out.println("Remove the first element : "+pollElement);
        System.out.println(q);
        
        //size 
        System.out.println("Queue Size : "+q.size());
        
      
        
    }
    
}
