
package multithreaddemo;

public class MultiThreadDemo {
    public static void main(String[] args) {
        
        NewThread newThread = new NewThread("One");
        newThread = new NewThread("Two");
        newThread = new NewThread("Three");
        
        try {
            //wait for other threads to end
            Thread.sleep(10000);
            
        } catch (Exception e) {
            System.out.println("Main Thread Inturrupted ");
        }
        
        System.out.println("Main thread existing .");
    }
    
}
