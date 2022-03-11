import javax.sound.sampled.Line;

public class LinearSearch {

    private LinearSearch(){}

    public static <E> int search (E[] arr, E target) {

        for(int i = 0; i < arr.length; i++) {
            if(arr[i].equals(target))
                return i;
        }

        return -1;
    }

    public static void main(String[] args) {
        int[] dataSize = {1000000, 10000000, 100000000};
        for (int n: dataSize) {
            Integer[] arr = ArrayGenerator.generateOrderedArray(n);
            long startTime = System.nanoTime();
            for (int i = 0; i < 100; i++) {
                LinearSearch.search(arr, n);
            }
            long endTime = System.nanoTime();
            double time = (endTime - startTime) / 1000000000.0;
            System.out.println("n = " + n + ", 100 runs, time = " + time + "s");
        }
    }
}