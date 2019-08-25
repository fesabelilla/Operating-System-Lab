package producerconsumer;

import java.util.concurrent.BlockingQueue;

public class Producer implements Runnable{

    private  final  BlockingQueue<Integer> queue;
     private final Integer POISON;
    
    @Override
    public void run() {
    
        try {
            Process();
        } 
        catch (InterruptedException e) {
        Thread.currentThread().interrupt();
        }finally{
            while(true){
                try{
                    queue.put(POISON);
                    break;
                }catch(InterruptedException e){
                    
                }
            }
            
            
        }
    
    }

    private void Process() throws InterruptedException{
      
        //put 20 intger values in the Queue
        for(int i = 0 ; i<20 ; i++){
           System.out.println("[Producer] put : "+i);
           queue.put(i);
           System.out.println("[Producer] Queue remainingCapacity : " + queue.remainingCapacity());
           Thread.sleep(100);
       }
        
    }

    public Producer(BlockingQueue<Integer> queue,Integer POISON){
        this.queue = queue;
        this.POISON = POISON;
    }
}
