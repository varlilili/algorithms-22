import java.util.Random;

public class Main {

    /**
     * 测试使用 q 运行 opCount 个 enqueue 和 dequeue 操作所需要的时间
     * @param q 传入的队列
     * @param opCount 操作次数
     * @return 所需要的时间（单位：秒）
     */
    private static double testQueue(Queue<Integer> q, int opCount){

        long startTime = System.nanoTime();
        Random random = new Random();
        for (int i = 0; i < opCount; i++)
            q.enqueue(random.nextInt(Integer.MAX_VALUE));
        for (int i = 0; i < opCount; i++)
            q.dequeue();
        long endTime = System.nanoTime();

        return (endTime - startTime) / 1000000000.0;
    }

    public static void main(String[] args) {

        int opCount = 1000000;

        LoopQueue<Integer> loopqueue = new LoopQueue<>();
        double time2 = testQueue(loopqueue, opCount);
        System.out.println("LoopQueue, Time = " + time2 + "s");

        ArrayQueue<Integer> arrayqueue = new ArrayQueue<>();
        double time1 = testQueue(arrayqueue, opCount);
        System.out.println("ArrayQueue, Time = " + time1 + "s");
    }
}
