package multithreaddemo;

/**
 *
 * @author Fesabelilla
 */
public class NewThread implements Runnable{

    String name ;
    Thread t;

    public NewThread(String threadName) {
    name = threadName;
    t = new Thread(this, name);
    System.out.println("New thread : "+ t);
    t.start(); // start thread
        
    }
     
    @Override
    public void run( ) {
   
        try {
            for(int i = 5 ; i>0 ; i-- ){
                System.out.println(name + " : "+i);
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
             System.out.println(name + " Inturrept !!!!");
             
        }
        
        System.out.println(name + " exiting.");
        
    }
    
}
