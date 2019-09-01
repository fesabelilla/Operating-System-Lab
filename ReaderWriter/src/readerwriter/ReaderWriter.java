package readerwriter;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;
import java.util.concurrent.Semaphore;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author fesabelilla
 */
public class ReaderWriter {

    static Semaphore readLock = new Semaphore(1);
    static Semaphore writeLock = new Semaphore(1);
    static int readCount = 0;
    static int n = 5;
    //static int[] store = new int[]{1, 2, 3, 4, 5, 6};
    public static ArrayList<Integer> arr = new ArrayList<>();
    Queue<Integer> q = new LinkedList<Integer>();

    static class Read implements Runnable {

        @Override
        public void run() {
            try {
                readLock.acquire();
                readCount++;
                if (readCount == 1) {
                    writeLock.acquire();
                }
                readLock.release();

                //System.out.println("Thread "+Thread.currentThread().getName() +" is reading");
                //for(int i = 0 ; i < store.length ; i++){
                 int a = arr.size();

                int i = returnInt()%a;
                System.out.println("Thread " + Thread.currentThread().getName() + " is reading  " + i);
                 //}

                //Thread.sleep(1000);
                System.out.println("Thread " + Thread.currentThread().getName() + " finished reading");

                readLock.acquire();
                readCount--;
                if (readCount == 0) {
                    writeLock.release();
                }
                readLock.release();

            } catch (InterruptedException ex) {
                Logger.getLogger(ReaderWriter.class.getName()).log(Level.SEVERE, null, ex);
            }

        }

        static public int returnInt() {
            return new Random().nextInt(5);
        }
    }

    static class Write implements Runnable {

        @Override
        public void run() {
            try {
                writeLock.acquire();
                // System.out.println("Thread "+Thread.currentThread().getName() +" is writing");
               
                //store[a] = returnInt();
                
                for(int i = 0 ; i < 3 ; i++){
                    int a = arr.get(i);
                    arr.add(a);
                }
                
                arr.add(returnInt());
                System.out.println("Thread " + Thread.currentThread().getName() + " is writing" );
                for(int i : arr){
                    System.out.print(" "+ i);
                }
                System.out.println("");

                // Thread.sleep(1500);
                System.out.println("Thread " + Thread.currentThread().getName() + " has finishing writing .");

                writeLock.release();

            } catch (InterruptedException ex) {
                Logger.getLogger(ReaderWriter.class.getName()).log(Level.SEVERE, null, ex);
            }

        }

        static public int returnInt() {
            return new Random().nextInt(100);
        }

    }

    public static void main(String[] args) {

        Read read = new Read();
        Write write = new Write();

        Thread t1 = new Thread(read);
        t1.setName("Reader1");

        Thread t2 = new Thread(read);
        t2.setName("Reader2");

        Thread t3 = new Thread(write);
        t3.setName("Writer1");

        Thread t4 = new Thread(write);
        t4.setName("Writer2");

        
        arr.add(returnInt());
        arr.add(returnInt());
        arr.add(returnInt());
        arr.add(returnInt());
        
        t1.start();
        t2.start();
        t3.start();
        t4.start();

    }

    static public int returnInt() {
        return new Random().nextInt(5);
    }
    

}
