import java.util.*;
class test{
 boolean val;
 test(boolean b){
  this.val = b;
 }
synchronized void call(){
 if(this.val == true){
   System.out.println("Your call is on wait!!");
   try{
     wait();
   }
   catch(InterruptedException e){}
 }
 System.out.println("Your call is accepted");
}

synchronized void hold(){
 if(this.val == false){
   System.out.println("Hold is released");
    notify();
 } 
 else{
  try{
  Thread.sleep(10000);
  this.val = isend();
  hold();
  }
  catch(InterruptedException e){}
 }
}
public boolean isend(){
 Scanner sc = new Scanner(System.in);
 System.out.print("Are you still buzy(0/1): ");
 int res = sc.nextInt();
 if(res == 1)
   return true;
 else
   return false;
}
}
public class call{
 public static void main(String args[]){
   test t1 = new test(true);
   test t2 = new test(false);
new Thread(){
 public void run(){
   t1.call();
   t2.call();
 }
}.start();
new Thread(){
 public void run(){
   t1.hold();
   t2.hold();
 }
}.start();
}
}
   