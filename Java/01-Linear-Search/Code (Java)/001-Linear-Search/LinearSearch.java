public class LinearSearch {

    private LinearSearch(){}

    public static int search (int[] arr, int target) {

        for(int i = 0; i < arr.length; i++) {
            if(arr[i] == target)
                return i;
        }

        return -1;
    }

    public static void main(String[] args) {

        int[] data = {24, 18, 12, 9, 16, 66, 32, 4};

        int res = LinearSearch.search(data, 4);
        System.out.println("res = " + res);

        int res2 = LinearSearch.search(data, 222);
        System.out.println("res2 = " + res2);
    }
}
