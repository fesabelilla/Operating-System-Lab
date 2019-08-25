package producerconsumer;

import java.util.concurrent.BlockingQueue;

public class Consumer implements Runnable{

    private final BlockingQueue<Integer> queue;
     private final Integer POISON;

    @Override
    public void run() {
    
        try {
           while(true){
               Integer take = queue.take();
               Process(take);
               
               // if this is a poison pill, break, exit
                if (take == POISON) {
                    break;
                }
           } 
        } catch (InterruptedException e) {
        Thread.currentThread().interrupt();
        }
    
    }
    
    private void Process(Integer take ) throws InterruptedException{
        System.out.println("[Consumer] Take : "+ take);
        Thread.sleep(500);
    }
        
    public Consumer(BlockingQueue<Integer> queue , Integer POISON){
        this.queue = queue;
        this.POISON = POISON;
    }
    
}
