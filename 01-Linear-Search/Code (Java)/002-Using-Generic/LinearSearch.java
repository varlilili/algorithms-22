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

        Integer[] data = {24, 18, 12, 9, 16, 66, 32, 4};

        int res = LinearSearch.<Integer>search(data, 4);
        System.out.println("res = " + res);

        int res2 = LinearSearch.<Integer>search(data, 222);
        System.out.println("res2 = " + res2);
    }
}
