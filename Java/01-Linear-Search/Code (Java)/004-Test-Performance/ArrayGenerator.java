public class ArrayGenerator {

    private ArrayGenerator() {}

    public static Integer[] generateOrderedArray(int n) {
        Integer[] array = new Integer[n];
        for(int i = 0; i < n; i++)
            array[i] = i+1;
        return array;
    }
}
