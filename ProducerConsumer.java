import java.util.LinkedList;
import java.util.Queue;
import java.util.concurrent.Semaphore;

class ProducerConsumer{
private static final int BUFFER_SIZE = 5;
  private final Queue<Integer>buffer = new LinkedList<>();
  private final Semaphore empty = new Semaphore(BUFFER_SIZE);
  private final Semaphore full = new Semaphore(0);
  private final Object lock = new Object();


  public void produce(int item) throws InterruptedException
  {
          empty.acquire();

          synchronized(lock){
                 buffer.add(item);
                 System.out.println("Producer Produced : "+ item);
          }

          full.release();
  }

  public void consume() throws InterruptedException
  {
          full.acquire();
int item;
          synchronized(lock){
                 item = buffer.remove();
                 System.out.println("Consumer Consumed : "+ item);
          }

          empty.release();
  } 



    public static void main(String []args)
    {

            ProducerConsumer s = new ProducerConsumer();

             Thread ProducerThread = new Thread(()->{
             
                    try{
                        for(int i =0;i<20;i++){
                            s.produce(i);
                            Thread.sleep(500);
                        }

                    }
                    catch(InterruptedException e){
                        Thread.currentThread().interrupt();
                    }

             });

               Thread ConsumerThread = new Thread(()->{
             
                    try{
                        for(int i =0;i<20;i++){
                            s.consume();
                            Thread.sleep(1000);
                        }

                    }
                    catch(InterruptedException e){
                        Thread.currentThread().interrupt();
                    }

             });

            ProducerThread.start();
            ConsumerThread.start();

            try{
                ProducerThread.join();
                ConsumerThread.join();
            }
            catch(InterruptedException e)
            {
                 Thread.currentThread().interrupt();
            }
    }
}

