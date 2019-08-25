
package producerconsumer;

//blockingQueue - thread safe data structure
//“poison pill” is a general solution to stop or interrupt both producer and consumer threads
//All methods of BlockingQueue are atomic in nature and use internal locks 
//BlockingQueue does not accept null value

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;


/**
 *
 * @author fesabelilla
 */
public class ProducerConsumer {

    public static void main(String[] args) {
        BlockingQueue<Integer> queue = new  LinkedBlockingQueue<>(10);
        
        Integer poison = -1;
        
        new Thread(new Producer(queue,poison)).start();
        new Thread(new Consumer(queue,poison)).start();
        
        
        
    }
    
}
