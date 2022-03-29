public class Main {
    public static void main(String[] args) {
        Array<Integer> arr = new Array<Integer>(10);
        System.out.println(arr);
        for (int i = 0; i < 10; i++)
            arr.addLast(i+1);
        System.out.println(arr);
        arr.addFirst(99);
        arr.addLast(100);
        arr.add(2,88);
        System.out.println(arr);
        arr.remove(2);
        System.out.println(arr);
        arr.removeElement(5);
        System.out.println(arr);
        System.out.println(arr.getCapacity());
        arr.remove(10);
        System.out.println(arr);
    }
}