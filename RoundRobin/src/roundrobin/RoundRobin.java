package roundrobin;

import java.util.Scanner;

public class RoundRobin {
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        
        System.out.println("Enter Total Number Of process : ");
        
        int n,q,flag=0;
         n = scan.nextInt();
        
         int[] bt = new int[n];
         int[] wt = new int[n];
         int[] tat = new int[n];
         int[] rem = new int[n]; 
         
         System.out.println("Enter Burst Time : ");
         for(int i = 0 ; i<n ;i++){
             bt[i]=rem[i]=scan.nextInt();
         }
         
         System.out.println("Enter Quntum Time : ");
         q = scan.nextInt();
         
         do{
        flag = 0;
        for(int i = 0 ; i<n ; i++){
            if(rem[i]>=q){
                System.out.println("P"+(i+1)+"\t");
                for(int j = 0 ; j<n ; j++){
                    if(j == i)
                        rem[i] = rem[i]-q;
                    else if(rem[j]>0)
                        wt[j] +=q;
                }
            }
            else if(rem[i]>0){
                System.out.println("P"+(i+1)+"\t");
            for(int j = 0 ; j<n ; j++){
                if(j == i )
                    rem[i] = 0;
                else if(rem[j] > 0)
                    wt[j] +=rem[i]; 
                
            }
            
            
            }
        }
        for(int i = 0 ;i<n ;i++)
            if(rem[i]>0)
                flag = 1;
        
    }
         while (flag == 1); 
         for(int i = 0 ; i<n ; i++)
         tat[i] = wt[i] + bt[i];
         
         double b = 0 , t = 0 ;
      System.out.println("\nProcess\tBurst\tWaiting\tTurnaround");
                        for(int i=0;i<n;i++)
                        {
                                    System.out.println("P"+(i+1)+"\t"+bt[i]+"\t"+wt[i]+"\t"+tat[i]);
                                    b+=wt[i];
                                    t+=tat[i];
                        }
                        System.out.println("Average waiting time:"+(b/n));
                        System.out.println("Average Turnaround time:"+(t/n));
    }
    
}
